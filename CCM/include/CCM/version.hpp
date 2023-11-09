#ifndef CCM_VERSION_HPP_INCLUDED
#define CCM_VERSION_HPP_INCLUDED

#include <cstdint>

struct CCMversion
{
    uint8_t major;
    uint8_t minor;
    uint8_t build;

    bool operator>(const CCMversion& other);
    bool operator<(const CCMversion& other);
    bool operator>=(const CCMversion& other);
    bool operator<=(const CCMversion& other);
    bool operator==(const CCMversion& other);
    bool operator!=(const CCMversion& other);
};

#endif
