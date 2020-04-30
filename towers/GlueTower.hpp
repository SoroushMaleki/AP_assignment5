#ifndef __GLUETOWER__
#define __GLUETOWER__

#include "Tower.hpp"
#include "../Block/Block.hpp"
#include "../enemy/Enemy.hpp"
#include "../main/define.hpp"
#include "../bullet/Bullet.hpp"
#include "../bullet/Glue.hpp"

class GlueTower : public Tower
{
public:
    GlueTower(Block* position_, const std::vector<Enemy*>& enemies_);
    void make_bullet_if_necessary();
    void increase_bullet_effects();
private:
    int damage = NO_DAMAGE;
    int bullet_effect_period = GLUE_INIT_EFFECT_PERIOD;
    int bullet_effect_intensity = GLUE_INIT_EFFECT_INTENSITY;

    
};

#endif