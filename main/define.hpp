#ifndef __DEFINE__
#define __DEFINE__

enum types {runner, stubborn_runner, super_trooper, scrambler};
#define GAME_NAME "FieldRunners"
#define NUM_OF_ENEMY_TYPES 4
#define GAME_DELAY 15.0
#define ROW_INDEX 0
#define COL_INDEX 1
#define FONT_DIR "game_manager/OpenSans.ttf"
#define MAIN_MUSIC_PATH "music/MainMusic.mp3"
#define LOSE_MUSIC "music/LoseMusic.mp3"
#define WIN_MUSIC "music/WinMusic.mp3"
#define DEFUALT_MASSAGE "Use your mouse to click on a block in the game"
#define OCCUPIED_BY_PATH_MESSEGE "That palce is occupied by the enemies path."
#define CLICK_INSIDE_GAME_MESSEGE "Please click inside the game."
#define TYPES_OF_TOWERS_MASSAGE "(G) Gatling(55$)    (M) Missler(70$)     (T) Tesla(120$)   (L) GlueTower(60$)"
#define TOWER_CONSTRUCTED_MASSAGE "Tower was constructed successfully."
#define CANT_AFFORD_MASSAGE "You dont have enough coins to built that tower."
#define UPGRADE_SUCCESSFUL_MASSAGE "Upgrade done successfully."
#define CANT_AFFORD_UPGRADE_MASSAGE "Not enough coins to upgrade."
#define TRYING_TO_UPGRADE "Press 'U' to up grade."
#define TOWER_MAXED_OUT_MASSAGE "That tower is already at max level."
#define SHOW_WIN_TEXT "You Won"
#define SHOW_LOSE_TEXT "You Lost"
#define TOWER_MAX_LEVEL 3
#define HEALTH_BAR_MAX_LENGTH 60
#define SHOW_HEALTH_POS Point(100, 70)
#define SHOW_WAVE_POS Point(500, 70)
#define SHOW_COIN_POS Point(1000, 70)
#define SHOW_RESULT_POS Point(300, 300)
#define PATH_COLOR RGB(0, 128, 64)
#define BULLET_SIZE 15
#define FONT_SIZE 30
#define ENEMY_SPAWN_INTERVAL 500.0
#define TIME_BETWEEN_WAVES_INTERVAL 3000.0
#define SHOW_RESULTS_TIME 15000.0
#define NO_DAMAGE 0
#define USER_INIT_HEALTH 20
#define USER_INIT_COINS 200
#define MILLIS_TO_SECS 1000.0
#define RSLD_PATH "../RSDL-master/src/rsdl.hpp"
#define BACKGROUND_PATH "game_manager/background.png"
#define RUNNER_IMAGE "enemy/runner.png"
#define RUNNER_WIDTH 41
#define RUNNER_HIGTH 61
#define SUPER_IMAGE "enemy/supertrooper.png"
#define SUPER_WIDTH 63
#define SUPER_HIGHT 82
#define STUBBORN_IMAGE "enemy/stubborn_runner.png"
#define STUBBORN_WIDTH 53
#define STUBBORN_HIGHT 76
#define SCRAMBLER_IMAGE "enemy/scrambler.png"
#define SCRAMBLER_WIDTH 86
#define SCRAMBLER_HIGHT 62
#define RUNNER_INDEX 0
#define STUBBORN_INDEX 1
#define SUPPER_INDEX 2
#define SCRAMBLER_INDEX 3
#define BLOCK_WIDTH 60
#define BLOCK_HIGHT 60
#define FIRST_BLOCK_X_PIX 121
#define FIRST_BLOCK_Y_PIX 174
#define MAIN_WINDOW_WIDTH_PIX 1365
#define MAIN_WINDOW_HIGHT_PIX 1024
#define NUM_OF_ROW_BLOCK 11
#define NUM_OF_COL_BLOCKS 19
#define SAFE_DISTANCE 0
#define REACHED_DISTANCE 3.0

#define RUNNER_DAMAGE 1
#define RUNNER_INIT_HEALTH 250
#define RUNNER_SPEED 50.0
#define RUNNER_BOUNTY 6

#define STUBBORN_DAMAGE 4
#define STUBBORN_INIT_HEALTH 400
#define STUBBORN_SPEED 30.0
#define STUBBORN_BOUNTY 10

#define SUPER_DAMAGE 4
#define SUPER_INIT_HEALTH 500
#define SUPER_SPEED 25.0
#define SUPER_BOUNTY 8

#define SCRAMBLER_DAMAGE 2
#define SCRAMBLER_INIT_HEALTH 100
#define SCRAMBLER_SPEED 70
#define SCRAMBLER_BOUNTY 4

#define GAT_PRICE_BUILT 55.0
#define GAT_PRIEC_UPGRADE 40.0
#define GAT_DAMAGE 35.0
#define GAT_SHOOT_INTERVAL 1000.0
#define RANGE_OF_ATTACK_PIX 150.0
#define GAT_PIC_NAMES {"towers/gat_pics/gattling1.png", "towers/gat_pics/gattling2.png", "towers/gat_pics/gattling3.png"}
#define GAT_PIC_DIMENTIONS {{116, 117}, {116, 132}, {114, 145}}
#define GAT_INCREASE_BULLET_DAMAGE 35
#define SIMPLE_BULLET_PIC_PATH "bullet/SimpleBullet.png"

#define MISS_PRICE_BUILT 70
#define MISS_PRIEC_UPGRADE 60
#define MISS_DAMAGE 75.0
#define MISS_SHOOT_INTERVAL 3000.0
#define MISS_PIC_NAMES {"towers/missiler_pics/missile1.png", "towers/missiler_pics/missile2.png", "towers/missiler_pics/missile3.png"}
#define MISS_PIC_DIMENTIONS {{103, 102}, {94, 121}, {108, 131}}
#define MISS_INCREASE_BULLET_DAMAGE 75
#define MISS_SPLASH_RADI 50.0
#define AREASPLASH_BULLET_PIC_PATH "bullet/Areasplash.png"

#define TESLA_PRICE_BUILT 120
#define TESLA_PRIEC_UPGRADE 100
#define TESLA_DAMAGE 700.0
#define TESLA_SHOOT_INTERVAL 1500.0
#define TESLA_PIC_NAMES {"towers/tesla_pics/tesla1.png", "towers/tesla_pics/tesla2.png", "towers/tesla_pics/tesla3.png"}
#define TESLA_PIC_DIMENTIONS {{66, 122}, {68, 125}, {73, 162}}
#define TESLA_INCREASE_BULLET_DAMAGE 1000
#define TESLA_STRIKE_DRAW_PERIOD 500
#define TESLA_STRIKE_DELTA_PIX 3
#define TESLA_TOWER_LENGTH 60
#define TESLA_STRIKE_COLOR RGB(0, 151, 151)



#define GLUE_PRICE_BUILT 60
#define GLUE_PRIEC_UPGRADE 40
#define GLUE_SHOOT_INTERVAL 2000.0
#define GLUE_PIC_NAMES {"towers/glue_pics/glue1.png", "towers/glue_pics/glue2.png", "towers/glue_pics/glue3.png"}
#define GLUE_PIC_DIMENTIONS {{103, 102}, {94, 121}, {108, 131}}
#define GLUE_INIT_EFFECT_INTENSITY 0.40
#define GLUE_INCREASE_EFFECT_INTENSITY 0.10
#define GLUE_INIT_EFFECT_PERIOD 2500.0
#define GLUE_INCREASE_EFFECT_PERIOD 500
#define GLUE_SPLASH_RADI 50.0
#define GLUE_BULLET_PIC_PATH "bullet/Glue.png"





#define WIDTH_INDEX 0   
#define HIGHT_INDEX 1


#endif