#ifndef __TESLASTRIKE__
#define __TESLASTRIKE__

#include <vector>
#include "Bullet.hpp"
#include "../enemy/Enemy.hpp"
#include "../main/define.hpp"
#include "../RSDL-master/src/rsdl.hpp"


class TeslaStrike : public Bullet
{
public:
    TeslaStrike(float initial_x, float initial_y, Enemy* target_, int tower_level_,
             const std::vector<Enemy*>& enemies_);
    void draw(Window* win);
    void set_effects();
    void act_upon_target();
    void set_flags_to_no_drawing();
    void draw_strikes(Window* win);
    std::vector<Point> make_strike_points(const Point& enemy_pos);
    bool strike_should_be_drawn();
private:
    int damage = TESLA_DAMAGE;
    int radius = 10;
    
};

#endif