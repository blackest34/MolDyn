#include "Atom.h"

void Atom::setPos(double init[]) {
    for (int i = 0; i < 3; i++)
        pos[i] = init[i];
}
void Atom::setVel(double init[]) {
    for (int i = 0; i < 3; i++)
        vel[i] = init[i];
}
void Atom::setForces(double init[]) {
    for (int i = 0; i < 3; i++)
        forces[i] = init[i];
}

double Atom::getMass() {
    return mass;
}
double Atom::getRadius() {
    return radius;
}
double* Atom::getPos() {
    return pos;
}
double* Atom::getVel() {
    return vel;
}
double* Atom::getForces() {
    return vel;
}