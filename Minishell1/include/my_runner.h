/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** .h
*/

#ifndef MY_RUNNER_H
#define MY_RUNNER_H
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/sysmacros.h>
#include <fcntl.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>
#include <SFML/System/Time.h>
#define MAX_SIZE 4096
#define RECT_LIFE ((sfIntRect){901/3, 0, 901/3, 300})
#define RECT_LIFE_TW ((sfIntRect){901/3 + 300, 0, 901/3, 300})
#define BLOOD_RECT ((sfVector2f){60, -500})
#define RECT_PARR ((sfIntRect){0,0, 4096, 1546})
#define BACK_SONG ("ressources/sound/background.ogg")
#define SPRITE_T ("ressources/play.png")
#define SPRITE_T_TWO ("ressources/exit.png")
#define SPRITE_T_THREE ("ressources/play_touch.png")
#define BACKGROUND_MENU ("ressources/back_menu.png")
#define EXIT_BUTTON ("ressources/exit_touch.png")
#define PATH_SONG_BACK ("ressources/sound/background.ogg")

typedef enum font {
    BACKGROUND,
    MIDDLE,
    FRONT,
    RUN,
    TREE
} type_t;

typedef struct p_assets_s {
    int speed_x;
    int dead;
    int life;
    int speed_reactor_up;
    int speed_reactor_down;
    sfSprite *life_sprite;
    sfTexture *life_texture;
    sfText *life_player;
    sfFont *font;
    sfMusic *background_sound;
    sfMusic *obstacle;
    sfMusic *stop_fly;
} p_assets_t;

typedef struct d_s {
    sfRenderWindow *window;
    sfEvent event;
    sfIntRect rect;
    sfIntRect rect_player;
    sfTime time;
    sfClock *clock;
    sfTexture *blood;
    sfTexture *texture_mission;
    sfSprite *blood_obstacle;
    sfSprite *mission;
    sfClock *clock_since_zero;
    sfTime time_since_zero;
    sfText *time_since_begin;
    sfText *show_second;
    float seconds_s_z;
    sfFont *font;
} d_t;

typedef struct game_object_s {
    const char *path_to_spritesheet;
    sfVector2f pos;
    sfIntRect rect;
    sfTexture *my_texture;
    sfSprite *my_sprite;
    sfVector2f my_pos;
    sfIntRect my_rect;
    type_t type;
} game_object_t;

typedef struct my_obstacle_s {
    const char *path;
    sfVector2f pos;
    sfTexture *my_texture;
    sfSprite *my_sprite;
    sfIntRect my_rect;
    type_t type_obstacle;
} my_obstacle_t;

typedef struct b_s {
    int tmp;
    int offset_player;
    float seconds;
    int width_image;
    int heigh_image;
    char *map;
    int number_of_enemy;
    int **stock_enemy;
    int speed_parralax;
    int size;
    int enemy_begin;
    int notify;
    int check_notify;
    int mission;
    int check_mission;
    int level;
    int move_enemy;
    sfFont *font;
    sfText *count_metter;
    sfText *level_show;
    sfTexture *level_texture;
    sfTexture *metter_texture;
    sfSprite *show_level;
    sfSprite *show_metter;
    sfSprite *line;
    sfSprite *line_right;
    sfTexture *line_texture;
    sfSprite *pause_game;
    sfTexture *pause_texture;
    sfTexture *pause_in_game;
} b_t;

typedef struct public_class_s {
    p_assets_t *player;
    d_t *csfml_object;
    game_object_t **my_object;
    game_object_t **my_pers;
    b_t *var;
    my_obstacle_t **enemy;
} public_class_t;

typedef struct menu_s {
    int play;
    sfSprite *background;
    sfTexture *back;
    sfSprite *play_sprite;
    sfTexture *play_texture;
    sfSprite *exit;
    sfTexture *exit_texture;
    sfTexture *exit_touch;
    sfTexture *play_touch;
    sfTexture *play_sprite_touch;
    sfTexture *play_sprite_texture;
} menu_t;

sfRenderWindow	*my_window_create();
void draw_display(public_class_t *);
void fill_divers(d_t *);
void poll_event(d_t *);
void time_clock(d_t *, b_t *, int);
void move_rect(public_class_t *);
void add_type(game_object_t **);
void fill_object(game_object_t **);
game_object_t *create_object(const char *, sfVector2f, sfIntRect);
void fill_var(b_t *);
void jump(int *, int *);
game_object_t **collider_box(game_object_t **my_pers);
void fill_assets_player(p_assets_t *);
void collider_level(public_class_t *);
void player_glide(public_class_t *, int);
void player_fly_up(public_class_t *, int);
void player_fly_down(public_class_t *, int);
void player_walk(public_class_t *, int);
void init_rect(public_class_t *);
void destroy_sprite(public_class_t *);
void destroy_texture(public_class_t *);
void destroy_clock(public_class_t *);
void destroy_window(public_class_t *);
void destroy_all(public_class_t *);
void free_all(public_class_t *);
void malloc_struct_all(public_class_t *);
void fill_all(public_class_t *);
void manage_player(public_class_t *);
void create_player(public_class_t *);
void manage_before_game(public_class_t *);
void fill_enemy(public_class_t *);
my_obstacle_t *create_enemy(const char *, sfVector2f, sfIntRect, sfVector2f);
void notify_obstacles(public_class_t *);
char* my_itoa(int, char *);
void manage_map(public_class_t *);
int my_strlen(char const *);
char *map_read(char *);
int get_count_of_enemy(public_class_t *);
int fs_open_file(char const *);
void assign_w_h(b_t *);
int fs_open_file(char const *);
int get_count_of_enemy(public_class_t *);
void manage_map(public_class_t *);
sfBool  collider_player_enemy(public_class_t *, int);
void move_enemy(public_class_t *);
void check_if_win(public_class_t *);
void check_if_loose(public_class_t *);
void show_second_scale(public_class_t *);
int menu_begin(menu_t *);
int poll_event_finish(sfEvent, sfRenderWindow *);
void draw_text(public_class_t *all);
void draw_sprite(public_class_t *all);
void draw_object_enemy(public_class_t *all);
void notify_obstacles(public_class_t *all);
void next_notif_obstacles(public_class_t *all, int *i, int *check);
void notify_mission(public_class_t *all);
void next_notify_mission(public_class_t *all, int *i, int *check);
#endif
