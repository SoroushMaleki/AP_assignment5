CPP_EXEC=g++
CPP_STD=-std=c++11
CPP_FLAGS=-g
RSDL_FLAGS=-l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer
RSDL_DIR= RSDL-master/src/
BLOCK_DIR= Block/
GAMEMAP_DIR= game_map/
GAMEMANAGER_DIR=game_manager/
ENEMY_DIR = enemy/
TOWER_DIR = towers/
BULLET_DIR = bullet/
WAVE_DIR = wave/


CPP=${CPP_EXEC} ${CPP_STD} ${CPP_FLAGS}

all: example.out FieldRunners.out

example.out: warmup/videoCodes.o warmup/rsdl.o
	${CPP} warmup/videoCodes.o warmup/rsdl.o ${RSDL_FLAGS} -o example.out

FieldRunners.out: obj/main.o obj/FieldRunners.o obj/Block.o obj/GameMap.o obj/GameManager.o obj/Enemy.o \
	obj/Tower.o obj/Gatling.o obj/Bullet.o obj/SimpleBullet.o obj/AreaSplash.o obj/Missiler.o warmup/rsdl.o \
	obj/Tesla.o obj/TeslaStrike.o obj/GlueTower.o obj/Glue.o obj/Wave.o
	${CPP} obj/main.o warmup/rsdl.o obj/FieldRunners.o obj/Block.o obj/GameMap.o obj/Enemy.o \
	obj/GameManager.o obj/Tower.o obj/Gatling.o obj/Bullet.o obj/SimpleBullet.o obj/AreaSplash.o \
	obj/Missiler.o obj/Tesla.o obj/TeslaStrike.o obj/GlueTower.o obj/Glue.o obj/Wave.o ${RSDL_FLAGS} -o FieldRunners.out

obj/main.o: main/main.cpp ${RSDL_DIR}rsdl.hpp main/define.hpp master_class/FieldRunners.hpp ${BLOCK_DIR}Block.hpp \
	${GAMEMAP_DIR}GameMap.hpp ${GAMEMANAGER_DIR}GameManager.hpp ${ENEMY_DIR}Enemy.hpp ${TOWER_DIR}Tower.hpp \
	${TOWER_DIR}Gatling.hpp ${BULLET_DIR}SimpleBullet.hpp ${BULLET_DIR}Bullet.hpp ${BULLET_DIR}AreaSplash.hpp \
	${TOWER_DIR}Tesla.hpp ${BULLET_DIR}TeslaStrike.hpp ${TOWER_DIR}GlueTower.hpp ${BULLET_DIR}Glue.hpp ${WAVE_DIR}Wave.hpp
	${CPP} -c main/main.cpp -o obj/main.o 

obj/FieldRunners.o: master_class/FieldRunners.cpp master_class/FieldRunners.hpp ${WAVE_DIR}Wave.hpp main/define.hpp \
	${GAMEMANAGER_DIR}GameManager.hpp
	${CPP} -c master_class/FieldRunners.cpp -o obj/FieldRunners.o

obj/Block.o: ${BLOCK_DIR}Block.cpp ${BLOCK_DIR}Block.hpp ${RSDL_DIR}rsdl.hpp main/define.hpp
	${CPP} -c ${BLOCK_DIR}Block.cpp -o obj/Block.o

obj/GameMap.o: ${GAMEMAP_DIR}GameMap.cpp ${GAMEMAP_DIR}GameMap.hpp ${BLOCK_DIR}Block.hpp main/define.hpp ${RSDL_DIR}rsdl.hpp
	${CPP} -c ${GAMEMAP_DIR}GameMap.cpp -o obj/GameMap.o

obj/GameManager.o: ${GAMEMANAGER_DIR}GameManager.cpp ${GAMEMANAGER_DIR}GameManager.hpp main/define.hpp wave/Wave.hpp \
	${ENEMY_DIR}Enemy.hpp ${TOWER_DIR}Gatling.hpp ${TOWER_DIR}Tower.hpp ${TOWER_DIR}Missiler.hpp ${RSDL_DIR}rsdl.hpp \
	${TOWER_DIR}Tesla.hpp ${TOWER_DIR}GlueTower.hpp
	${CPP} -c ${GAMEMANAGER_DIR}GameManager.cpp -o obj/GameManager.o

obj/Wave.o: ${WAVE_DIR}Wave.cpp ${WAVE_DIR}Wave.hpp ${ENEMY_DIR}Enemy.hpp
	${CPP} -c ${WAVE_DIR}Wave.cpp -o obj/Wave.o

obj/Enemy.o: ${ENEMY_DIR}Enemy.cpp ${ENEMY_DIR}Enemy.hpp main/define.hpp ${TOWER_DIR}Tower.hpp ${RSDL_DIR}rsdl.hpp
	${CPP} -c ${ENEMY_DIR}Enemy.cpp -o obj/Enemy.o

obj/Tower.o: ${TOWER_DIR}Tower.cpp ${TOWER_DIR}Tower.hpp ${ENEMY_DIR}Enemy.hpp main/define.hpp ${BLOCK_DIR}Block.hpp \
	${RSDL_DIR}rsdl.hpp ${BULLET_DIR}Bullet.hpp
	${CPP} -c ${TOWER_DIR}Tower.cpp -o obj/Tower.o

obj/Gatling.o: ${TOWER_DIR}Gatling.cpp ${TOWER_DIR}Gatling.hpp ${TOWER_DIR}Tower.hpp main/define.hpp ${BLOCK_DIR}Block.hpp \
	${ENEMY_DIR}Enemy.hpp ${RSDL_DIR}rsdl.hpp ${BULLET_DIR}Bullet.hpp ${BULLET_DIR}SimpleBullet.hpp
	${CPP} -c ${TOWER_DIR}Gatling.cpp -o obj/Gatling.o

obj/Missiler.o: ${TOWER_DIR}Missiler.cpp ${TOWER_DIR}Missiler.hpp ${TOWER_DIR}Tower.hpp main/define.hpp ${BLOCK_DIR}Block.hpp \
	${ENEMY_DIR}Enemy.hpp ${RSDL_DIR}rsdl.hpp ${BULLET_DIR}Bullet.hpp ${BULLET_DIR}AreaSplash.hpp
	${CPP} -c ${TOWER_DIR}Missiler.cpp -o obj/Missiler.o

obj/Tesla.o: ${TOWER_DIR}Tesla.cpp ${TOWER_DIR}Tesla.hpp ${TOWER_DIR}Tower.hpp main/define.hpp ${BLOCK_DIR}Block.hpp \
	${ENEMY_DIR}Enemy.hpp ${RSDL_DIR}rsdl.hpp ${BULLET_DIR}Bullet.hpp ${BULLET_DIR}TeslaStrike.hpp
	${CPP} -c ${TOWER_DIR}Tesla.cpp -o obj/Tesla.o

obj/GlueTower.o: ${TOWER_DIR}GlueTower.cpp ${TOWER_DIR}GlueTower.hpp ${TOWER_DIR}Tower.hpp main/define.hpp ${BLOCK_DIR}Block.hpp \
	${ENEMY_DIR}Enemy.hpp ${RSDL_DIR}rsdl.hpp ${BULLET_DIR}Bullet.hpp ${BULLET_DIR}Glue.hpp
	${CPP} -c ${TOWER_DIR}GlueTower.cpp -o obj/GlueTower.o

obj/Bullet.o: ${BULLET_DIR}Bullet.cpp ${BULLET_DIR}Bullet.hpp ${ENEMY_DIR}Enemy.hpp main/define.hpp ${RSDL_DIR}rsdl.hpp
	${CPP} -c ${BULLET_DIR}Bullet.cpp -o obj/Bullet.o

obj/SimpleBullet.o: ${BULLET_DIR}SimpleBullet.cpp ${BULLET_DIR}SimpleBullet.hpp ${BULLET_DIR}Bullet.hpp ${ENEMY_DIR}Enemy.hpp \
	main/define.hpp ${RSDL_DIR}rsdl.hpp
	${CPP} -c ${BULLET_DIR}SimpleBullet.cpp -o obj/SimpleBullet.o

obj/AreaSplash.o: ${BULLET_DIR}AreaSplash.cpp ${BULLET_DIR}AreaSplash.hpp ${BULLET_DIR}Bullet.hpp ${ENEMY_DIR}Enemy.hpp \
	main/define.hpp ${RSDL_DIR}rsdl.hpp
	${CPP} -c ${BULLET_DIR}AreaSplash.cpp -o obj/AreaSplash.o

obj/TeslaStrike.o: ${BULLET_DIR}TeslaStrike.cpp ${BULLET_DIR}TeslaStrike.hpp ${BULLET_DIR}Bullet.hpp ${ENEMY_DIR}Enemy.hpp \
	main/define.hpp ${RSDL_DIR}rsdl.hpp
	${CPP} -c ${BULLET_DIR}TeslaStrike.cpp -o obj/TeslaStrike.o

obj/Glue.o: ${BULLET_DIR}Glue.cpp ${BULLET_DIR}Glue.hpp ${BULLET_DIR}Bullet.hpp ${ENEMY_DIR}Enemy.hpp \
	main/define.hpp ${RSDL_DIR}rsdl.hpp
	${CPP} -c ${BULLET_DIR}Glue.cpp -o obj/Glue.o

warmup/videoCodes.o: warmup/videoCodes.cpp ${RSDL_DIR}rsdl.hpp
	${CPP} -c warmup/videoCodes.cpp -o warmup/videoCodes.o

warmup/rsdl.o: ${RSDL_DIR}rsdl.cpp ${RSDL_DIR}rsdl.hpp
	${CPP} -c ${RSDL_DIR}rsdl.cpp -o warmup/rsdl.o

clean:
	rm -r *.o
	rm -r obj/*.o
