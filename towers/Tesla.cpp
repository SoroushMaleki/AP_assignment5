#include "Tesla.hpp"
using namespace std;

Tesla::Tesla(Block* position_, const vector<Enemy*>& enemies_)
:Tower(TESLA_PRICE_BUILT, TESLA_PRIEC_UPGRADE, TESLA_SHOOT_INTERVAL,
            position_,
            enemies_,
            TESLA_PIC_NAMES,
            TESLA_PIC_DIMENTIONS)
{
    position = position_;
}

void Tesla::make_bullet_if_necessary()
{
    if (has_to_shoot == true && has_target == true)
    {
        Bullet* new_bullet = new TeslaStrike(center.x, center.y, target, level, enemies);
        bullets.push_back(new_bullet);
    }
    return;
}

void Tesla::increase_bullet_effects()
{
    damage += TESLA_INCREASE_BULLET_DAMAGE;
}
