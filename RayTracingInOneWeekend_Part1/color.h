#ifndef COLOR_H
#define COLOR_H

// include minimal dependency
#include "vec3.h" // defines vec3 and point3
#include "interval.h"

using color = vec3;

// used to display the color's rgb values
inline void write_color(std::ostream &out, const color &pixel_color)
{
    // create rgb variables
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // convert from range 0-1 to range 0-255
    static const interval intensity(0.000, 0.999);
    int rbyte = int(256 * intensity.clamp(r));
    int gbyte = int(256 * intensity.clamp(g));
    int bbyte = int(256 * intensity.clamp(b));

    // display values
    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

#endif