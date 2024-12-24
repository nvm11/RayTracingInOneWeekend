#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec3
{
public:
    double e[3];

    // default constructor
    vec3() : e{0, 0, 0} {}
    // param constructor
    vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

    // access to indices
    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }

    // negation operator
    vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
    // array syntax for const, copy of value
    double operator[](int i) const { return e[i]; }
    // return reference
    double &operator[](int i) { return e[i]; }

    // addition
    vec3 &operator+=(const vec3 &v)
    {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }
    // subtraction
    vec3 &operator-=(const vec3 &v)
    {
        e[0] -= v.e[0];
        e[1] -= v.e[1];
        e[2] -= v.e[2];
        return *this;
    }
    // multiplication
    vec3 &operator*=(double t)
    {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }
    // division
    vec3 &operator/=(double t)
    {
        return *this *= 1 / t;
    }

    // useful functions
    double length() const
    {
        return std::sqrt(length_squared());
    }

    double length_squared() const
    {
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
    }
};

// point 3 is just vec3, but useful for geomrety clarity
using point = vec3;

// utility functions
// print values
inline std::ostream &operator<<(std::ostream &out, const vec3 &v)
{
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}
// addition
inline vec3 operator+(const vec3 &u, const vec3 &v)
{
    return vec3(v.e[0] + u.e[0], v.e[1] + u.e[1], v.e[2] + u.e[2]);
}
// subtraction
inline vec3 operator-(const vec3 &u, const vec3 &v)
{
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}
// multiplication
inline vec3 operator*(const vec3 &u, const vec3 &v)
{
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}
// power
inline vec3 operator*(double t, const vec3 &v)
{
    return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}
// other order
inline vec3 operator*(const vec3 &v, double t)
{
    return t * v;
}
// division
inline vec3 operator/(const vec3 &u, const vec3 &v)
{
    return vec3(u.e[0] / v.e[0], u.e[1] / v.e[1], u.e[2] / v.e[2]);
}
// const division
inline vec3 operator/(const vec3 &v, double t)
{
    return (1 / t) * v;
}
// dot product
inline double dot(const vec3 &u, const vec3 &v)
{
    return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2];
}
// cross product
inline vec3 cross(const vec3 &u, const vec3 &v)
{
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(const vec3 &v)
{
    return v / v.length();
}

#endif