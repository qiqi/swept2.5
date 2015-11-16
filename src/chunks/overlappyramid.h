#ifndef SWEPT25_CHUNKS_OVERLAPPYRAMID_H
#define SWEPT25_CHUNKS_OVERLAPPYRAMID_H

#include "fronts/daggerfront.h"

void OverlapPyramid(
        const Swept25_DaggerFront2D * bottom_north,
        const Swept25_DaggerFront2D * bottom_south,
        const Swept25_DaggerFront2D * bottom_east,
        const Swept25_DaggerFront2D * bottom_west,
        Swept25_DaggerFront2D * top_north,
        Swept25_DaggerFront2D * top_south,
        Swept25_DaggerFront2D * top_east,
        Swept25_DaggerFront2D * top_west);

#endif
