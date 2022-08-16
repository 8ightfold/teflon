#ifndef TEFLON_UTIL_TIMER_HPP
#define TEFLON_UTIL_TIMER_HPP

#include <chrono>
#include <optional>
#include <teflon/util/units.hpp>

namespace teflon::util
{
    class timer
    {
        using steady_clock_t = std::chrono::high_resolution_clock;
        using time_point_t = steady_clock_t::time_point;
        using time_t = typename decltype(time::s::value);
    public:
        timer() : m_start(steady_clock_t::now()) {}

        inline void start()
        {
            this->m_is_running = true;
            this->m_has_started = true;
            this->m_start = steady_clock_t::now();
        }

        inline void stop()
        {
            this->m_end = steady_clock_t::now();
            this->m_is_running = false;
            this->m_has_ended = true;
        }

        inline void restart()
        {
            this->m_is_running = true;
            this->m_has_started = true;
            this->m_start = steady_clock_t::now();
        }

        // Fast time functions

        template <teflon::unit::is_unit_time_c Time_t>
        inline auto qstart_time() -> time_t
        {
            auto ns_value = std::chrono::duration_cast<std::chrono::nanoseconds>(this->m_start.time_since_epoch()).count();
            return { ns_value / (Time_t::value * 1.0E9L) };
        };

        template <teflon::unit::is_unit_time_c Time_t>
        inline auto qend_time() -> time_t
        {
            auto ns_value = std::chrono::duration_cast<std::chrono::nanoseconds>(this->m_end.time_since_epoch()).count();
            return { ns_value / (Time_t::value * 1.0E9L) };
        };

        template <teflon::unit::is_unit_time_c Time_t>
        inline auto qelapsed_time() -> time_t
        {
            time_point_t end;
            if (this->m_is_running) { end = steady_clock_t::now(); }
            else { end = this->m_end; }

            return { std::chrono::duration_cast<std::chrono::nanoseconds>(end - this->m_start).count() / (Time_t::value * 1.0E9L) };
        };

        // Safe time functions

        template <teflon::unit::is_unit_time_c Time_t>
        inline auto start_time() -> std::optional<time_t>
        {
            if (this->m_has_started)
            {
                return { qstart_time<Time_t>() };
            }
            else return {};
        };

        template <teflon::unit::is_unit_time_c Time_t>
        inline auto end_time() -> std::optional<time_t>
        {
            if (!this->m_is_running && this->m_has_ended)
            {
                return { qend_time<Time_t>() };
            }
            else return {};
        };

        template <teflon::unit::is_unit_time_c Time_t>
        inline auto elapsed_time() -> std::optional<time_t>
        {
            if (this->m_has_started)
            {
                return { qelapsed_time<Time_t>() };
            }
            else return {};
        };

    private:
        time_point_t m_start;
        time_point_t m_end;
        bool m_is_running = false;
        bool m_has_started = false;
        bool m_has_ended = false;
    };
}

#endif // TEFLON_UTIL_TIMER_HPP
