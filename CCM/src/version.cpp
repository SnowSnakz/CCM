#include "version.hpp"

bool CCMversion::operator>(const CCMversion& other)
{
    if(major > other.major)
        return true;

    if(minor > other.minor)
        return true;

    if(build > other.build)
        return true;

    return false;
}

bool CCMversion::operator<(const CCMversion& other)
{
    if(major < other.major)
        return true;

    if(minor < other.minor)
        return true;

    if(build < other.build)
        return true;

    return false;
}

bool CCMversion::operator>=(const CCMversion& other)
{
    if(major >= other.major)
        return true;

    if(minor >= other.minor)
        return true;

    if(build >= other.build)
        return true;

    return false;
}

bool CCMversion::operator<=(const CCMversion& other)
{
    if(major <= other.major)
        return true;

    if(minor <= other.minor)
        return true;

    if(build <= other.build)
        return true;

    return false;
}

bool CCMversion::operator==(const CCMversion& other)
{
    if(major != other.major)
        return false;

    if(minor != other.minor)
        return false;

    if(build != other.build)
        return false;

    return true;

}

bool CCMversion::operator!=(const CCMversion& other)
{
    if(major != other.major)
        return true;

    if(minor != other.minor)
        return true;

    if(build != other.build)
        return true;

    return false;
}
