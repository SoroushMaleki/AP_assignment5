#include "Block.hpp"
using namespace std;

Block::Block(int x_number_ , int y_number_ )
:top_left(FIRST_BLOCK_X_PIX + x_number_ * BLOCK_WIDTH
                    ,FIRST_BLOCK_Y_PIX + y_number_ * BLOCK_HIGHT)
{
    x_number = x_number_;
    y_number = y_number_;
    
}

Rectangle Block::get_box()
{
    Point buttom_right = Point(top_left.x + BLOCK_WIDTH, top_left.y + BLOCK_HIGHT);
    return Rectangle(top_left, buttom_right);
}

bool Block::contains(Point p)
{
    
    if ((p.x > top_left.x) && (p.x < (top_left.x + BLOCK_WIDTH)) &&
        (p.y > top_left.y) && (p.y < (top_left.y + BLOCK_HIGHT)))
        {
            return true;
        }
    else
        {
            return false;
        }
}

Point Block:: get_center()
{
    Point center(top_left.x + BLOCK_WIDTH / 2, top_left.y + BLOCK_HIGHT / 2);
    return center;    
}