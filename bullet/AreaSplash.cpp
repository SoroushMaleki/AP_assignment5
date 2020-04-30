#include "AreaSplash.hpp"
using namespace std;

AreaSplash::AreaSplash(float initial_x, float initial_y, Enemy* target_, int tower_level_,
        const vector<Enemy*>& enemies_)
:Bullet(initial_x, initial_y, target_, MAGENTA, tower_level_, enemies_)
{
    damage = MISS_DAMAGE;
    set_effects();
}

void AreaSplash::draw(Window* win)
{
    if (visible == true)
    {
        win -> draw_img(AREASPLASH_BULLET_PIC_PATH, get_box());
    }
}

void AreaSplash::act_upon_target()
{
    for (Enemy* enemy:enemies)
    {
        if (dist(center, enemy -> get_pos()) <= MISS_SPLASH_RADI)
        {
            enemy -> deal_damge(damage);
        }
    }
    damage = NO_DAMAGE;
    return;
}

void AreaSplash::set_effects()
{
    damage = MISS_DAMAGE + MISS_INCREASE_BULLET_DAMAGE * (tower_level - 1);
}

