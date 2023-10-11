#ifndef STRUCTS_H
#define STRUCTS_H

#include "../Include/SDL2/SDL.h"
#include "../Include/SDL2/SDL_ttf.h"
#include "defs.h"

typedef struct
{
    void (*logic)(void);
    void (*draw)(void);
} Delegate;

typedef struct Texture
{
    char            active;

    char            name[MAX_NAME_LENGTH];
    SDL_Texture*    texture;
} Texture;

typedef struct
{
    int x;
    int y;
    int button[MAX_MOUSE_BUTTONS];
    int wheel;
} Mouse;

#define TEXTURE_CACHE_MAX   16
typedef struct
{
	SDL_Renderer*   renderer;
	SDL_Window*     window;
    Delegate        delegate;

    Mouse           mouse;

    int             keyboard[MAX_KEYBOARD_KEYS];

    TTF_Font        *font;

    SDL_Texture     *spritesheet;

    Texture         texture_cache[TEXTURE_CACHE_MAX];
} Game;
extern Game game;

typedef enum Game_State
{
    MAIN_MENU,
    PLAYING,
    GAME_OVER,
} Game_State;
extern Game_State game_state;

typedef enum Layers
{
    BG_0,
    BG_1,
    BG_2,
    GAMEPLAY,
    FG,
    UI,

    NUM_LAYERS,
} Layers;

enum Flags 
{
    GAME_PAUSED         = 1 << 0,
};

// |= flag      : set flag
// &= !()flag   : unset flag
// ^= flag      : flip flag
typedef struct Game_Flags
{
    uint64_t flags;

} Game_Flags;
extern Game_Flags game_flags;

typedef struct
{
    char            active;

    SDL_Rect        src;
    SDL_Rect        dest;

    SDL_Texture     *tex;
} Sprite;

typedef enum Entity_Type
{
    PLAYER      = 0,
    PLATFORM    = 1,
    TRAP        = 2,
    ENVIRONMENT = 3,
} Entity_Type;

typedef struct
{
    char            active;

    int             x;
    int             y;
    int             dx;
    int             dy;

    SDL_Rect        hitbox;
    Sprite          *sprite;
    Layers          layer;
    Entity_Type     ent_type;
} Entity;
extern Entity player;

typedef struct
{
    //Entity 0 is always player
    int             entity_count;
    Entity          entities_pool[ENTITIES_MAX];
}Stage;
extern Stage stage;


/*
typedef struct
{
    int red;
    int green;
    int blue;
    int alpha;
} COLOR_RGBA;

const COLOR_RGBA C_BACKGROUND       = { 16, 33, 43, 255 };

const COLOR_RGBA C_ORANGE         = { 170, 100, 77, 255 };
const COLOR_RGBA C_DARK_PURPLE    = { 55, 42, 56, 255 };
const COLOR_RGBA C_GREEN          = { 120, 131, 116, 255 };
const COLOR_RGBA C_BEIGE          = { 245, 233, 191, 255 };
const COLOR_RGBA C_BLUE           = { 91, 118, 141, 255 };
*/

#endif
