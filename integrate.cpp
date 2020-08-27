#include<cmath>

#include "Atom.h"

void integrate(Atom atoms[], int nAtoms, double dt, double lambda) {

    /*
    //Berendsen and velocity scaling
    for (int i = 0; i < nAtoms; i++) {
        double vels[] = { 0, 0, 0 };
        for (int j = 0; j < 3; j++) 
            vels[j] = *(atoms[i].getVel() + j) * lambda;
        atoms[i].setVel(vels);
    }
    */

    //Nose Hoover
    for (int i = 0; i < nAtoms; i++) {
        double vels[] = { 0, 0, 0 };
        for (int j = 0; j < 3; j++)
             vels[j] = *(atoms[i].getVel() + j) - *(atoms[i].getVel() + j) *lambda * dt;
        atoms[i].setVel(vels);
    }
    
    for (int i = 0; i < nAtoms; i++) {
        double pos[]= { 0, 0, 0 };
        for (int j = 0; j < 3; j++)
            pos[j] = *(atoms[i].getPos() + j) + *(atoms[i].getVel() + j) * dt;
        atoms[i].setPos(pos);
    }
    
}