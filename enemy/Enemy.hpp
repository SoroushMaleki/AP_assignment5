#ifndef __ENEMY__
#define __ENEMY__

#include <string>
#include <vector>
#include "../main/define.hpp"
#include "../RSDL-master/src/rsdl.hpp"


typedef int Type;
typedef std::vector<std::vector<int>> path_coordinates;

class Enemy
{
public:
    Enemy(Type enemy_type, const path_coordinates& path_ );
    int get_health() {return (health - damage_taken);}
    float get_speed() {return speed;}
    int get_damage() {return damage;}
    int get_bounty() {return bounty;}
    int get_type() {return type;}
    Rectangle get_box();                                          
    Point get_pos() {return center;}
    void deal_damge(int damage) {damage_taken += damage;}
    void decrease_speed_ms(double decrease_percentage, float millisoconds);
    void set_speed_back_to_normal(); 
    void set_damage(int new_damage) {damage = new_damage;}
    void set_properties();
    void set_pos(double x, double y);
    void set_health(int health_) {health = health_;}
    void move_towards_target();
    void update();
    void draw(Window* win);
    void draw_health_bar(Window* win);
    void set_should_be_slowed_flag_to_true() {should_be_slowed = true;}
    void set_tick_counter_to_zero() {tick_counter = 0;}
    void set_bounty_collected() {bounty_collected = true;}
    bool is_alive();
    bool has_reached(const Point& p);
    bool get_reached_dest_flag() {return reached_dest;}
    bool get_should_be_slowed_flag() {return should_be_slowed;}
    bool get_should_be_deleted_flag() {return should_be_deleted;}
    bool get_bounty_collected_flag() {return bounty_collected;}
    

    Enemy* get_add() {return this;}
    int get_damage_taked() {return damage_taken;}
    void fix_scrambler();


private:
    Type type;
    float health;
    double speed;
    int damage;
    int bounty;
    int tick_counter;
    float slowed_duration;
    path_coordinates path;
    std::vector<Point> milestones;

    Point center;
    double center_x;
    double center_y;
    Point target;
    int current_target_index;
    Point destination;
    std::string image_name;

    bool visible = false;
    bool reached_dest = false;
    bool should_be_deleted = false;
    bool should_be_slowed = false;
    bool bounty_collected = false;


    Point get_milestone(const std::vector<int>& coordinate);
    std::vector<Point> convert_to_milestones();
    void set_milestones();
    void set_target(const Point& new_target) {target = new_target;}
    void initiate_pos();
    float dist(const Point& p1, const Point& p2);


    int damage_taken = 0;


};



#endif