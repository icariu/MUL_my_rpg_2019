/*
** EPITECH PROJECT, 2019
** MUL_MY_RPG_2019
** File description:
** MY_RPG
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Vector2.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include <time.h>
#include "my.h"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"
#define ON 1
#define OFF 0
#define M_POS_X sfMouse_getPositionRenderWindow(window).x
#define M_POS_Y sfMouse_getPositionRenderWindow(window).y
#define W_H 600
#define W_L 800

#ifndef MY_RPG_H_
#define MY_RPG_H_

typedef struct {
    sfSprite *spr;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
    sfMusic *music;
    sfClock *clock;
    sfText *text;
}object;

typedef struct mobs {
    sfSprite *spr;
    sfVector2f pos;
    float life;
    sfIntRect rect;
    sfText *txt_life;
}st_player;

typedef struct foe{
    sfSprite *spr;
    sfVector2f pos;
    float life;
    sfIntRect rect;
    sfText *txt_life;
    struct foe *next;
}st_foes;

typedef struct control {
    st_foes *head;
    st_foes *tail;
}control_t;

typedef struct inventory {
    object **items;
    char **items_activation;
}st_inventory;

typedef struct {
    object **button;
    object **back;
    object **menu;
    object **intro;
    object **portal;
    object **overlay;
    st_inventory *inventory;
    st_player *player;
    st_player *princess;
    sfRenderWindow *window;
    sfClock *mobs_clock;
    sfClock *rain_clock;
    control_t *control;
    sfMusic *music;
    sfRectangleShape **rain;
    sfRectangleShape **snow;
    int state;
    int old_state;
    int background_index;
    int xp;
    int difficulty;
    int nb_dial_f;
    int nb_dial_c;
    int win;
}st_scene;

typedef void (*replace_w)(st_scene *, sfRenderWindow *);
typedef void (*replace)(st_scene *, sfRenderWindow *, sfEvent);

//cursor
void cursor(st_scene *scene, sfRenderWindow *window);
//overlay
void overlay(st_scene *scene, sfRenderWindow *window);

//init
int initialise(st_scene *scene);
object *new_sprite(char *text);
sfSprite *player_sprite(char *text);
sfSprite *princess_sprite(char *text);
void init_button(st_scene *scene);
object **generate_obj(st_scene *scene, int pos, object **object, char **);
void init_music(st_scene *scene);
void init_intro(st_scene *scene, int i, char **tab);
void init_portal(st_scene *scene, int i, char **tab);
int init_game(st_scene *scene, char **tab);

//destroy
int destroy(st_scene *scene);

//pointeur
void if_one(st_scene *scene, sfRenderWindow *window, sfEvent event);
void if_two(st_scene *scene, sfRenderWindow *window, sfEvent event);
void if_three(st_scene *scene, sfRenderWindow *window, sfEvent event);
void if_four(st_scene *scene, sfRenderWindow *window, sfEvent event);
void if_five(st_scene *scene, sfRenderWindow *window, sfEvent event);
void if_six(st_scene *scene, sfRenderWindow *window, sfEvent event);
void if_seven(st_scene *scene, sfRenderWindow *window, sfEvent event);
void if_eight(st_scene *scene, sfRenderWindow *window, sfEvent event);
void if_nine(st_scene *scene, sfRenderWindow *window, sfEvent event);
void if_ten(st_scene *scene, sfRenderWindow *window, sfEvent event);
//pointeur_w
void if_one_w(st_scene *scene, sfRenderWindow *window);
void if_two_w(st_scene *scene, sfRenderWindow *window);
void if_three_w(st_scene *scene, sfRenderWindow *window);
void if_four_w(st_scene *scene, sfRenderWindow *window);
void if_five_w(st_scene *scene, sfRenderWindow *window);
void if_six_w(st_scene *scene, sfRenderWindow *window);
void if_eleven(st_scene *scene, sfRenderWindow *window);
void if_twelve(st_scene *scene, sfRenderWindow *window);
void if_thirteen(st_scene *scene, sfRenderWindow *window);

//move
void move_player(st_scene *scene, sfEvent event);
int collision_check(st_player *player, int x, int y, int map);

//dialog
void display_dialog(st_scene *scene, sfVector2f txt, sfVector2f ble, char *);
void first_dialog(sfRenderWindow *window, st_scene *scene);
void craftman_dialog(sfRenderWindow *window, st_scene *scene);
sfText *init_text(char *name, sfVector2f pos, sfColor col, unsigned int);

// menu
void draw_button(st_scene *scene, char *text, sfVector2f tpos, int button);
void main_menu(st_scene *scene, sfRenderWindow *window, sfEvent event);
void button_hover(st_scene *scene, sfVector2f pos, int button, int);
void inventory_menu(st_scene *scene, sfRenderWindow *window, sfEvent event);
void button_back_hover(st_scene *scene, sfVector2f pos, int state_change);
void settings_menu(st_scene *scene, sfRenderWindow *window, sfEvent evt);
void display_intro(st_scene *scene, sfRenderWindow *window);
void display_htp(st_scene *scene, sfRenderWindow *window);
void htp_button_hover(st_scene *scene, sfVector2f pos, int state_change);
void display_pause_menu(st_scene *scene, sfRenderWindow *window);

//generation
char *generate_from_file(char *file);

//sound
void sound_gestion(st_scene *scene);

//shop
void display_shop(st_scene *scene, sfRenderWindow *window, sfEvent, int);

void display_sprite(sfSprite *spr, sfRenderWindow *w, sfVector2f, sfIntRect);
//parameters verification
int verif_params(char *path, int equal, char *arg[]);
int check_folder_exist(void);

//enemies
void init_foes(st_scene *scene, int pos, char **tab);
void move_foes(st_scene *scene);
void display_enemies(st_scene *scene, sfRenderWindow *window);

//display portal
void portal(st_scene *scene, sfRenderWindow *window, sfVector2f pos);

// win
void display_win(st_scene *scene, sfRenderWindow *window);

// particules
sfRectangleShape **particles_gen(int nb, int max_h, int width, char type);
int particles_draw(sfRectangleShape **particles, sfRenderWindow *window,
                    sfClock *clock);
int particles_destroy(sfRectangleShape **particles);

// MY_RPG by alizee.soussan@epitech.eu, paul.fermey@epitech.eu,
// valentin.sene@epitech.eu & theo.poette@epitech.eu

#endif /* !MY_RPG_H_ */