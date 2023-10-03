
#include "common.h"
#include "defs.h"
#include "draw.h"
#include "structs.h"
#include "util.h"
#include "player.h"

inline Sprite p_sprite;
void init_player()
{
    player.active = 1;

    player.x = get_scr_width_scaled() / 2;
    player.y = get_scr_height_scaled() / 2;
    
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
    player.health = 3;
}


void update_player(void)
{
   
}   

void draw_player(void)
{
    blit_from_sheet(game.spritesheet, player.sprite->dest, player.sprite->src, 0, SCREEN_SCALE, 1);
}

