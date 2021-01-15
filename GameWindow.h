#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
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
#include <set>
#include <fstream>
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
#include "monsters/Skeleton.h"
#include "monsters/BlackSkeleton.h"
#include "monsters/StoneGolem.h"
#include "Reward.h"
#include "rewards/Coin.h"
#include "TempoHeart.h"
#include "items/Bomb.h"
#include "items/Shovel.h"
#include "items/Torch.h"
#include "items/Dagger.h"
#include "items/AdvancedShovel.h"
#include "items/AdvancedTorch.h"
#include "items/LongSword.h"
#include "characters/Aria.h"
#include "characters/Cadencce.h"


#define GAME_INIT -1
#define GAME_BEGIN 1
#define GAME_PAUSE 2
#define GAME_OVER 3
#define GAME_RUN 4
#define GAME_EXIT 5
#define GAME_TERMINATE 6
#define GAME_CONTINUE 7
// clock rate
const float FPS = 120;

// total number of level
const int LevelNum = 4;




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
    void load_character_imgs();
    void load_number_imgs();
    void load_heart_imgs();
    void load_other_imgs();

    // 
    void init_object_pos();


public:
    bool initial = true;

private:
    ALLEGRO_BITMAP *icon;

    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_FONT *font = NULL;

    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_EVENT event;
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
    map<string, ALLEGRO_BITMAP*> character_imgs;
    vector<ALLEGRO_BITMAP*> number_imgs;
    map<string, ALLEGRO_BITMAP*> heart_imgs;
    map<string, ALLEGRO_BITMAP*> other_imgs;

    // games' character and object
    Map* game_map;
    list<Monster*> monsters;
    MainCharacter* main_character;
    list<Coin*> coins;
    TempoHeart* tempo_heart;
    list<Item*> items;
    list<Item*> bombing_items;
    
    // utility variable
    int mouse_x, mouse_y;
    bool redraw = false;
    bool mute = false;

    // FBO
    ALLEGRO_BITMAP *tmp_bitmap;

    // record game status
    int game_status = GAME_BEGIN;
};

#endif
