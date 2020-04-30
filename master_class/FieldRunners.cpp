#include "FieldRunners.hpp"
using namespace std;

FieldRunners::FieldRunners()
{
    game_path = read_path_coordinates();
    game_waves = read_waves_descreptions();
    manager = GameManager(game_waves);
    run();
}

vector<int> parse_line (string line)
{
    vector<int> result ; 
    istringstream input_strings(line) ;
    int value ;
    while( input_strings >> value ) result.push_back(value);
    return result ;
}

path_coordinates FieldRunners::read_path_coordinates()
{
    string path;
    getline(cin, path);
    vector<int> coordinate_data = parse_line(path);
    path_coordinates coordinates;
    int row_number = 0;
    int col_number = 0;
    for (int coordinate_index = 0; coordinate_index < coordinate_data.size()/2; coordinate_index++)
    {
        vector<int> new_coordinate;
        row_number = coordinate_data[coordinate_index * 2];
        col_number = coordinate_data[coordinate_index * 2 + 1];
        new_coordinate.push_back(row_number);
        new_coordinate.push_back(col_number);
        coordinates.push_back(new_coordinate);
    }
    return coordinates;
}

waves FieldRunners::read_waves_descreptions()
{
    waves game_waves;
    string wave_descriptions;
    int wave_number = 0;
    while (getline(cin, wave_descriptions))
    {
        vector<int> wave_data = parse_line(wave_descriptions);
        wave_number++;
        Wave new_wave(wave_data, game_path, wave_number);
        game_waves.push_back(new_wave);
    }
    return game_waves;
}

void FieldRunners::run()
{
    manager.run();
}