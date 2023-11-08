#include "uuid.hpp"

const char* _CCM_HEX_LOWER = "0123456789abcdef";
const char* _CCM_HEX_UPPER = "0123456789ABCDEF";

const uint16_t _CCM_UUID_HYPHEN_MASK = 0b0001001001000000;

CCMuuid CCMuuid::fromString(const char* str)
{
    CCMuuid result;

    uint8_t byte, temp;
    int offset = 0;

    for(int i = 0; i < 16; i++)
    {
        // Ignore hyphens.
        if((_CCM_UUID_HYPHEN_MASK >> i) & 1)
        {
            if(str[offset] == '-')
                offset++;
        }

        temp = str[offset++];

        // Convert hex to dec.
        if(temp > '9')
        {
            if(temp > 'F')
                temp -= 'a' - 10;
            else
                temp -= 'A' - 10;
        }
        else temp -= '0';

        // Set high nibble.
        byte = temp << 4;

        temp = str[offset++];

        // Convert hex to dec.
        if(temp > '9')
        {
            if(temp > 'F')
                temp -= 'a' - 10;
            else
                temp -= 'A' - 10;
        }
        else temp -= '0';

        // Set low nibble.
        byte |= temp;

        // Set target byte.
        result.bytes[i] = byte;
    }

    return result;
}

void CCMuuid::toString(char* result, size_t offset, bool hyphenated, bool uppercase)
{
    const char* hex = uppercase ? _CCM_HEX_UPPER : _CCM_HEX_LOWER;
    uint16_t hyphenMask = hyphenated ? _CCM_UUID_HYPHEN_MASK : 0;

    int low, high;
    for(int i = 0; i < 16; i++)
    {
        high = bytes[i] >> 4;
        low = bytes[i] & 0b1111;

        result[offset++] = hex[high];
        result[offset++] = hex[low];

        if((hyphenMask >> i) & 1)
            result[offset++] = '-';
    }
}
