#include "Tower.hpp"
using namespace std;



Tower::Tower(int price_built_, int price_upgrade_, int shoot_interval_ms_,
        Block* position_,
        const vector<Enemy*>& enemies_,
        const vector<string>& picture_names_,
        const vector<vector<int>>& picture_dimentions_)
        {
            price_built = price_built_;
            price_upgrade = price_upgrade_;
            shoot_interval_ms = shoot_interval_ms_;
            range_of_attack_pixles = RANGE_OF_ATTACK_PIX;
            enemies = enemies_;
            tick_counter = 0;
            level = 1;
            has_to_shoot = false;
            has_target = false;
            position = position_;
            picture_dimentions = picture_dimentions_;
            picture_names = picture_names_;
            center = get_center();
            set_picture_based_on_level();
        }

float dist(const Point& p1, const Point& p2)
{
    float result = sqrt(((float)pow((p1.x-p2.x),2))+((float)pow((p1.y-p2.y),2)));
	return result;
}

void Tower::set_picture_based_on_level()
{
        pic_width_pixle = picture_dimentions[level-1][WIDTH_INDEX];
        pic_hight_pixle = picture_dimentions[level-1][HIGHT_INDEX];
        current_picture = picture_names[level-1];
}

void Tower::upgrade_tower()
{
    level++;
    set_picture_based_on_level();
    increase_bullet_effects();
}

void Tower::alter_has_to_shoot_flag()
{
    if (has_to_shoot == true)
        has_to_shoot = false;
    else
        has_to_shoot = true;
    return;
}

Rectangle Tower:: get_box()
{
    Point top_left;
    Point buttom_right;
    top_left.x = center.x - pic_width_pixle / 2;
    top_left.y = center.y - pic_hight_pixle / 2;
    buttom_right.x = center.x + pic_width_pixle / 2;
    buttom_right.y = center.y + pic_hight_pixle / 2;
    return Rectangle(top_left, buttom_right);
}

void Tower::draw_bullets(Window* win)
{
    for (Bullet* bullet : bullets)
    {
        bullet -> draw(win);
    }
    return;
}

void Tower::draw(Window* win)
{
    win -> draw_img(current_picture, get_box());
    draw_bullets(win);
    return;
}

float Tower::calc_dist_from_enemy(Enemy* enemy)
{
    return dist(center, enemy->get_pos());
}

Enemy* Tower::find_target(std::vector<Enemy*> enemies)
{
    Enemy* new_target = NULL;
    float least_dist = calc_dist_from_enemy(enemies[0]);
    float new_dist = 0;
    for (Enemy* enemy: enemies)
    {
        new_dist = calc_dist_from_enemy(enemy);
        if ((new_dist <= least_dist) && (new_dist <= range_of_attack_pixles)
            && enemy -> is_alive())
        {
            new_target = enemy;
            least_dist = new_dist;
            has_target = true;  
        }
    }
    if (new_target == NULL)
    {
        has_target = false;
    }
    return new_target;

}

bool Tower::target_not_in_range()
{
    if (has_target == false)
        return true;

    if (calc_dist_from_enemy(target) <= range_of_attack_pixles)
        return false;
    else
        return true;
}

void Tower::set_target()
{
    if (able_to_find_target())
    {
        Enemy* new_target = find_target(enemies);
        target = new_target;
    }
    return;
}

bool Tower::able_to_find_target()
{
    return ((has_target == false || target_not_in_range()) && (enemies.size() != 0));
}

void Tower::update_has_to_shoot_flag()
{
    if (tick_counter * GAME_DELAY >= shoot_interval_ms && has_target == true)
    {
        has_to_shoot = true;
        set_counter_to_zero();
    }
    else
        has_to_shoot = false;
    
}

void Tower::update_bullets()
{
    for (Bullet* bullet : bullets)
    {
        if (bullet -> get_should_be_deleted_flag() == false)
        {
            bullet -> update();
        }
        if (bullet -> get_should_increase_tick_flag() == true)
        {
            bullet -> increment_tick_counter();
        }
        if (bullet -> get_should_increase_tick_flag() == false)
        {
            bullet -> set_tick_counter_to_zero();
        }
        
    }
    return;
}

void Tower::update_has_target_flag()
{
    if (has_target == true && (target -> is_alive()))
    {
        has_target = true;
    }
    else
    {
        has_target = false;
    }
    
    return;
}

void Tower::update()
{
    set_target();
    update_has_to_shoot_flag();
    update_has_target_flag();
    make_bullet_if_necessary();
    update_bullets();
    tick_counter++;
}

void Tower::delete_bullet_list()
{
    for (Bullet* bullet:bullets)
    {
        delete bullet;
    }
    bullets.clear();
}









