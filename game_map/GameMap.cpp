#include "GameMap.hpp"
using namespace std;


GameMap::GameMap()
{
    game_blocks = construct_blocks();
}

Blocks GameMap::construct_blocks()
{
    Blocks blocks;
    for (int row_number = 0 ; row_number < NUM_OF_ROW_BLOCK ; row_number++)
    {
        vector<Block*> new_row;
        for (int col_number = 0 ; col_number < NUM_OF_COL_BLOCKS ; col_number++)
        {
            Block* new_block = new Block(col_number, row_number);
            new_row.push_back(new_block);
        }
        blocks.push_back(new_row);
    }
    return blocks;
}

Block* GameMap::find_block_by_a_point_in_it(Point p)
{
    for (int row_number = 0 ; row_number < NUM_OF_ROW_BLOCK ; row_number++)
    {
        for (int col_number = 0 ; col_number < NUM_OF_COL_BLOCKS ; col_number++)
        {
            if (game_blocks[row_number][col_number] -> contains(p))
                return game_blocks[row_number][col_number];
        }
    }
    return NULL;
}

void GameMap::mark_path_as_ocupied(const path_coordinates& game_path)
{
    for (int block_number = 0 ; block_number < game_path.size() ; block_number++)
    {
        mark_block_as_ocupied_by_path(game_path[block_number][ROW_INDEX], game_path[block_number][COL_INDEX]);
    }
    return;
}

void GameMap::mark_block_as_ocupied_by_path(int row_number, int col_number)
{
    game_blocks[col_number][row_number] -> mark_as_ocupied_by_path();
    return;
}