#ifndef CCM_SHAPE_HPP_INCLUDED
#define CCM_SHAPE_HPP_INCLUDED

#include "CCM.hpp"

// The shape mode controls how shapes are combined with other shapes.
enum CCMshapemode
{
    CCM_ADD,
    CCM_SUBTRACT,
    CCM_MULTIPLY,
    CCM_MIN,
    CCM_MAX
};

// An base class for all volumetric shapes.
class CCMshape
{
protected:
    CCMshapemode _shapeMode;

public:
    // Get the signed distance to the nearest surface at the specified position.
    virtual double SDF(double x, double y, double z) = 0;

    // Get the shape mode. 
    CCMshapemode getShapeMode();
};


#endif
