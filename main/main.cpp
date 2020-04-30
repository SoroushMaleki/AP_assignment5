#include <iostream>
#include <cstdlib>
#include <ctime>
#include "define.hpp"
#include "../RSDL-master/src/rsdl.hpp"
#include "../master_class/FieldRunners.hpp"
#include "../Block/Block.hpp"
#include "../game_map/GameMap.hpp"
#include "../game_manager/GameManager.hpp"
#include "../enemy/Enemy.hpp"
#include "../towers/Tower.hpp"
#include "../towers/Gatling.hpp"
#include "../towers/Tesla.hpp"
#include "../towers/GlueTower.hpp"
#include "../bullet/Bullet.hpp"
#include "../bullet/SimpleBullet.hpp"
#include "../bullet/AreaSplash.hpp"
#include "../bullet/TeslaStrike.hpp"
#include "../wave/Wave.hpp"


using namespace std;

int main (int argc, char* argv[])
{
    srand((unsigned) time(0));
    FieldRunners game;
    return 0;    
}