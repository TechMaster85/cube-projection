#include "cube.h"

// Whoever figures out how to create the transformation matrix, copy the reset() function,
// but feed in degrees (in radians preferably to make sin() and cos() easier).

void Cube::reset() {
    points.clear();
    points.reserve(originalMat.size());   // 8

    // 2 rows, 3 columns, visualize this transformed
    // Don't know why they have goofy ahh syntax but it's const so it's fast
    const Eigen::MatrixXd transformation = (Eigen::MatrixXd(2, 3) << 1, 0, 0, 0, 1, 0).finished();

    for (const Eigen::Vector3d& vec : originalMat) {
        const Eigen::Vector2d pointVector = transformation * vec;
        points.push_back(Point2D { pointVector[0], pointVector[1] });
    }
}


// Only two "directions" it can rotate at once, take in either degrees up down for up down arrow and degrees left right
// for left right arrow
// void Cube::transformed_points(float rads_ud, float rads_lr) {
//     float rotx = M_PI / 12;
//     float roty = M_PI / 12;

//     Eigen::MatrixXd transformation = (Eigen::MatrixXd(2, 3) << 1, 0, 0, 0, 1, 0).finished();
// }

void Cube::project_to_plane() {}
