#ifndef __WAVE__
#define __WAVE__
#include <vector>
#include <cstdlib>
#include <ctime>
#include "../enemy/Enemy.hpp"

typedef std::vector<Enemy*> enemy_list;
typedef std::vector<enemy_list> all_enemies;
typedef std::vector<int> enemy_numbers;
typedef std::vector<std::vector<int>> path_coordinates;



class Wave
{
public:
    Wave(const enemy_numbers& wave_data_ = {}, const path_coordinates& game_path_ = {},
            int wave_number_ = 1);
    Enemy* generate_type(Type type);
    Enemy* generate_random_enemy();
    int generate_a_random_number();
    int get_wave_number() {return wave_number;}
    void set_enemy_health_based_on_wave_number(Enemy* enemy);
    bool get_wave_over_flag();
    path_coordinates get_game_path() {return game_path;}
private:

    int wave_number;
    enemy_numbers wave_data;
    path_coordinates game_path;
    bool wave_over = false;
};




#endif