#ifndef __MISSLER__
#define __MISSLER__

#include "Tower.hpp"
#include "../Block/Block.hpp"
#include "../enemy/Enemy.hpp"
#include "../main/define.hpp"
#include "../bullet/Bullet.hpp"
#include "../bullet/AreaSplash.hpp"

class Missiler : public Tower
{
public:
    Missiler(Block* position_, const std::vector<Enemy*>& enemies_);
    void make_bullet_if_necessary();
    void increase_bullet_effects();
private:
    int damage = MISS_DAMAGE;
};

#endif