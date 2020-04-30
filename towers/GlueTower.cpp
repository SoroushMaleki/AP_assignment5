#include "GlueTower.hpp"
using namespace std;

GlueTower::GlueTower(Block* position_, const vector<Enemy*>& enemies_)
:Tower(GLUE_PRICE_BUILT, GLUE_PRIEC_UPGRADE, GLUE_SHOOT_INTERVAL,
            position_,
            enemies_,
            GLUE_PIC_NAMES,
            GLUE_PIC_DIMENTIONS)
{
    position = position_;
}

void GlueTower::make_bullet_if_necessary()
{
    if (has_to_shoot == true && has_target == true)
    {
        Bullet* new_bullet = new Glue(center.x, center.y, target, level, enemies);
        bullets.push_back(new_bullet);
    }
    return;
}

void GlueTower::increase_bullet_effects()
{
    bullet_effect_period = GLUE_INIT_EFFECT_PERIOD + (level - 1) * GLUE_INCREASE_EFFECT_PERIOD;
    bullet_effect_intensity = GLUE_INIT_EFFECT_INTENSITY + (level - 1) * GLUE_INCREASE_EFFECT_INTENSITY;
}