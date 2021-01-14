#include "Block.h"
#include <stdlib.h>
Block::Block(int x, int y, BlockType type, ALLEGRO_BITMAP *img, ALLEGRO_BITMAP *torch_img, bool have_torch)
{
    pos_x = x;
    pos_y = y;
    this->type = type;
    this->img = img;
    switch (type)
    {
    case BACKGROUND:
    case ROAD:
    case DOOR:
        level = 0;
        break;
    case WALL:
    case SHOP:
    case SHOP_FLAG:
    case GOAL:
        level = 100;
        break;
    case BREAKABLE_ONE:
        level = 1;
        break;
    case BREAKABLE_TWO:
        level = 2;
        break;
    default:
        break;
    }
    torch_in_wall = torch_img;
    cur_action = 0;
    beat_cnt = 0;
    tempo = 2;
    beat_of_change = (BEAT_PER_TEMPO*tempo)/num_action;
    num_action = 4;
    this->have_torch = have_torch;
}

void Block::draw() {
    if(type != BlockType::BACKGROUND) {
        if(type != BlockType::DOOR) {
            al_draw_tinted_scaled_bitmap(img, al_map_rgba_f(0.5, 0.5, 0.5, 1), 0, 0, GRID_SIZE, GRID_SIZE + GRID_OFFSET, pos_x, pos_y, GRID_SIZE, GRID_SIZE + GRID_OFFSET, 0);
            // draw torch
            if(type != BlockType::ROAD && type != BlockType::SHOP_FLAG) {
                if(have_torch) al_draw_tinted_scaled_bitmap(torch_in_wall, al_map_rgba_f(0.5, 0.5, 0.5, 1), 0 + 12 * cur_action, 0, TORCH_SIZE, GRID_SIZE, pos_x + TORCH_OFFSET, pos_y - GRID_OFFSET / 2, TORCH_SIZE, GRID_SIZE, 0);
            }
        }
        else
        { // if door, put floor first then put door
            al_draw_tinted_scaled_bitmap(al_load_bitmap("assets/block/boss_floor_A.png"), al_map_rgba_f(0.5, 0.5, 0.5, 1), 0, 0, GRID_SIZE, GRID_SIZE, pos_x, pos_y, GRID_SIZE, GRID_SIZE, 0);
            al_draw_tinted_scaled_bitmap(img, al_map_rgba_f(0.5, 0.5, 0.5, 1), 0, 0, GRID_SIZE, GRID_SIZE + GRID_OFFSET, pos_x, pos_y, GRID_SIZE, GRID_SIZE + GRID_OFFSET, 0);
        }
    }
    
}

void Block::draw_shovel() {
    // draw shovel
    if(is_shovel) {
        al_draw_scaled_bitmap(shovel_img, 0, 0, GRID_SIZE, GRID_SIZE, pos_x, pos_y, GRID_SIZE, GRID_SIZE, 0);
        is_shovel = false;
    }
}

int Block::get_level()
{
    return level;
}
void Block::pass_beat()
{
    beat_cnt++;
    if (beat_cnt == beat_of_change)
    {
        change_animation();
        beat_cnt = 0;
    }
}
void Block::change_animation()
{
    cur_action = cur_action + 1;
    if (cur_action == num_action) cur_action = 0;
}
void Block::delete_wall(ALLEGRO_BITMAP* shovel_img)
{
    img = al_load_bitmap("assets/block/boss_floor_A.png");
    this->shovel_img = shovel_img;
    is_shovel = true;
    type = BlockType::ROAD;
    pos_y += GRID_OFFSET;
}