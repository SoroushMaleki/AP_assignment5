#include "Wave.hpp"
using namespace std;

Wave::Wave(const enemy_numbers& wave_data_, const path_coordinates& game_path_,
            int wave_number_)
{
    wave_data = wave_data_;
    wave_number = wave_number_;
    game_path = game_path_;
    wave_over = false;
}

Enemy* Wave::generate_type(Type type)
{
    Enemy* new_enemy = new Enemy(type, game_path);
    wave_data[type] -= 1 ;
    return new_enemy;
}

Enemy* Wave::generate_random_enemy()
{
    Type random_type = generate_a_random_number();
    Enemy* result = generate_type(random_type);
    set_enemy_health_based_on_wave_number(result);
    return result;
}

int Wave:: generate_a_random_number()
{
    Type random_type;
    while (wave_over == false)
    {
        random_type = rand() % NUM_OF_ENEMY_TYPES;
        if (wave_data[random_type] != 0)
            break;
    }
    return random_type;
}

void Wave::set_enemy_health_based_on_wave_number(Enemy* enemy)
{
    float enemy_health = enemy -> get_health();
    enemy -> set_health((0.9 + 0.1 * wave_number) * enemy_health);
}

bool Wave::get_wave_over_flag()
{
    for (int enemy_number : wave_data)
    {
        if (enemy_number != 0)
            return false;
    }
    wave_over = true;
    return true;
}

