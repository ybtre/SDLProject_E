

#include "common.h"
#include "defs.h"
#include "draw.h"
#include "structs.h"
#include "util.h"
#include "entities.h"

#define NUM_LAYERS      6
//layer 0 = bg deepest = green
//layer 1 = bg          1 less deep
//layer 2 = bg          2 less deep
//layer 3 = gameplay    3 less deep = platforms and player
//layer 4 = fg          4 less deep
//layer 5 = UI          5 less deep
inline Entity layers[NUM_LAYERS];
inline Sprite layer_spr[NUM_LAYERS];

inline void init_layers(void);

void init_entities(void)
{
    init_layers();
}

void update_entities(void)
{

}

void draw_entities(void)
{
    int i = 0;
    for(i = 0; i < 3; i++)
    {
        blit_from_sheet(game.spritesheet, layers[i].sprite->dest, layers[i].sprite->src, 0, SCREEN_SCALE, 1);
    }
}

void init_layers(void)
{
    {//bg   layer 1
        layers[0].active = 1;

        layers[0].x = get_scr_width_scaled() / 2 - 40;
        layers[0].y = get_scr_height_scaled() / 2;

        layers[0].dx = 0;
        layers[0].dy = 0;

        layer_spr[0].active = 1;
        layer_spr[0].src.x = 480;
        layer_spr[0].src.y = 0;
        layer_spr[0].src.w = 60;
        layer_spr[0].src.h = 320;

        layer_spr[0].dest.x = layers[0].x;
        layer_spr[0].dest.y = layers[0].y;
        layer_spr[0].dest.w = layer_spr[0].src.w;
        layer_spr[0].dest.h = layer_spr[0].src.h;

        layers[0].sprite = &layer_spr[0];

        layers[0].hitbox = layers[0].sprite->dest;
        layers[0].health = 1;
    } 

    {//bg   layer 2
        layers[1].active = 1;

        layers[1].x = get_scr_width_scaled() / 2;
        layers[1].y = get_scr_height_scaled() / 2;

        layers[1].dx = 0;
        layers[1].dy = 0;

        layer_spr[1].active = 1;
        layer_spr[1].src.x = 208;
        layer_spr[1].src.y = 0;
        layer_spr[1].src.w = 192;
        layer_spr[1].src.h = 320;

        layer_spr[1].dest.x = layers[1].x;
        layer_spr[1].dest.y = layers[1].y;
        layer_spr[1].dest.w = layer_spr[1].src.w;
        layer_spr[1].dest.h = layer_spr[1].src.h;

        layers[1].sprite = &layer_spr[1];

        layers[1].hitbox = layers[1].sprite->dest;
        layers[1].health = 1;
    } 

    {//bg   layer 3
        layers[2].active = 1;

        layers[2].x = get_scr_width_scaled() / 2;
        layers[2].y = get_scr_height_scaled() / 2;

        layers[2].dx = 0;
        layers[2].dy = 0;

        layer_spr[2].active = 1;
        layer_spr[2].src.x = 80;
        layer_spr[2].src.y = 0;
        layer_spr[2].src.w = 128;
        layer_spr[2].src.h = 320;

        layer_spr[2].dest.x = layers[2].x;
        layer_spr[2].dest.y = layers[2].y;
        layer_spr[2].dest.w = layer_spr[2].src.w;
        layer_spr[2].dest.h = layer_spr[2].src.h;

        layers[2].sprite = &layer_spr[2];

        layers[2].hitbox = layers[2].sprite->dest;
        layers[2].health = 1;
    } 
}
