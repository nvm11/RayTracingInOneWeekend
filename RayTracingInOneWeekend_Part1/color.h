#ifndef COLOR_H
#define COLOR_H

// include minimal dependency
#include "vec3.h" // defines vec3 and point3

using color = vec3;

// used to display the color's rgb values
inline void write_color(std::ostream &out, const color &pixel_color)
{
    // create rgb variables
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // convert from range 0-1 to range 0-255
    int rbyte = int(255.999 * r);
    int gbyte = int(255.999 * g);
    int bbyte = int(255.999 * b);

    // display values
    //out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

#endif