#ifndef TEFLON_PREPROCESSING_SAFECONCAT_HPP
#define TEFLON_PREPROCESSING_SAFECONCAT_HPP

#include <teflon/external/boost/preprocessor/cat.hpp>
#include <teflon/preprocessing/chars.hpp>
// Thanks Boost.

#define TEFLON_SAFECONCAT(a, b) BOOST_PP_CAT(a, b)

#define TEFLON_TRICONCAT(a, b, c) TEFLON_SAFECONCAT(TEFLON_SAFECONCAT(a, b), c)
#define TEFLON_QUADCONCAT(a, b, c, d) TEFLON_SAFECONCAT(TEFLON_SAFECONCAT(a, b), TEFLON_SAFECONCAT(c, d))

#endif // TEFLON_PREPROCESSING_SAFECONCAT_HPP