#ifndef CCM_MATH_HPP_INCLUDED
#define CCM_MATH_HPP_INCLUDED

#include "CCM/util.hpp"

template<int components>
class CCMvector
{
protected:
    CCMfloat _components[components];

public:
    CCMfloat length();
    CCMfloat lengthSqr();

    template<typename TVector>
    static TVector add(TVector a, TVector b);

    template<typename TVector>
    static TVector subtract(TVector a, TVector b);

    template<typename TVector>
    static CCMvector cross(TVector a, TVector b);

    template<typename TVector>
    static CCMfloat dot(TVector a, TVector b);

    template<typename TVector>
    static TVector normalize(TVector vec);
};

class CCMvec2 : public CCMvector<2>
{
public:
    CCMfloat x();
    void x(CCMfloat x);

    CCMfloat y();
    void y(CCMfloat y);
};

class CCMvec3 : public CCMvector<3>
{
public:
    CCMfloat x();
    void x(CCMfloat x);

    CCMfloat y();
    void y(CCMfloat y);

    CCMfloat z();
    void z(CCMfloat z);
};

class CCMvec4 : public CCMvector<4>
{
public:
    CCMfloat x();
    void x(CCMfloat x);

    CCMfloat y();
    void y(CCMfloat y);

    CCMfloat z();
    void z(CCMfloat z);

    CCMfloat w();
    void w(CCMfloat w);
};

class CCMquat : public CCMvec4
{
public:
    CCMvec3 eulerAngles();
    void eulerAngles(CCMvec3 angles);
};

constexpr CCMfloat CCM_PI = (CCMfloat)3.14159265359;
constexpr CCMfloat CCM_RAD_TO_DEG = (CCMfloat)(180 / CCM_PI);
constexpr CCMfloat CCM_DEG_TO_RAD = (CCMfloat)(CCM_PI / 180);

#endif
