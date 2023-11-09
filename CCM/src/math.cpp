#include "CCM/math.hpp"

CCMfloat CCMvector::length();
CCMfloat CCMvector::lengthSqr();

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
