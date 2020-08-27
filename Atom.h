//Atom.h

#pragma once

#include "Constants.h"

class Atom {
    double mass = 1e-3 / Avogadro;
    double radius = 120e-12;
    double pos[3];
    double vel[3];
    double forces[3];
public:
    void setPos(double init[]);
    void setVel(double init[]);
    void setForces(double init[]);

    double getMass();
    double getRadius();

    double* getPos();
    double* getVel();
    double* getForces();
};
