// Params.h

#pragma once
#include <string>

using std::string;

class Params {
    int natoms = 50;
    double dt = 1e-15;
    double temp = 600.0;
    int steps = 100000;
    int freq = 100;
    double box[6] = { 0, 1e-8, 0, 1e-8, 0, 1e-8 };
    string ofname = "traj-hydrogen.dump";
public:
    int getNatoms();
    double getDt();
    double getTemp();
    int getSteps();
    int getFreq();
    double* getBox();
    string getOfname();
};
