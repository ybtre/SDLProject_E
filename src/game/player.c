
#include "common.h"
#include "defs.h"
#include "draw.h"
#include "structs.h"
#include "util.h"
#include "player.h"

inline Sprite   p_sprite;
inline char     is_on_left_side = 0;
inline char     was_pressed_this_frame = 0;
void init_player()
{
    player.active = 1;

    player.x = (get_scr_width_scaled() / 2) - (57 * SCREEN_SCALE);
    player.y = (get_scr_height_scaled() / 2) + (140 * SCREEN_SCALE);
    is_on_left_side = 0;
    
    player.dx = 0;
    player.dy = 0;

    p_sprite.active = 1;
    p_sprite.src.x = 0;
    p_sprite.src.y = 16;
    p_sprite.src.w = 8;
    p_sprite.src.h = 8;
        
    p_sprite.dest.x = player.x;
    p_sprite.dest.y = player.y;
    p_sprite.dest.w = 8;
    p_sprite.dest.h = 8;

    p_sprite.tex = game.spritesheet;

    player.sprite = &p_sprite;

    player.hitbox = player.sprite->dest;
    player.layer = GAMEPLAY;
    player.ent_type = PLAYER;

    stage.entities_pool[0] = player;
}


void update_player(void)
{
    if(game.keyboard[SDL_SCANCODE_SPACE])
    {
        //NOTE: set the key to UP state in order to only count single key press
        game.keyboard[SDL_SCANCODE_SPACE] = 0;

        if(is_on_left_side == 0)
        {
            //player.x = (get_scr_width_scaled() / 2) + (57 * SCREEN_SCALE);
            player.dx = PLAYER_SPEED;
            
            is_on_left_side = 1;
        }
        else if(is_on_left_side == 1)
        {
            player.dx = -PLAYER_SPEED;
            
            is_on_left_side = 0;
        }
    }
    
    player.x += player.dx;
    player.sprite->dest.x = player.x;
    if(player.x < (get_scr_width_scaled() / 2) - (49 * SCREEN_SCALE))
    {
        player.x = (get_scr_width_scaled() / 2) - (49 * SCREEN_SCALE);
    }
    if(player.x > (get_scr_width_scaled() / 2) + (49 * SCREEN_SCALE))
    {
        player.x = (get_scr_width_scaled() / 2) + (49 * SCREEN_SCALE);
    }
}   

void draw_player(void)
{
    blit_from_sheet(game.spritesheet, player.sprite->dest, player.sprite->src, 0, SCREEN_SCALE, 1);
}

