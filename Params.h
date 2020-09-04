// Params.h

#pragma once
#include <string>

using std::string;

class Params {
    int natoms =0;
    double dt=0;
    double temp=0;
    int steps=0;
    int freq=0;
    double box[6];
    string ofname= "test.dump";
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
