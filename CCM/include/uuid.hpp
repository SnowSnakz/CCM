#ifndef CCM_UUID_HPP_INCLUDED
#define CCM_UUID_HPP_INCLUDED

struct CCMuuid
{
public:
    // Parse UUID from string.
    static CCMuuid fromString(const char* str);
};

#endif
