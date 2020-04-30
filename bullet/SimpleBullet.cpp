#include "SimpleBullet.hpp"
using namespace std;

SimpleBullet::SimpleBullet(float initial_x, float initial_y, Enemy* target_, int tower_level_, 
        const std::vector<Enemy*>& enemies_)
:Bullet(initial_x, initial_y, target_, RED, tower_level_, enemies_)
{
    damage = GAT_DAMAGE;
    set_effects();
}

void SimpleBullet::draw(Window* win)
{
    if (visible == true)
    {
        win -> draw_img(SIMPLE_BULLET_PIC_PATH, get_box());
    }
}

void SimpleBullet::act_upon_target()
{
    if ((target -> get_type() != stubborn_runner))
    {
        target -> deal_damge(damage);
        damage = NO_DAMAGE;
    } 
    return;
}

void SimpleBullet::set_effects()
{
    damage = GAT_DAMAGE + GAT_INCREASE_BULLET_DAMAGE * (tower_level - 1);
}

