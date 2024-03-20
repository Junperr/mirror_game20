#include <SDL2/SDL.h>
#include "main.h"
#include "movement.h"

#ifndef CGAME_MAP_H
#define CGAME_MAP_H

#define MAX_TILES 150
typedef struct Character Character;
typedef struct Collision Collision;
struct Collision {
    SDL_bool up;
    SDL_bool down;
    SDL_bool left;
    SDL_bool right;
    SDL_bool traversableUp;
    SDL_bool traversableDown;
    SDL_bool traversableLeft;
    SDL_bool traversableRight;
};

typedef struct Point Point;
typedef struct Position Position;
struct Position {
    Point left;
    Point center;
    Point right;
};
typedef struct CharHitbox CharHitbox;
struct CharHitbox {
    Position head;
    Position neck;
    Position body;
    Position knee;
    Position feet;
};



typedef struct Tile Tile;
struct Tile {
    int x;
    int y;
    int width;
    int height;
    int type;
    SDL_Texture *texture;
    Collision collision;
    int rotation;

};

typedef struct Map Map;
struct Map {
    int width;
    int height;
    int tile_width;
    int tile_height;
    Tile tiles[MAX_TILES][MAX_TILES];
    int foreground[MAX_TILES][MAX_TILES];
    SDL_bool full;
    int tile_start_x;
    int tile_start_y;
};

Map *create_map(char *path, int tile_width, int tile_height);
void collision(Character *character, Map *map);
void add_right_pattern_to_map(Map *pattern, Map *map);


#endif //CGAME_MAP_H
