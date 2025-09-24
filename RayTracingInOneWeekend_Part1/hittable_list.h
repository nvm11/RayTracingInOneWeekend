#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"
#include <vector>

#include "rtweekend.h"

class hittable_list : public hittable
{
public:
    // Fields
    std::vector<shared_ptr<hittable>> objects;

    // Constructors
    hittable_list() {}
    hittable_list(shared_ptr<hittable> object) { add(object); }

    // Functions
    void clear() { objects.clear(); }
    void add(shared_ptr<hittable> object) { objects.push_back(object); }

    bool hit(const ray &r, interval ray_t, hit_record &rec) const override
    {
        hit_record temp_rec;
        bool hit_anything = false;
        auto closest_so_far = ray_t.max;

        // Check each object in list
        for (const auto &object : objects)
        {
            // Closer than previous hit?
            if (object->hit(r, interval(ray_t.min, closest_so_far), temp_rec))
            {
                hit_anything = true;
                // Update closest hit
                closest_so_far = temp_rec.t;
                // Update hit record
                rec = temp_rec;
            }
        }
        // Return whether anything was hit
        return hit_anything;
    }
};

#endif