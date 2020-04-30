#include "Missiler.hpp"
using namespace std;

Missiler::Missiler(Block* position_,const vector<Enemy*>& enemies_)
:Tower(MISS_PRICE_BUILT, MISS_PRIEC_UPGRADE, MISS_SHOOT_INTERVAL,
            position_,
            enemies_,
            MISS_PIC_NAMES,
            MISS_PIC_DIMENTIONS)
{
    position = position_;
}

void Missiler::make_bullet_if_necessary()
{
    if (has_to_shoot == true && has_target == true)
    {
        Bullet* new_bullet = new AreaSplash(center.x, center.y, target, level, enemies);
        bullets.push_back(new_bullet);
    }
    return;
}

void Missiler::increase_bullet_effects()
{
    damage += MISS_INCREASE_BULLET_DAMAGE;
    return;
}

