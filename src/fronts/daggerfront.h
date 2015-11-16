/******************************************************************************/
/*                                                                            */
/******************************************************************************/
#ifndef SWEPT25_FRONTS_DAGGERFRONT_H
#define SWEPT25_FRONTS_DAGGERFRONT_H

#include<stdint.h>

typedef struct {
    uint64_t i_root, j_root;
    uint64_t i_tip, j_tip;
    uint64_t t_tip;
    uint64_t bytes_per_point;
    uint8_t  data[8];
} Swept25_DaggerFront2D;

uint64_t Swept25_DaggerFront2D_numPoints(uint64_t length);

uint64_t Swept25_DaggerFront2D_bytes(uint64_t length,
        uint64_t bytes_per_point);

uint64_t Swept25_DaggerFront2D_length(uint64_t i_root, uint64_t j_root,
                                      uint64_t i_tip, uint64_t j_tip);

Swept25_DaggerFront2D * Swept25_DaggerFront2D_new(
    uint64_t i_root, uint64_t j_root,
    uint64_t i_tip, uint64_t j_tip,
    uint64_t t_tip, uint64_t bytes_per_point);

#endif
/******************************************************************************/
/******************************************************************************/
/******************************************************************************/
