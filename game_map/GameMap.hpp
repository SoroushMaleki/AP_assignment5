#ifndef __GAMEMAP__
#define __GAMEMAP__

#include <vector>
#include "../Block/Block.hpp"
#include "../RSDL-master/src/rsdl.hpp"
#include "../main/define.hpp"


typedef std::vector<std::vector<Block*>> Blocks;
typedef std::vector<std::vector<int>> path_coordinates;

class GameMap
{

public:
    GameMap();
    Blocks construct_blocks();
    Blocks get_blocks(){return game_blocks;}
    Block* find_block_by_a_point_in_it(Point p);
    void mark_path_as_ocupied(const path_coordinates& game_path);
    void mark_block_as_ocupied_by_path(int row_number, int col_number);
private:

    Blocks game_blocks;
    int num_of_rows = NUM_OF_ROW_BLOCK;
    int num_of_cols = NUM_OF_COL_BLOCKS;
};
#endif