#ifndef CUBE_H
#define CUBE_H

#include <cmath>
#include <vector>

#include <eigen3/Eigen/Core>

// Creates variables M_PI and other useful constants
// https://learn.microsoft.com/en-us/cpp/c-runtime-library/math-constants?view=msvc-170
#define _USE_MATH_DEFINES


//         |
//         Y
//         |
//         |______X_
//        /
//      Z
//    /

struct Point2D {
    double x;
    double y;
};

struct Line {
    double x1;
    double y1;
    double x2;
    double y2;
};

class Cube {
private:
    // Transform this by a 2x3 matrix to get your points
    const std::vector<Eigen::Vector3d> originalMat { Eigen::Vector3d(0, 0, 0), Eigen::Vector3d(1, 0, 0),
                                                     Eigen::Vector3d(0, 1, 0), Eigen::Vector3d(0, 0, 1),
                                                     Eigen::Vector3d(1, 1, 0), Eigen::Vector3d(0, 1, 1),
                                                     Eigen::Vector3d(1, 0, 1), Eigen::Vector3d(1, 1, 1) };

    // After matrix is transformed, you'll get 8 of these.
    std::vector<Point2D> points;

public:
    void reset();
    const std::vector<Point2D>& getPoints() const { return points; }
    void transformed_points(const float& rotx, const float& roty);
    // void line_export(std::vector<Point2D> &vec);
    void project_to_plane();
    Eigen::Vector2d project_vector_to_plane(Eigen::Vector3d &v);


    // void printPoints():

    // TODO: Make a project function (maybe with helpers) to:
    // - Rotate along x axis (rolling forward or backward) by d degrees
    // - Rotate along y axis (spinning left or right) by d degrees

    // (Rotating along z axis not needed, quaternions suck ¯\_(ツ)_/¯)

    // Rotation can be accomplished by matrix multiplication of a 2x3 vector
    // you figure out by each vector in originalMat. Check out reset() in
    // cube.cpp

    // This is a pretty helpful guide to eigen:
    // https://cs2240.graphics/assignments/eigen_tutorial.pdf

    // If your functions aren't easy one-liners, please put them in cube.cpp.
};

#endif