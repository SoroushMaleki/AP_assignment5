#include "Gatling.hpp"
using namespace std;

Gatling::Gatling(Block* position_, const vector<Enemy*>& enemies_)
:Tower(GAT_PRICE_BUILT, GAT_PRIEC_UPGRADE, GAT_SHOOT_INTERVAL,
            position_,
            enemies_,
            GAT_PIC_NAMES,
            GAT_PIC_DIMENTIONS)
{
    position = position_;
}

void Gatling::make_bullet_if_necessary()
{
    if (has_to_shoot == true && has_target == true)
    {
        Bullet* new_bullet = new SimpleBullet(center.x, center.y, target, level, enemies);
        bullets.push_back(new_bullet);
    }
    return;
}

void Gatling::increase_bullet_effects()
{
    damage += GAT_INCREASE_BULLET_DAMAGE;
}

