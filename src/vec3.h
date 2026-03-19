#pragma once

#include <cmath>
#include <iostream>

/*
    This class will represent vectors in 3D space.
*/
class vec3 {
public:
    // Vector elements
    double e[3];

    vec3() {
        e[0] = 0.0;
        e[1] = 0.0;
        e[2] = 0.0;
    }

    vec3( double x, double y, double z ) {
        e[0] = x;
        e[1] = y;
        e[2] = z;
    }

    // getters for code readability
    double x() const { return e[0]; }
    double y() const  { return e[1]; }
    double z() const  { return e[2]; }

    // Operator overloading
    vec3    operator-  ()        const   { return vec3( -e[0], -e[1], -e[2] ); }
    double  operator[] ( int i ) const   { return e[i]; }
    double& operator[] ( int i )         { return e[i]; }

    vec3& operator+=( const vec3& v ) { 
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    vec3& operator*=( double t ) { 
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    vec3& operator/=( double t ) { 
        return *this *= 1/t;
    }

    double length() const {
        return std::sqrt( length_squared() );
    }

    double length_squared() const {
        return ( e[0] * e[0] ) + ( e[1] * e[1] ) + ( e[2] * e[2] );
    }
};

// Generate an alias for vec3 called point3. For this project, opints and vectors in 3D space are the same under the hood
using point3 = vec3;

// Vector utitlity functions

// Define the behavior  of cout << vec3_object;
inline std::ostream& operator <<( std::ostream& out, const vec3& v ) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

// Define behavior of vec3 = vec3 + vec3
inline vec3 operator+( const vec3& u, const vec3& v ) {
    return vec3(
        u.e[0] + v.e[0],
        u.e[1] + v.e[1],
        u.e[2] + v.e[2]
    );
}

// Define behavior of vec3 = vec3 - vec3
inline vec3 operator-( const vec3& u, const vec3& v ) {
    return vec3(
        u.e[0] - v.e[0],
        u.e[1] - v.e[1],
        u.e[2] - v.e[2]
    );
}

// Define behavior of vec3 = vec3 * vec3
inline vec3 operator*( const vec3& u, const vec3& v ) {
    return vec3(
        u.e[0] * v.e[0],
        u.e[1] * v.e[1],
        u.e[2] * v.e[2]
    );
}

// Define behavior of vec3 = double * vec3
inline vec3 operator*( double t, const vec3& v ) {
    return vec3(
        t * v.e[0],
        t * v.e[1],
        t * v.e[2]
    );
}

// Define behavior of vec3 = vec3 * double
inline vec3 operator*( const vec3& v, double t ) {
    return t * v;
}

// Define behavior of vec3 = vec3 / double
inline vec3 operator/( const vec3& v, double t ) {
    return ( 1 / t ) * v;
}

// Define vector dot product
inline double dot( const vec3& u, const vec3& v ) {
    return ( u.e[0] * v.e[0] ) +
           ( u.e[1] * v.e[1] ) +
           ( u.e[2] * v.e[2] );
}

// Define vector cross product
inline vec3 cross(const vec3& u, const vec3& v) {
    return  vec3(
                u.e[1] * v.e[2] - u.e[2] * v.e[1],  // newX
                u.e[2] * v.e[0] - u.e[0] * v.e[2],  // newY
                u.e[0] * v.e[1] - u.e[1] * v.e[0]   // newZ
            );
}

// Define the unit vector
inline vec3 unit_vector( const vec3& v ) {
    return v / v.length();
}