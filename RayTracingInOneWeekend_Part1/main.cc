#include <iostream>
#include "color.h"
#include "vec3.h"

int main()
{
    // image params
    int image_width = 256;
    int image_height = 256;

    // render image using ppm file format
    std::cout << "P3\n"
              << image_width << ' ' << image_height << "\n255\n";

    // set pixels' color values left to right
    // top to bottom rows
    for (int i = 0; i < image_height; i++)
    {
        // output progress
        std::clog << "\rScanlines remaining: " << (image_height - i) << ' ' << std::flush;
        for (int j = 0; j < image_width; j++)
        {
            auto pixel_color = color(double(j) / (image_width - 1), double(i) / (image_height - 1), 0);
            write_color(std::cout, pixel_color);
        }
    }

    // output that render is complete
    std::clog << "\rDone.   \n";
}
