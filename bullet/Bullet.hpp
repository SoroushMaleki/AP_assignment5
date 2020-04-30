#ifndef __BULLET__
#define __BULLET__

#include "../enemy/Enemy.hpp"
#include "../main/define.hpp"
#include "../RSDL-master/src/rsdl.hpp"

class Bullet
{

public:
    Bullet(float initial_x, float initial_y, Enemy* target_, RGB color_, int tower_level_,
            const std::vector<Enemy*>& enemies_);
    void set_pos(float x, float y);
    void move_towards_target();
    void set_target(Enemy* new_target) {target = new_target;}
    void increment_tick_counter() {tick_counter++;}
    int get_tick_counter() {return tick_counter;}
    void set_tick_counter_to_zero() {tick_counter = 0;}
    bool target_not_exist();
    bool has_reached();
    bool get_should_be_deleted_flag() {return should_be_deleted;}
    bool get_should_increase_tick_flag() {return should_increase_tick;}
    Rectangle get_box();
    virtual void set_effects() = 0;
    virtual void act_upon_target() = 0;
    virtual void draw(Window* win) = 0;
    void update();
    
protected:

    float dist(const Point& p1, const Point& p2);
    float speed = 300;
    int tick_counter = 0;
    bool should_increase_tick = false;
    bool tower_has_target = false;
    bool visible = false;
    RGB color = WHITE;
    bool reached_target = false;
    bool should_be_deleted = false;
    int tower_level;
    std::vector<Enemy*> enemies;
    Point center;
    Point tower_pos;
    Enemy* target = NULL;

};







#endif