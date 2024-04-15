#ifndef CUBE_H
#define CUBE_H

#include <cmath>
#include <iostream>
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
    const std::vector<Eigen::Vector3d> originalMat {
        Eigen::Vector3d(-0.5, -0.5, -0.5), Eigen::Vector3d(0.5, -0.5, -0.5), Eigen::Vector3d(-0.5, 0.5, -0.5),
        Eigen::Vector3d(-0.5, -0.5, 0.5),  Eigen::Vector3d(0.5, 0.5, -0.5),  Eigen::Vector3d(-0.5, 0.5, 0.5),
        Eigen::Vector3d(0.5, -0.5, 0.5),   Eigen::Vector3d(0.5, 0.5, 0.5)
    };


    // After matrix is transformed, you'll get 8 of these.
    std::vector<Point2D> points;

    double rotX = 0;
    double rotY = 0;

public:
    void reset();
    const std::vector<Point2D>& getPoints() const { return points; }
    void transformed_points(const double& rotx, const double& roty);
    // void line_export(std::vector<Point2D> &vec);
    void project_to_plane(const Eigen::MatrixXd& transformation);

    void printRotation() const { std::cout << "X: " << rotX / M_PI << "π\tY: " << rotY / M_PI << "π\n"; };
};

#endif
