
#include "common.h"

#include "defs.h"
#include "draw.h"
#include "init.h"
#include "input.h"
#include "stage.h"
#include "main.h"
#include <stdint.h>

Game game;
Entity player;
Stage stage;

inline void cap_fps(long *THEN, float *REMAINDER);

int main(int argc, char *argv[])
{
    long then;
    float remainder;

    srand(42);

    memset(&game, 0, sizeof(Game));
    
    init_SDL();

    atexit(game_close);

    init_game();

    init_stage();

    then = SDL_GetTicks();
    remainder = 0;

    while(1)
    {
        prepare_scene();

        handle_input();

        game.delegate.logic();
        game.delegate.draw();

        render_scene();

        cap_fps(&then, &remainder);
    }
    return(0);
}

inline void cap_fps(long *THEN, float *REMAINDER)
{// fps cap logic
    long wait, frame_time;

    wait = 16 + *REMAINDER;

    *REMAINDER -= (int)*REMAINDER;

    frame_time = SDL_GetTicks() - *THEN;

    wait -= frame_time;

    if(wait < 1)
    {
        wait = 1;
    }

    SDL_Delay(wait);

    *REMAINDER += 0.667f;

    *THEN = SDL_GetTicks();
}






















