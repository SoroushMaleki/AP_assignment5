#ifndef __TOWER__
#define __TOWER__

#include "../RSDL-master/src/rsdl.hpp"
#include "../enemy/Enemy.hpp"
#include "../Block/Block.hpp"
#include "../main/define.hpp"
#include "../bullet/Bullet.hpp"


class Tower
{
public:
    Tower(int price_built_, int price_upgrade_, int shoot_interval_ms_,
            Block* position_,
            const std::vector<Enemy*>& enemies_,
            const std::vector<std::string>& picture_names_,
            const std::vector<std::vector<int>>& picture_dimentions_);
    int get_price_build() {return price_built;}
    int get_price_upgrade() {return price_upgrade;}
    int get_level() {return level;}
    void increment_tick_counter() {tick_counter++;}
    void set_counter_to_zero() {tick_counter = 0;}
    void update_has_to_shoot_flag();
    void alter_has_to_shoot_flag();
    void update_has_target_flag();
    void delete_bullet_list();
    virtual void increase_bullet_effects() = 0;
    void set_pic();
    Enemy* find_target(std::vector<Enemy*> enemies);
    float calc_dist_from_enemy(Enemy* enemy);
    bool target_not_in_range();
    bool able_to_find_target();
    void set_target();
    void upgrade_tower();
    void delete_done_bullets();
    void update_bullets();
    void update();
    virtual void make_bullet_if_necessary() = 0;
    
    Point get_center() {return (position -> get_center());}
    Rectangle get_box();
    void draw(Window* win);
    void draw_bullets(Window* win);
    void set_picture_based_on_level();
    void set_enemies(const std::vector<Enemy*>& enemies_) {enemies = enemies_;}

protected:
    int price_built;
    int price_upgrade;
    int tick_counter;
    int shoot_interval_ms;
    int range_of_attack_pixles;
    int level;
    bool has_to_shoot;
    bool has_target;


    Enemy* target = NULL;
    Block* position;
    std::vector<Bullet*> bullets;
    Point center;
    int pic_width_pixle;
    int pic_hight_pixle;
    std::string current_picture;
    std::vector<std::vector<int>> picture_dimentions;
    std::vector<std::string> picture_names;
    std::vector<Enemy*> enemies;
};














#endif