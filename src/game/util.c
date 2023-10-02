
#include "common.h"

#include "util.h"
#include "defs.h"
#include <stdint.h>
#include <stdlib.h>

inline uint64_t total_malloc    = 0;
inline uint64_t total_free      = 0;

extern void* mmalloc(uint64_t SIZE)
{
    void* mem_ptr;

    mem_ptr = malloc(SIZE);

    total_malloc += sizeof(mem_ptr);

#ifdef MEMORY_DEBUG
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Total Malloc: %i", total_malloc);
#endif

    return(mem_ptr);
}

extern void mfree(void* MEM_TO_FREE)
{
    total_malloc -= sizeof(MEM_TO_FREE);
    total_free += sizeof(MEM_TO_FREE);

#ifdef MEMORY_DEBUG
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Total Free: %i", total_free);

    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Difference: %i", total_malloc - total_free);
#endif

    free(MEM_TO_FREE);
}

int collision(int X1, int Y1, int W1, int H1, int X2, int Y2, int W2, int H2)
{
    return((MAX(X1, X2) < MIN(X1 + W1, X2 + W2)) && (MAX(Y1, Y2) < MIN(Y1 + H1, Y2 + H2)));
}

void calc_slope(int X1, int Y1, int X2, int Y2, float *DX, float *DY)
{
    int steps = MAX(abs(X1 - X2), abs(Y1 - Y2));

    if(steps == 0)
    {
        *DX = *DY = 0;
        return;
    }

    *DX = (X1 - X2);
    *DX /= steps;

    *DY = (Y1 - Y2);
    *DY /= steps;
}

float get_angle(int X1, int Y1, int X2, int Y2)
{
    float angle = -90 + atan2(Y1 - Y2, X1 - X2) * (180 / PI);

    return angle >= 0 ? angle : 360 + angle;
}














