#ifndef __TESLA__
#define __TESLA__

#include "Tower.hpp"
#include "../Block/Block.hpp"
#include "../enemy/Enemy.hpp"
#include "../main/define.hpp"
#include "../bullet/Bullet.hpp"
#include "../bullet/TeslaStrike.hpp"

class Tesla : public Tower
{
public:
    Tesla(Block* position_, const std::vector<Enemy*>& enemies_);
    void make_bullet_if_necessary();
    void increase_bullet_effects();
private:
    int damage = TESLA_DAMAGE;
};

#endif