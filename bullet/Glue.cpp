#include "Glue.hpp"
using namespace std;

Glue::Glue(float initial_x, float initial_y, Enemy* target_, int tower_level_,
        const vector<Enemy*>& enemies_)
:Bullet(initial_x, initial_y, target_, GREEN, tower_level_, enemies_)
{
    damage = NO_DAMAGE;
    set_effects();
}

void Glue::draw(Window* win)
{
    if (visible == true)
    {
        win -> draw_img(GLUE_BULLET_PIC_PATH, get_box());
    }
}

void Glue::act_upon_target()
{
    for (Enemy* enemy:enemies)
    {
        act_upon_targets_if_in_range(enemy);
    }
    
    return;
}

void Glue::act_upon_targets_if_in_range(Enemy* enemy)
{
    if (enemy_in_range(enemy))
    {
        decrease_speed_if_necessary(enemy);
    }    
}

bool Glue::enemy_in_range(Enemy* enemy)
{
    return (dist(center, enemy -> get_pos()) <= GLUE_SPLASH_RADI);
}

void Glue::decrease_speed_if_necessary(Enemy* enemy)
{
    if ((enemy -> get_should_be_slowed_flag() == false) && (enemy -> get_type() != stubborn_runner))
    {
        enemy -> decrease_speed_ms(bullet_effect_intensity, bullet_effect_period);
    }
    enemy -> set_should_be_slowed_flag_to_true();
    enemy -> set_tick_counter_to_zero();
}


void Glue::set_effects()
{
    bullet_effect_period = GLUE_INIT_EFFECT_PERIOD + (tower_level - 1) * GLUE_INCREASE_EFFECT_PERIOD;
    bullet_effect_intensity = GLUE_INIT_EFFECT_INTENSITY + (tower_level - 1) * GLUE_INCREASE_EFFECT_INTENSITY;
}

