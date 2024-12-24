#include <iostream>

#include "color.h"
#include "vec3.h"
#include "ray.h"

// blue to white gradient
color ray_color(const ray &r)
{
    // convert ray to unit vecotr
    vec3 unit_direction = unit_vector(r.direction());
    // calculate height
    auto a = 0.5 * (unit_direction.y() + 1.0);
    // scale amount of blue by height
    return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}

int main()
{
    // image setup
    auto aspect_ratio = 16.0 / 9.0;
    int image_width = 400;
    // calculate image height
    int image_height = int(image_width / aspect_ratio);
    // ensure it is at least 1 using turnary operator
    image_height = (image_height < 1) ? 1 : image_height;

    // camera setup
    auto focal_length = 1.0;
    // viewport widths less than one are
    // acceptable since they are a real number
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (double(image_width) / image_height);
    auto camera_center = point3(0, 0, 0);

    // calculate the vectors actoss the horizontal and down the vertical viewport edges
    auto viewport_u = vec3(viewport_width, 0, 0);
    auto viewport_v = vec3(0, -viewport_height, 0);

    // calculate the horizontal and vertical delta vectors from pixel to pixel
    auto pixel_delta_u = viewport_u / viewport_width;
    auto pixel_delta_v = viewport_v / viewport_height;

    // get the location of the upper left pixel
    auto viewport_upper_left = camera_center - vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    // render image using ppm file format
    std::cout
        << "P3\n"
        << image_width << ' ' << image_height << "\n255\n";

    // set pixels' color values left to right
    // top to bottom rows
    for (int i = 0; i < image_height; i++)
    {
        // output progress
        std::clog << "\rScanlines remaining: " << (image_height - i) << ' ' << std::flush;
        for (int j = 0; j < image_width; j++)
        {
            auto pixel_center = pixel00_loc + (j * pixel_delta_u) + (i * pixel_delta_v);
            auto ray_direction = pixel_center - camera_center;
            ray r(camera_center, ray_direction);

            color pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);
        }
    }

    // output that render is complete
    std::clog << "\rDone.   \n";
}
