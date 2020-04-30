#include "TeslaStrike.hpp"
using namespace std;

TeslaStrike::TeslaStrike(float initial_x, float initial_y, Enemy* target_, int tower_level_, 
        const std::vector<Enemy*>& enemies_)
:Bullet(initial_x, initial_y, target_, TESLA_STRIKE_COLOR, tower_level_, enemies_)
{
    damage = TESLA_DAMAGE;
    set_effects();
}

bool TeslaStrike::strike_should_be_drawn()
{
    return ((tick_counter * GAME_DELAY <= TESLA_STRIKE_DRAW_PERIOD)
             && should_be_deleted == false);
}
void TeslaStrike::set_flags_to_no_drawing()
{
    tick_counter = 0;
    should_increase_tick = false;
}

void TeslaStrike::draw_strikes(Window* win)
{
    vector<Point> strike_points;
    Point enemy_pos = target -> get_pos();
    Point start_pos(tower_pos.x, tower_pos.y - TESLA_TOWER_LENGTH);
    strike_points = make_strike_points(enemy_pos);
    for (Point p:strike_points)
    {
        win -> draw_line (start_pos, p, color);
    }
    return;
    
}

vector<Point> TeslaStrike::make_strike_points(const Point& enemy_pos)
{
    vector<Point> result;
    Point new_point;
    for (int delta_x = -TESLA_STRIKE_DELTA_PIX; delta_x <= TESLA_STRIKE_DELTA_PIX; delta_x += 2 * TESLA_STRIKE_DELTA_PIX)
    {
        for (int delta_y = -TESLA_STRIKE_DELTA_PIX; delta_y <= TESLA_STRIKE_DELTA_PIX; delta_y +=2 * TESLA_STRIKE_DELTA_PIX)
        {
            new_point = Point(enemy_pos.x + delta_x, enemy_pos.y + delta_y);
            result.push_back(new_point);
        }
    }
    return result;
}

void TeslaStrike::draw(Window* win)
{
    if (strike_should_be_drawn())
    {
        draw_strikes(win);
    }
    else
        set_flags_to_no_drawing();
}

void TeslaStrike::act_upon_target()
{
    target -> deal_damge(damage);
    damage = NO_DAMAGE;
    should_increase_tick = true;
    return;
}

void TeslaStrike::set_effects()
{
    damage = TESLA_DAMAGE + TESLA_INCREASE_BULLET_DAMAGE * (tower_level - 1);
}
