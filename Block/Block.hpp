#ifndef __BLOCK__
#define __BLOCK__

#include "../RSDL-master/src/rsdl.hpp"
#include "../main/define.hpp"


class Block
{

public:
    Block(int x_number_ , int y_number_);
    void mark_as_ocupied_by_path() {ocupied_by_path = true;}
    void mark_as_ocupied_by_tower() {ocupied_by_tower = true;}
    bool is_ocupied_by_path() {return ocupied_by_path;}
    bool is_ocupied_by_tower() {return ocupied_by_tower; }
    int get_x_number() {return x_number;}
    int get_y_number() {return y_number;}
    Point get_top_left() {return top_left;}
    Rectangle get_box();
    Point get_center();
    bool contains(Point p);

private:
    int x_number;
    int y_number;
    Point top_left;
    bool ocupied_by_path = false;
    bool ocupied_by_tower = false;

};


#endif