#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "rtweekend.h"

class sphere : public hittable
{
public:
    sphere(const point3 &center, double radius) : center(center), radius(std::fmax(0, radius)) {}
    bool hit(const ray &r, double ray_tmin, double ray_tmax, hit_record &rec) const override
    {
        // set b = -2h in original code to get simplifications for variables
        vec3 oc = center - r.origin();
        auto a = r.direction().length_squared();
        auto h = dot(r.direction(), oc);
        auto c = oc.length_squared() - radius * radius;

        auto discriminant = h * h - a * c;
        // check if hidden behind something
        if (discriminant < 0)
        {
            return false;
        }

        auto sqrtd = std::sqrt(discriminant);
        // find nearest root in acceptable range
        auto root = (h - sqrtd) / a;
        // root is not along ray
        if (root <= ray_tmin || ray_tmax <= root)
        {
            return false;
        }

        rec.t = root;
        rec.p = r.at(rec.t);
        vec3 outward_normal = (rec.p - center) / radius;
        rec.set_face_normal(r, outward_normal);
        rec.normal = (rec.p - center) / radius;

        // sphere was hit
        return true;
    }

private:
    point3 center;
    double radius;
};

#endif