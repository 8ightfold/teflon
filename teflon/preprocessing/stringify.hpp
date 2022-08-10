#ifndef TEFLON_PREPROCESSING_STRINGIFY_HPP
#define TEFLON_PREPROCESSING_STRINGIFY_HPP

#include <teflon/external/boost/preprocessor/stringize.hpp>
#include <teflon/preprocessing/safeconcat.hpp>

#define TEFLON_STRINGIFY(text) BOOST_PP_STRINGIZE(text)

#endif // TEFLON_PREPROCESSING_STRINGIFY_HPP