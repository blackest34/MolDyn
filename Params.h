// Params.h

#pragma once
#include <string>

using std::string;

class Params {
    int natoms =100;
    double dt=1e-15;
    double temp=300;
    int steps = 100000;
    int freq=1000;
    double box[6] = { 0, 1e-8, 0, 1e-8, 0, 1e-8 };
    string ofname= "traj.dump";
public:
    int getNatoms();
    double getDt();
    double getTemp();
    int getSteps();
    int getFreq();
    double* getBox();
    string getOfname();

    void setNatoms(int s_natoms);
    void setDt(double s_dt);
    void setTemp(double s_temp);
    void setSteps(int s_steps);
    void setFreq(int s_freq);
    void setBox(double *s_box);
    void setOfname(string &s_ofname);
};
