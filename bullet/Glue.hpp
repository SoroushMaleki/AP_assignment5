#ifndef __GLUE__
#define __GLUE__

#include "Bullet.hpp"
#include "../enemy/Enemy.hpp"
#include "../main/define.hpp"
#include "../RSDL-master/src/rsdl.hpp"

class Glue : public Bullet
{
public:
    Glue(float initial_x, float initial_y, Enemy* target_, int tower_level_,
             const std::vector<Enemy*>& enemies_);
    void draw(Window* win);
    void set_effects();
    void act_upon_target();
    void act_upon_targets_if_in_range(Enemy* enemy);
    void decrease_speed_if_necessary(Enemy* enemy);
    bool enemy_in_range(Enemy* enemy);

private:
    int damage = NO_DAMAGE;
    int radius = 20;
    double bullet_effect_period = GLUE_INIT_EFFECT_PERIOD;
    double bullet_effect_intensity = GLUE_INIT_EFFECT_INTENSITY;
};

#endif