/******************************************************************************/
/*                                                                            */
/******************************************************************************/

#include <stdint.h>
#include <stdlib.h>

#include "daggerfront.h"

uint64_t Swept25_DaggerFront2D_numPoints(uint64_t length)
{
    // length:
    //     abs(i_tip - i_root) if dagger is aligned in i direction, or
    //     abs(j_tip - j_root) if dagger is aligned in j direction
    // returns the number of points, which needs to be multiplied by
    // bytes_per_point to obtain the size of data
    uint64_t num_edge_points = length * 2 - 1;
    uint64_t num_interior_points = length * length;
    return num_interior_points * 2 + num_edge_points;
}

uint64_t Swept25_DaggerFront2D_bytes(uint64_t length,
        uint64_t bytes_per_point)
{
    // length:
    //     abs(i_tip - i_root) if dagger is aligned in i direction, or
    //     abs(j_tip - j_root) if dagger is aligned in j direction
    // bytes_per_point:
    //     number of bytes needed to store data at each point
    // returns the total size in bytes of a Swept25_DaggerFront2D structure
    uint64_t numPoints = Swept25_DaggerFront2D_numPoints(length);
    uint64_t dataBytes = numPoints * bytes_per_point;
    return dataBytes + sizeof(Swept25_DaggerFront2D) - 8;
}

uint64_t Swept25_DaggerFront2D_length(uint64_t i_root, uint64_t j_root,
                                      uint64_t i_tip, uint64_t j_tip)
{
    if ((i_root != i_tip) && (j_root != j_tip)) {
        return 0;
    }
    return (i_root != i_tip) ? abs(i_root - i_tip) : abs(j_root - j_tip);
}

Swept25_DaggerFront2D * Swept25_DaggerFront2D_new(
    uint64_t i_root, uint64_t j_root,
    uint64_t i_tip, uint64_t j_tip,
    uint64_t t_tip, uint64_t bytes_per_point)
{
    uint64_t length = Swept25_DaggerFront2D_length(
             i_root, j_root, i_tip, j_tip);
    uint64_t bytes = Swept25_DaggerFront2D_bytes(length, bytes_per_point);
    Swept25_DaggerFront2D * ptr = (Swept25_DaggerFront2D *) malloc(bytes);

    ptr->i_tip = i_tip;
    ptr->i_root = i_root;
    ptr->j_tip = j_tip;
    ptr->j_root = j_root;
    ptr->t_tip = t_tip;
    ptr->bytes_per_point = bytes_per_point;
    return ptr;
}

/******************************************************************************/
/******************************************************************************/
/******************************************************************************/
