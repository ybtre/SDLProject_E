#ifndef UTIL_H
#define UTIL_H

#include <stdint.h>

int collision(int X1, int Y1, int W1, int H1, int X2, int Y2, int W2, int H2);
void calc_slope(int X1, int Y1, int X2, int Y2, float *DX, float *DY);
float get_angle(int X1, int Y1, int X2, int Y2);

extern void* mmalloc(uint64_t SIZE);
extern void mfree(void* MEM_TO_FREE);

#endif
