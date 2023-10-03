#include "common.h"

#include "defs.h"
#include "structs.h"
#include "draw.h"
#include "stage.h"
#include "player.h"
#include "entities.h"
#include "util.h"

inline void update(void);
inline void render(void);

inline SDL_Texture *cursor_texture;
inline SDL_Texture *spritesheet;

inline void reset_game(void);

void init_stage(void)
{
    game.delegate.logic = update;
    game.delegate.draw = render;

    memset(&stage, 0, sizeof(Stage));

    cursor_texture = load_texture("assets/cursor.png");
    game.spritesheet = load_texture("assets/spritesheet.png"); 

    init_player();
    init_entities();
}

inline void update(void)
{
    update_player();

    update_entities();

    if(game.keyboard[SDL_SCANCODE_ESCAPE])
    {
        exit(1);
    }
}

inline void render(void)
{
    draw_entities();
    draw_player();

    blit(cursor_texture, game.mouse.x, game.mouse.y, 1.f, 1);
}


inline void reset_game(void)
{
    //init_player();
    //init_entities();
}
