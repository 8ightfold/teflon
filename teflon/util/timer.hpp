#ifndef TEFLON_UTIL_TIMER_HPP
#define TEFLON_UTIL_TIMER_HPP

#include <chrono>
#include <teflon/util/units.hpp>
#include <teflon/xio/xtypeid/cttypeid.hpp>

namespace teflon::util 
{
    class timer
    {
        using steady_clock_t = std::chrono::high_resolution_clock;
        using time_point_t = steady_clock_t::time_point;
    public:
        inline void start() 
        {
            this->Start = steady_clock_t::now();
            this->isRunning = true;
        }

        inline void stop() 
        {
            this->End = steady_clock_t::now();
            this->isRunning = false;
        }

        inline void restart() 
        {
            this->Start = steady_clock_t::now();
        }

        template <typename Time_t>
        inline long double telapsed()
        {
            static_assert(teflon::unit::is_unit_time<Time_t>::value, "Not a valid time unit");

            time_point_t end;
            if (this->isRunning) { end = steady_clock_t::now(); }
            else { end = this->End; }

            return std::chrono::duration_cast<std::chrono::nanoseconds>(end - this->Start).count() * Time_t::value;
        };

    private:
        time_point_t Start;
        time_point_t End;
        bool isRunning = false;
    };
}

#endif // TEFLON_UTIL_TIMER_HPP
