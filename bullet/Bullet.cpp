#include "Bullet.hpp"
using namespace std;


Bullet::Bullet(float initial_x, float initial_y, Enemy* target_, RGB color_, int tower_level_,
            const std::vector<Enemy*>& enemies_)
{
    set_pos(initial_x, initial_y);
    tower_pos = Point(initial_x, initial_y);
    target = target_;
    color = color_;
    visible = true;
    tower_level = tower_level_;
    enemies = enemies_;
}

float Bullet::dist(const Point& p1, const Point& p2)
{
    float result = sqrt(((float)pow((p1.x-p2.x),2))+((float)pow((p1.y-p2.y),2)));
	return result;
}

void Bullet::set_pos(float x, float y)
{
    center.x = x;
    center.y = y;
}

void Bullet::move_towards_target()
{
	float new_x;
	float new_y;
    Point target_pos = target -> get_pos();
	float distance = dist(center, target_pos);
    new_x = (float)center.x + (float)(target_pos.x - center.x)/(distance) * speed * GAME_DELAY / MILLIS_TO_SECS;
    new_y = (float)center.y + (float)(target_pos.y - center.y)/(distance) * speed * GAME_DELAY / MILLIS_TO_SECS;
    set_pos(new_x, new_y);
    return;
}

bool Bullet::has_reached()
{
    if (dist(center, target -> get_pos()) <= REACHED_DISTANCE)
    {
        reached_target = true;
        return true;
    }
    else
    {
        return false;
    }
}

bool Bullet::target_not_exist()
{
    return (target -> is_alive() == false) || (target -> get_reached_dest_flag() == true);
}

void Bullet::update()
{
    if (target_not_exist())
    {
        should_be_deleted = true;
        visible = false;
        return;
    }
    if (has_reached())
    {
        visible = false;
        reached_target = true;
        should_be_deleted = true;
        act_upon_target();
        return;
    }
    move_towards_target();

    return;
}

Rectangle Bullet::get_box()
{
    Point top_left(center.x - BULLET_SIZE, center.y - BULLET_SIZE);
    Point bottom_right(center.x + BULLET_SIZE, center.y + BULLET_SIZE );
    Rectangle box(top_left, bottom_right);
    return box;
}






