#include "Enemy.hpp"
using namespace std;



Enemy::Enemy(Type enemy_type, const path_coordinates& path_)
{
    type = enemy_type;
    path = path_;
    visible = true;
    set_properties();
    set_milestones();
    initiate_pos();
}

void Enemy::set_pos(double x, double y)
{
    center_x = x;
    center_y = y;
    center.x = center_x;
    center.y = center_y;
}

void Enemy::set_properties()
{
    switch (type)
    {
    case runner:
        health = RUNNER_INIT_HEALTH;
        speed = RUNNER_SPEED ;
        damage = RUNNER_DAMAGE;
        bounty = RUNNER_BOUNTY;
        image_name = RUNNER_IMAGE;
        break;
    case stubborn_runner:
        health = STUBBORN_INIT_HEALTH;
        speed =  STUBBORN_SPEED;
        damage = STUBBORN_DAMAGE;
        bounty = STUBBORN_BOUNTY;
        image_name = STUBBORN_IMAGE;
        break;
    case super_trooper:
        health = SUPER_INIT_HEALTH;
        speed = SUPER_SPEED; 
        damage = SUPER_DAMAGE;
        bounty = SUPER_BOUNTY;
        image_name = SUPER_IMAGE;
        break;
    case scrambler:
        health = SCRAMBLER_INIT_HEALTH;
        speed = SCRAMBLER_SPEED;
        damage = SCRAMBLER_DAMAGE;
        bounty = SCRAMBLER_BOUNTY;
        image_name = SCRAMBLER_IMAGE;
    }
}

Point Enemy::get_milestone(const vector<int>& coordinate)
{
    int x = FIRST_BLOCK_X_PIX + BLOCK_WIDTH / 2 + coordinate[0] * BLOCK_WIDTH;
    int y = FIRST_BLOCK_Y_PIX + BLOCK_HIGHT / 2 + coordinate[1] * BLOCK_HIGHT;
    return Point(x, y);
}


vector<Point> Enemy::convert_to_milestones()
{
    vector<Point> the_milestones;
    for (vector<int> coordinate: path)
    {
        Point new_milestone = get_milestone(coordinate);
        the_milestones.push_back(new_milestone);
    }
    return the_milestones;
}

void Enemy::set_milestones()
{
    milestones = convert_to_milestones();
}

void Enemy::initiate_pos()
{
    set_pos(milestones[0].x, milestones[0].y);
    current_target_index = 1;
    set_target(milestones[current_target_index]);
    destination = milestones[milestones.size()-1];
}

bool Enemy::is_alive()
{
    if (get_health() > 0) 
        return true;
    else
        return false;
}

Rectangle Enemy::get_box()
{
    Point top_left;
    Point buttom_right;
    switch (type)
    {
    case runner:
        top_left.x = center.x - RUNNER_WIDTH / 2;
        top_left.y = center.y - RUNNER_HIGTH / 2;
        buttom_right.x = center.x + RUNNER_WIDTH / 2;
        buttom_right.y = center.y + RUNNER_HIGTH / 2;
        return Rectangle(top_left, buttom_right);
        break;
    case stubborn_runner:
        top_left.x = center.x - STUBBORN_WIDTH / 2;
        top_left.y = center.y - STUBBORN_HIGHT / 2;
        buttom_right.x = center.x + STUBBORN_WIDTH / 2;
        buttom_right.y = center.y + STUBBORN_HIGHT / 2;
        return Rectangle(top_left, buttom_right);
        break;
    case super_trooper:
        top_left.x = center.x - SUPER_WIDTH / 2;
        top_left.y = center.y - SUPER_HIGHT / 2;
        buttom_right.x = center.x + SUPER_WIDTH / 2;
        buttom_right.y = center.y + SUPER_HIGHT / 2;
        return Rectangle(top_left, buttom_right);
        break;
    case scrambler:
        top_left.x = center.x - SCRAMBLER_WIDTH / 2;
        top_left.y = center.y - SCRAMBLER_HIGHT / 2;
        buttom_right.x = center.x + SCRAMBLER_WIDTH / 2;
        buttom_right.y = center.y + SCRAMBLER_HIGHT / 2;
        return Rectangle(top_left, buttom_right);
        break;
    }

}

float Enemy::dist(const Point& p1, const Point& p2)
{
    float result = sqrt(((float)pow((p1.x-p2.x),2))+((float)pow((p1.y-p2.y),2)));
	return result;
}

bool Enemy::has_reached(const Point& p)
{
    if (dist(center, p) <= SAFE_DISTANCE)
        return true;
    else
        return false;
}

void Enemy::move_towards_target()
{
	float distance = dist(center, target);
    center_x = center_x + (double)(target.x - center.x)/(distance) * speed * GAME_DELAY / MILLIS_TO_SECS;
    center_y = center_y + (double)(target.y - center.y)/(distance) * speed * GAME_DELAY / MILLIS_TO_SECS;
    fix_scrambler();
    set_pos(center_x, center_y);
    return;
}

void Enemy::update()
{

    if (!is_alive())
    {
        visible = false;
        damage = 0;
        should_be_deleted = true;
        return;
    }
    if (has_reached(destination))
    {
        visible = false;
        reached_dest = true;
        should_be_deleted = true;
        return;
    }
    if (has_reached(target))
    {
        current_target_index++;
        target = milestones[current_target_index];
        return;
    }
    if (should_be_slowed == true)
    {
        tick_counter ++;
    }
    if (tick_counter * GAME_DELAY >= slowed_duration)
    {
        set_speed_back_to_normal();
        should_be_slowed = false;
        tick_counter = 0;
    }
    move_towards_target();
    
    return;
}
void Enemy::draw(Window* win)
{
    if (visible == true && should_be_deleted == false)
    {
        Rectangle box = get_box();
        win -> draw_img(image_name, box);
        draw_health_bar(win);
    }
}

void Enemy::draw_health_bar(Window* win)
{
    Point top_left (center.x - 30, center_y + 30);
    int health_bar_length = (get_health()) / health * HEALTH_BAR_MAX_LENGTH;
    Point bottom_right (top_left.x + health_bar_length, center_y + 34);
    Rectangle health_bar(top_left, bottom_right);
    win -> fill_rect(health_bar, RED);
    return;

}

void Enemy::decrease_speed_ms(double decrease_percentage, float millisoconds)
{
    speed = speed * (1 - decrease_percentage);
    slowed_duration = millisoconds;
}

void Enemy::set_speed_back_to_normal()
{
    slowed_duration = 0;
    set_properties();
}

void Enemy::fix_scrambler()
{
    if (type == scrambler)
    {
    float distance = dist(center, target);
    center_x = center_x + ceil((double)(target.x - center.x)/(distance) * speed * GAME_DELAY / MILLIS_TO_SECS) / 5.0;
    center_y = center_y + ceil((double)(target.y - center.y)/(distance) * speed * GAME_DELAY / MILLIS_TO_SECS) / 5.0;
    }
}
