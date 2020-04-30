#include "GameManager.hpp"
using namespace std;


GameManager::GameManager(waves game_waves):map()
{
    win = new Window(MAIN_WINDOW_WIDTH_PIX, MAIN_WINDOW_HIGHT_PIX, GAME_NAME);
    set_waves(game_waves);
    game_path = game_waves[0].get_game_path();
    map.mark_path_as_ocupied(game_path);
    win -> play_music(MAIN_MUSIC_PATH);
    set_milestones();
}

void GameManager::set_waves(const waves& game_waves_)
{
    game_waves = game_waves_;
    current_wave = game_waves[0];
    current_wave_number = 1;
}

void GameManager::delete_map()
{
    Blocks game_blocks = map.get_blocks();
    for (int row_number = 0 ; row_number < NUM_OF_ROW_BLOCK ; row_number++)
    {
        for (int col_number = 0 ; col_number < NUM_OF_COL_BLOCKS ; col_number++)
        {
            delete game_blocks[row_number][col_number];
        }
    }
}

void GameManager::delete_enemy_list()
{
    for (Enemy* enemy : enemies)
    {
        delete enemy;
    }
    enemies.clear();
    return;
}

void GameManager::delete_tower_list()
{
    for (Tower* tower : towers)
    {
        tower -> delete_bullet_list();
        delete tower;
    }
    towers.clear();  
    return;  
}

void GameManager::delete_tower_bullets()
{
    for (Tower* tower : towers)
    {
        tower -> delete_bullet_list();
    }
    return;    
}

void GameManager::damage_user_if_necessary(Enemy* enemy)
{
    if (enemy -> get_reached_dest_flag() == true)
    {
        user_health -= (enemy -> get_damage());
        enemy -> set_damage(NO_DAMAGE);
    }
    return;
}

void GameManager::update_enemies()
{
    for (Enemy* enemy : enemies)
    {
        enemy -> update();
        damage_user_if_necessary(enemy);
    }
    return;
}

void GameManager::update_towers()
{
    for (Tower* tower:towers)
    {
        tower -> update();
    }
    return;
}

void GameManager::broadcast_enemy_list_to_towers()
{
    for (Tower* tower:towers)
    {
        tower -> set_enemies(enemies);
    }
}

void GameManager::release_all_alloc_memory()
{
    delete_enemy_list();
    delete_tower_list();
    delete_map();
    delete win;

}

void GameManager::release_alloc_memory_between_rounds()
{
    delete_enemy_list();
    delete_tower_bullets();
    return;
}



void GameManager::handle_events()
{
    while (win -> has_pending_event())
    {
        Event event = win -> poll_for_event();
        process_event(event);
    }  
}

void GameManager::process_event(Event event)
{
    switch (event.get_type()) 
    {
        case Event::EventType::QUIT:
            release_all_alloc_memory();
            exit(0);
            break;

        case Event::EventType::LCLICK:
            handle_click_event();
            break;

        case::Event::EventType::KEY_PRESS:
            char pressed_char = event.get_pressed_key();
            handle_key_pressed_event(pressed_char);
            break;
    }
}

void GameManager::handle_click_event()
{
    Point mouse_position = get_current_mouse_position();
    user_clicked_block = map.find_block_by_a_point_in_it(mouse_position);

    if (occupied_by_path())
    {
        user_clicked_block = NULL;
        massage_shown = OCCUPIED_BY_PATH_MESSEGE ;
        return;
    }
    else if (user_clicked_block == NULL)
    {
        massage_shown = CLICK_INSIDE_GAME_MESSEGE;
        return;
    }
    else if (user_clicked_block -> is_ocupied_by_tower() == false)
    {
        massage_shown = TYPES_OF_TOWERS_MASSAGE;
        return;
    }

    massage_shown = TRYING_TO_UPGRADE;
    return;
}

bool GameManager::occupied_by_path()
{
    return ((user_clicked_block != NULL) &&
            (user_clicked_block -> is_ocupied_by_path()));
}

void GameManager::handle_key_pressed_event(char pressed_key)
{

    handle_construct_tower_process(pressed_key);
    if (able_to_upgrade(pressed_key))
        {
            Tower* tower = find_tower_in_blocks(user_clicked_block);
            handle_upgrade_tower(tower);
        }
    return;
}

void GameManager::handle_upgrade_tower(Tower* tower)
{
    if (tower -> get_level() < TOWER_MAX_LEVEL)
    {
        upgrade_selected_tower(tower);
        return;
    }
    else
    {
        massage_shown = TOWER_MAXED_OUT_MASSAGE;
        return;
    }
}

void GameManager::upgrade_selected_tower(Tower* tower)
{
    int price_upgrade = tower -> get_price_upgrade();
    if ((user_coins - price_upgrade) > 0)
    {
        tower -> upgrade_tower();
        user_coins -= price_upgrade;
        massage_shown = UPGRADE_SUCCESSFUL_MASSAGE;
    }
    else
    {
        massage_shown = CANT_AFFORD_UPGRADE_MASSAGE;
    }
    return;    
}

bool GameManager::able_to_upgrade(char pressed_key)
{
    return ((user_clicked_block != NULL)&&
            (user_clicked_block -> is_ocupied_by_tower() == true)&&
            (pressed_key == 'u'));
}

void GameManager::handle_construct_tower_process(char pressed_key)
{
    if (free_for_construction())
    {
        construct_tower_based_on_pressed_key(pressed_key);
    }
    return;
}

bool GameManager::free_for_construction()
{
    return ((user_clicked_block != NULL) &&
            (user_clicked_block -> is_ocupied_by_tower() == false));
}

void GameManager::construct_tower_based_on_pressed_key(char pressed_key)
{
    Tower* new_tower;
    switch (pressed_key)
    {
        case 'g':
            new_tower = new Gatling(user_clicked_block, enemies);
            construct_new_tower(new_tower);
            break;
        case 't':
            new_tower = new Tesla(user_clicked_block, enemies);
            construct_new_tower(new_tower);
            break;
        case 'm':
            new_tower = new Missiler(user_clicked_block, enemies);
            construct_new_tower(new_tower);
            break;
        case 'l':
            new_tower = new GlueTower(user_clicked_block, enemies);
            construct_new_tower(new_tower);
            break;
    }   
}


Tower* GameManager::find_tower_in_blocks(Block* block)
{
    Point tower_center;
    for (Tower* tower:towers)
    {
        tower_center = tower -> get_center();
        if (tower_is_in_block(tower_center, block))
        {
            return tower;
        }
    }
    return NULL;
}


bool GameManager::tower_is_in_block (Point tower_center, Block* block)
{
    return (block -> contains(tower_center));
}

void GameManager::construct_new_tower(Tower* new_tower)
{
    int price_to_build = new_tower -> get_price_build();
    if ((user_coins - price_to_build) > 0)
    {
        towers.push_back(new_tower);
        user_coins -= price_to_build;
        user_clicked_block -> mark_as_ocupied_by_tower();
        user_clicked_block = NULL;
        massage_shown = TOWER_CONSTRUCTED_MASSAGE;
        return;
    }
    else 
    {
        massage_shown = CANT_AFFORD_MASSAGE;
        return;
    }
}

void GameManager::run()
{
    
    while (game_is_over() == false)
    {
        run_current_wave_while_it_isnt_over();
        go_to_next_wave();
    }
    show_results();
    release_all_alloc_memory();
    return;
}

void GameManager::show_results()
{
    tick_counter = 0;
    play_right_music();
    while (!time_elapsed_reached(SHOW_RESULTS_TIME))
    {
        tick_counter++;
        if (user_health > 0)
            show_win();
        else
            show_lose();
        win -> update_screen();
        handle_events();
        delay(GAME_DELAY);
    }

}

void GameManager::play_right_music()
{
    if (user_health > 0)
        win -> play_music(WIN_MUSIC);
    else
        win -> play_music(LOSE_MUSIC);
    
}

void GameManager::show_win()
{

    win -> show_text(SHOW_WIN_TEXT, SHOW_RESULT_POS, BLACK, FONT_DIR, 180);
    return;
}

void GameManager::show_lose()
{
    win -> show_text(SHOW_LOSE_TEXT, SHOW_RESULT_POS, RED, FONT_DIR, 180);
    return;
}

void GameManager::run_current_wave_while_it_isnt_over()
{
    while (current_wave_going_on())
    {
        run_current_wave();
    }
    return;    
}

bool GameManager::current_wave_going_on()
{
    return ((user_health > 0) && (current_wave.get_wave_over_flag() == false) ||
            enemy_exists_on_the_field());
}

bool GameManager::game_is_over()
{
    if (user_health <= 0 || current_wave_number > game_waves.size())
        game_over = true;
        
    return game_over;
    
}

void GameManager::run_current_wave()
{
    generate_enemy_if_enough_time_passed();
    update_and_draw();
    return;
}

void GameManager::generate_enemy_if_enough_time_passed() 
{
    if (its_time_to_make_enemy())
    {
        enemies.push_back(current_wave.generate_random_enemy());
        broadcast_enemy_list_to_towers();
        tick_counter = 0;
    }
    return;
}

bool GameManager::its_time_to_make_enemy()
{
    return ((time_elapsed_reached(ENEMY_SPAWN_INTERVAL) == true)&&
            (current_wave.get_wave_over_flag() == false));
}

bool GameManager::time_elapsed_reached(float time_milliseconds)
{
    if (tick_counter * GAME_DELAY >= time_milliseconds)
        return true;
    return false;
}

void GameManager::update_and_draw()
{
    update();
    collect_bounties();
    draw();
    delay(GAME_DELAY);
    return;    
}

void GameManager::update()
{
    update_enemies();
    update_towers();
    handle_events();
    tick_counter++;
    return;
}

void GameManager::collect_bounties()            
{
    for (Enemy* enemy:enemies)
    {
        if (bounty_collectable(enemy))
        {
            user_coins += enemy -> get_bounty();
            enemy -> set_bounty_collected();
        }
    }
}


bool GameManager::bounty_collectable(Enemy* enemy)
{
    return ((enemy -> is_alive() == false) &&
            (enemy -> get_bounty_collected_flag() == false));
}

void GameManager::draw_enemies()
{
    for (Enemy* enemy : enemies)
    {
        enemy -> draw(win);
    }
    return;
}

void GameManager::draw_towers()
{
    for (Tower* tower : towers)
    {
        tower -> draw(win);
    }
    return;
}

void GameManager::set_up_background()
{
    win -> draw_img(background_path);
    return;
}

void GameManager::show_texts_on_screen()
{
    
    show_health();
    show_current_wave();
    show_coins();
    show_massage();
    return;
}

void GameManager::show_health()
{
    string health_in_string_format = to_string(user_health);
    Rectangle box(Point(60,75), Point(90,105));
    win -> draw_img("game_manager/heart.png", box);
    win -> show_text(health_in_string_format, SHOW_HEALTH_POS, RGB(200, 50, 50), FONT_DIR, FONT_SIZE);
    return;

}

void GameManager::show_current_wave()
{
    string current_wave_in_string_format = "wave number: " + to_string(current_wave_number);
    win -> show_text(current_wave_in_string_format, SHOW_WAVE_POS, WHITE, FONT_DIR, FONT_SIZE);
    return;
}
void GameManager::show_coins()
{
    string coins_in_string_format = to_string(user_coins);
    Rectangle box(Point(960,75), Point(990,105));
    win -> draw_img("game_manager/coin.png", box);
    win -> show_text(coins_in_string_format, SHOW_COIN_POS, YELLOW, FONT_DIR, FONT_SIZE);
    return;
}

void GameManager::show_massage()
{
    win -> show_text(massage_shown, Point(100, 900), WHITE, FONT_DIR, FONT_SIZE);
    return;
}

void GameManager::draw()
{
    win -> clear();
    set_up_background();
    draw_path();
    draw_enemies();
    draw_towers();
    show_texts_on_screen();
    win -> update_screen();
}

void GameManager::draw_path()
{
    for (int counter = 0; counter < milestones.size() -1; counter++)
    {
        win -> draw_line(milestones[counter], milestones[counter+1], PATH_COLOR);
    }
    win -> fill_circle(milestones[0], 10, BLUE);
    win -> fill_circle(milestones.back(), 10, RED);
}

bool GameManager::enemy_exists_on_the_field()
{
    for (Enemy* enemy:enemies)
    {
        if (enemy -> get_should_be_deleted_flag() == false)
            return true;
    }
    return false;
}

void GameManager::go_to_next_wave()
{
    wait_between_waves_for_some_time();
    current_wave_number++;
    if (current_wave_number <= game_waves.size())
    { 
        current_wave = game_waves[current_wave_number - 1];
    }
    release_alloc_memory_between_rounds();
    return;
}

void GameManager::wait_between_waves_for_some_time()
{
    tick_counter = 0;
    while (!time_elapsed_reached(TIME_BETWEEN_WAVES_INTERVAL))
    {
        update_and_draw();
    }
    return;
}


Point GameManager::get_milestone(const vector<int>& coordinate)
{
    int x = FIRST_BLOCK_X_PIX + BLOCK_WIDTH / 2 + coordinate[0] * BLOCK_WIDTH;
    int y = FIRST_BLOCK_Y_PIX + BLOCK_HIGHT / 2 + coordinate[1] * BLOCK_HIGHT;
    return Point(x, y);
}


vector<Point> GameManager::convert_to_milestones()
{
    vector<Point> the_milestones;
    for (vector<int> coordinate: game_path)
    {
        Point new_milestone = get_milestone(coordinate);
        the_milestones.push_back(new_milestone);
    }
    return the_milestones;
}

void GameManager::set_milestones()
{
    milestones = convert_to_milestones();
}