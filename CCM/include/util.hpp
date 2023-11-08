#ifndef CCM_UTIL_HPP_INCLUDED
#define CCM_UTIL_HPP_INCLUDED

#include <stdint.h>

#ifdef CCM_USE_DOUBLE
typedef double CCMfloat;
#else
typedef float CCMfloat;
#endif

#include <unicode/unistr.h>
typedef icu::UnicodeString CCMstring;

#define ccmMakeStringUTF8(cstr) icu::UnicodeString::fromUTF8(icu::StringPiece(cstr))

#endif
