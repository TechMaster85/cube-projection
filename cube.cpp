#include "cube.h"

#include <eigen3/Eigen/src/Core/Matrix.h>

// Whoever figures out how to create the transformation matrix, copy the reset()
// function, but feed in degrees (in radians preferably to make sin() and cos()
// easier).

void Cube::reset() {
    points.clear();
    points.reserve(originalMat.size());   // 8

    // 2 rows, 3 columns, visualize this transformed
    // Don't know why they have goofy ahh syntax but it's const so it's fast
    const Eigen::MatrixXd transformation = (Eigen::MatrixXd(3, 3) << 1, 0, 0, 0, 1, 0, 0, 0, 0).finished();

    project_to_plane(transformation);
}

void Cube::transformed_points(const double& x, const double& y) {
    rotX += x;
    rotY += y;

    // transformation matrix rotating along x axis
    Eigen::MatrixXd rotx_transformation
      = (Eigen::MatrixXd(3, 3) << 1, 0, 0, 0, cos(rotX), -sin(rotY), 0, sin(rotY), cos(rotY)).finished();
    // transformation matrix rotating along y axis
    Eigen::MatrixXd roty_transformation
      = (Eigen::MatrixXd(3, 3) << cos(rotY), 0, sin(rotY), 0, 1, 0, -sin(rotY), 0, cos(rotY)).finished();
    // both
    roty_transformation = rotx_transformation * roty_transformation;

    project_to_plane(roty_transformation);

    // reference: https://www.malinc.se/math/linalg/rotatecubeen.php
}

void Cube::project_to_plane(const Eigen::MatrixXd& transformation) {
    points.clear();
    for (const Eigen::Vector3d& vec : originalMat) {
        const Eigen::Vector2d pointVector = transformation * vec;
        points.push_back(Point2D { pointVector[0], pointVector[1] });
    }
}

// Eigen::Vector2d Cube::project_vector_to_plane(Eigen::Vector3d &v) {}