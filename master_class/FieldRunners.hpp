#ifndef __FIELDRUNNERS__
#define __FIELDRUNNERS__
#include <vector>
#include <string>
#include <sstream>

#include "../main/define.hpp"
#include "../wave/Wave.hpp"
#include "../RSDL-master/src/rsdl.hpp"
#include "../game_manager/GameManager.hpp"
#include "../wave/Wave.hpp"

typedef std::vector<std::vector<int>> path_coordinates;
typedef std::vector<Wave> waves;

std::vector<int> parse_line( std::string line );


class FieldRunners
{
public:
    FieldRunners();
    path_coordinates read_path_coordinates();
    waves read_waves_descreptions();
    void run();                        



private:
    GameManager manager;
    path_coordinates game_path;
    waves game_waves;
    
};


#endif