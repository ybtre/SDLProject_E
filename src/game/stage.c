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

    game_state = MAIN_MENU;

    init_player();
    init_entities();
}

inline void update(void)
{
    switch(game_state)
    {
        case MAIN_MENU:
            {
                if(game.keyboard[SDL_SCANCODE_SPACE])
                {
                    reset_game();
                    game_state = PLAYING;
                }
            }
            break;
        
        case PLAYING:
            {
                update_player();

                update_entities();

                if(stage.entities_pool[0].active == 0)
                {
                    game_state = GAME_OVER;
                }
            }
            break;

        case GAME_OVER:
            {
                if(game.keyboard[SDL_SCANCODE_SPACE])
                {
                    reset_game();
                    game_state = PLAYING;
                }
            }
            break;

    }
    if(game.keyboard[SDL_SCANCODE_ESCAPE])
    {
        exit(1);
    }
}

inline void render(void)
{
    switch(game_state)
    {
        case MAIN_MENU:
            {
                draw_entities();
                draw_player();

                char buff[32];
                sprintf(buff, "PRESS SPACE TO PLAY!");

                SDL_Rect dest = {get_scr_width_scaled() / 5, get_scr_height_scaled() / 2, 0, 0};
                render_text(buff, dest, 2.f);
            }
            break;
        
        case PLAYING:
            {
                draw_entities();
                draw_player();
            }
            break;

        case GAME_OVER:
            {
                draw_entities();
                draw_player();

                char buff[32];
                sprintf(buff, "PRESS SPACE TO RESTART!");

                SDL_Rect dest = {get_scr_width_scaled() / 5, get_scr_height_scaled() / 2, 0, 0};
                render_text(buff, dest, 2.f);
            }
            break;
    }

    blit(cursor_texture, game.mouse.x, game.mouse.y, 1.f, 1);
}


inline void reset_game(void)
{
    init_player();
    init_entities();
}
