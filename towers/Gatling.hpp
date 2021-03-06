#ifndef __GATLING__
#define __GATLING__

#include "Tower.hpp"
#include "../Block/Block.hpp"
#include "../enemy/Enemy.hpp"
#include "../main/define.hpp"
#include "../bullet/Bullet.hpp"
#include "../bullet/SimpleBullet.hpp"

class Gatling : public Tower
{
public:
    Gatling(Block* position_, const std::vector<Enemy*>& enemies_);
    void make_bullet_if_necessary();
    void increase_bullet_effects();
private:
    int damage = GAT_DAMAGE;
};

#endif