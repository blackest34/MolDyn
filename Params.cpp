#include "Params.h"

int Params::getNatoms() {
    return natoms;
}
double Params::getDt() {
    return dt;
}
double Params::getTemp() {
    return temp;
}
int Params::getSteps() {
    return steps;
}
int Params::getFreq() {
    return freq;
}
double* Params::getBox() {
    return box;
}
string Params::getOfname() {
    return ofname;
}

void Params::setNatoms(int s_nAtoms) {
    natoms = s_nAtoms;
}
void Params::setDt(double s_dt) {
    dt = s_dt;
}
void Params::setTemp(double s_temp) {
    temp = s_temp;
}
void Params::setSteps(int s_steps) {
    steps = s_steps;
}
void Params::setFreq(int s_freq) {
    freq = s_freq;
}
void Params::setBox(double *s_box) {
    for (int i = 0; i < 6; i++)
        box[i] = s_box[i];
}
void Params::setOfname(string& s_ofname) {
    ofname = s_ofname;
}