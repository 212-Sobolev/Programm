#ifndef __Rprocessor_H__
#define __Rprocessor_H__

#include "Rover.h"
#include "Landscape.h"
#include <vector>
#include <list>
#include <fstream>

class R_Processor
{ 
private:
    Rover *rover;
    Landscape *landscape;
    Point start_point;
    Point end_point;
    std::ofstream routfile;
    

    std::vector<Point> center_rover;
    std::vector<double> tilts_angle_forback;
    std::vector<double> tilts_angle_side;
    std::vector<std::string> directions;

    std::vector<Point> rout;

    int error;

public:
    R_Processor(Rover *rov, Landscape *land);
    void print_orig_rout();
    void place_rover_start(Point a); // Ставим ровер в начальную точку
    std::string decod_direction(int a, int b); //считаем что a > b (то есть а - следующий индекс после b)
    void final_rout();
    std::string inverse_dir(std::string direct);
    void Djkstra();

    void make_move(std::string dir);
    void folow_rout();

};

#endif