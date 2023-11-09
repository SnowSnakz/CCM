#ifndef CCM_BONE_HPP_INCLUDED
#define CCM_BONE_HPP_INCLUDED

#include "CCM/util.hpp"

class CCMbone
{
private:
    CCMbone* parent;
    CCMbone** children;

    CCMfloat length;

public:
    CCMbone* getParent();

    int getChildCount();
    CCMbone* getChild(int index);
};

#endif
