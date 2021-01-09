#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <time.h>
#include <string>
#include "global.h"
#include "Map.h"
#include "Monster.h"
#include "MainCharacter.h"
#include "monsters/GreenSlime.h"
#include "monsters/BlueSlime.h"
#include "monsters/RedBat.h"
#include "monsters/Zombie.h"
#include "Reward.h"
#include "rewards/Coin.h"
#include "TempoHeart.h"
#include "items/Bomb.h"


#define GAME_INIT -1
#define GAME_SETTING 0
#define GAME_SELECT 1
#define GAME_BEGIN 2
#define GAME_CONTINUE 3
#define GAME_FAIL 4
#define GAME_TERMINATE 5
#define GAME_NEXT_LEVEL 6
#define GAME_EXIT 7
 
// clock rate
const float FPS = 60;

// total number of level
const int LevelNum = 4;

// 1 coin every 2 seconds
// const int CoinSpeed = FPS * 2;
// const int Coin_Time_Gain = 1;
using namespace std;
class GameWindow
{
public:
    // constructor
    GameWindow();
    // each process of scene
    void game_init();
    void game_reset();
    void game_play();
    void game_begin();

    int game_run();
    int game_update();

    void show_err_msg(int msg);
    void game_destroy();

    // each drawing scene function
    void draw_running_map();

    // process of updated event
    int process_event();
    // detect if mouse hovers over a rectangle
    bool mouse_hover(int, int, int, int);

    // load imgs
    void load_coin_imgs();
    void load_monster_imgs();
    void load_item_imgs();

public:
    bool initial = true;

private:
    ALLEGRO_BITMAP *icon;
    ALLEGRO_BITMAP *background = NULL;

    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_FONT *font = NULL;
    ALLEGRO_FONT *Medium_font = NULL;
    ALLEGRO_FONT *Large_font = NULL;

    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_EVENT event;
    ALLEGRO_TIMER *refresh_timer = NULL;
    int refresh_cycle = 0;
    ALLEGRO_TIMER *quater_timer = NULL; // 1/4 tempo.
    int beat_cnt = 0; // four tempo count = 1 tempo

    ALLEGRO_SAMPLE *sample = NULL;
    ALLEGRO_SAMPLE_INSTANCE *startSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *clearSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *failSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *backgroundSound = NULL;
    // object's image
    map<int, ALLEGRO_BITMAP*> coin_imgs;
    map<string, ALLEGRO_BITMAP*> monster_imgs;
    map<string, ALLEGRO_BITMAP*> item_imgs;
    // games' character and object
    Map* game_map;
    list<Monster*> monsters;
    MainCharacter* main_character;
    list<Reward*> coins;
    TempoHeart* tempo_heart;
    list<Item*> items;
    
    // utility variable
    int mouse_x, mouse_y;
    bool redraw = false;
    bool mute = false;
};

#endif // MAINWINDOW_H_INCLUDED