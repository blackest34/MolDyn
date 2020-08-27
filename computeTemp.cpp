#include <cmath>

#include "Atom.h"
#include "Constants.h"

double computeTemp(Atom atoms[], int nAtoms) {

    double Ekin = 0;

    for (int i = 0; i < nAtoms; i++) {

        double velTotSq = 0;

        for (int j = 0; j < 3; j++)
            velTotSq += pow(*(atoms[i].getVel() + j), 2.0);

        Ekin += atoms[i].getMass() * velTotSq;

    }
    return Ekin / (Boltzmann * (3 * double(nAtoms) - 3));
}