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