#ifndef __GAMEMANAGER__
#define __GAMEMANAGER__
#include <vector>
#include <string>
#include "../main/define.hpp"
#include "../game_map/GameMap.hpp"
#include "../wave/Wave.hpp"
#include "../RSDL-master/src/rsdl.hpp"
#include "../enemy/Enemy.hpp"
#include "../towers/Tower.hpp"
#include "../towers/Gatling.hpp"
#include "../towers/Missiler.hpp"
#include "../towers/Tesla.hpp"
#include "../towers/GlueTower.hpp"

typedef std::vector<std::vector<int>> path_coordinates;
typedef std::vector<std::vector<Block*>> Blocks;
typedef std::vector<Wave> waves;
typedef std::vector<std::vector<Block*>> Blocks;
typedef std::vector<Enemy*> enemy_list;
typedef std::vector<Tower*> tower_list;

class GameManager
{
public:
    GameManager(waves game_waves);
    GameManager(){};
    void set_waves(const waves& game_waves_);
    void delete_map();
    enemy_list generate_wave(Wave wave);
    enemy_list generate_type(enemy_list& list_of_enemies, Type type, int count);
    Tower* find_tower_in_blocks(Block* block);
    void delete_enemy_list();
    void delete_tower_list();
    void delete_tower_bullets();
    void release_all_alloc_memory();
    void release_alloc_memory_between_rounds();
    void update_towers();
    void damage_user_if_necessary(Enemy* enemy);
    void update_enemies();
    void handle_events();
    void handle_click_event();
    void handle_key_pressed_event(char pressed_key);
    void handle_construct_tower_process(char pressed_key);
    void construct_tower_based_on_pressed_key(char pressed_key);
    void collect_bounties();
    void update();
    void set_up_background();
    void draw_enemies();
    void draw_towers();
    void draw_path();
    void draw();
    void generate_enemy_if_enough_time_passed();
    void wait_between_waves_for_some_time();
    void process_event(Event event);
    bool time_elapsed_reached(float time_milliseconds);
    bool game_is_over();
    bool current_wave_going_on();
    bool enemy_exists_on_the_field();
    bool bounty_collectable(Enemy* enemy);
    bool free_for_construction();
    bool able_to_upgrade(char pressed_key);
    bool occupied_by_path();
    bool tower_is_in_block (Point tower_center, Block* block);
    bool its_time_to_make_enemy();
    void upgrade_selected_tower(Tower* tower);
    void handle_upgrade_tower(Tower* tower);
    void show_texts_on_screen();
    void show_health();
    void show_current_wave();
    void show_coins();
    void show_massage();
    void update_and_draw();
    void go_to_next_wave();
    void run_current_wave();
    void run_current_wave_while_it_isnt_over();
    void run();
    void broadcast_enemy_list_to_towers();
    void construct_new_tower(Tower* new_tower);
    void show_results();
    void show_win();
    void show_lose();
    void play_right_music();

private:
    GameMap map;
    Window* win;
    waves game_waves;
    Wave current_wave;
    enemy_list enemies;
    tower_list towers;
    path_coordinates game_path;
    std::string background_path = BACKGROUND_PATH;
    int tick_counter = 0;
    int current_wave_number = 1;
    int user_health = USER_INIT_HEALTH;
    int user_coins = USER_INIT_COINS;
    bool game_over = false;
    Block* user_clicked_block = NULL;
    std::string massage_shown = DEFUALT_MASSAGE;
    std::vector<Point> milestones;

    Point get_milestone(const std::vector<int>& coordinate);
    std::vector<Point> convert_to_milestones();
    void set_milestones();

    
};
#endif