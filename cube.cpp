#include "cube.h"

void Cube::reset() {
    points.clear();
    points.reserve(originalMat.size());   // 8

    // 2 rows, 3 columns, visualize this transformed
    const Eigen::Matrix<double, 2, 3> transformation {
        {0, 0},
        {0, 0},
        {0, 0}
    };

    for (const Eigen::Vector3d& vec : originalMat) {
        const Eigen::Vector2d pointVector = transformation * vec;
        points.push_back(Point2D { pointVector[0], pointVector[1] });
    }
}