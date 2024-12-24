#ifndef RAY_H
#define RAY_H
// include dependencies
#include "vec3.h"

class ray
{
public:
    // default constructor
    ray() {}

    // parameterized constructor
    ray(const point3 &origin, const vec3 &direction) : orig(origin), dir(direction) {}

    // public read-only properties
    const point3 &origin() const { return orig; }
    const vec3 &direction() const { return dir; }

    // used to get a point along the ray
    point3 at(double t) const
    {
        return orig + t * dir;
    }

private:
    // fields
    // origin plint of ray
    point3 orig;
    // direction of ray
    vec3 dir;
};

#endif