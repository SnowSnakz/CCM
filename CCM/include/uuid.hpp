#ifndef CCM_UUID_HPP_INCLUDED
#define CCM_UUID_HPP_INCLUDED

#include <iostream>
#include <cstdint>

struct CCMuuid
{
private:
    uint8_t bytes[16];

public:
    // Parse UUID from string. 
    // This function takes in a UUID string, the string is not required to be hyphenated.
    // Note: This function does not check for invalid characters, any invalid characters will produce undefined behavior.
    static CCMuuid fromString(const char* str);

    // Insert a UUID into a string at the specified offset.
    void toString(char* result, size_t offset, bool hyphenated, bool uppercase);
};

#endif
