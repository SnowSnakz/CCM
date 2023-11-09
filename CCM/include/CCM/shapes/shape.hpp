#ifndef CCM_SHAPE_HPP_INCLUDED
#define CCM_SHAPE_HPP_INCLUDED

#include "CCM/util.hpp"

// The shape mode controls how shapes are combined with other shapes.
enum CCMshapemode
{
    // The result of the shapes SDF is added to the total shape.
    CCM_ADD,

    // The result of the shapes SDF is subtracted from the total shape.
    CCM_SUBTRACT,

    // The result of the shapes SDF is multiplied with the total shape.
    CCM_MULTIPLY,

    // The total shape is set to the minimum between the total shape and the current shape.
    CCM_MIN,

    // The total shape is set to the maximum between the total shape and the current shape.
    CCM_MAX,

    CCM_SMOOTH_MIN,

    CCM_SMOOTH_MAX
};

// An base class for all volumetric shapes.
class CCMshape
{
protected:
    CCMshapemode _shapeMode;

public:
    // Get the signed distance to the nearest surface at the specified position.
    virtual CCMfloat SDF(CCMfloat x, CCMfloat y, CCMfloat z) = 0;

    // Get the shape mode. 
    CCMshapemode getShapeMode();
};

#endif
