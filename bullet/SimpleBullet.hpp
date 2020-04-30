#ifndef __SIMPLEBULLET__
#define __SIMPLEBULLET__

#include "Bullet.hpp"
#include "../enemy/Enemy.hpp"
#include "../main/define.hpp"
#include "../RSDL-master/src/rsdl.hpp"

class SimpleBullet : public Bullet
{
public:
    SimpleBullet(float initial_x, float initial_y, Enemy* target_, int tower_level_,
             const std::vector<Enemy*>& enemies_);
    void draw(Window* win);
    void set_effects();
    void act_upon_target();
private:
    int damage = GAT_DAMAGE;
    int radius = 10;
};






#endif