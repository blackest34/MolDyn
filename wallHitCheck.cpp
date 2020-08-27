#include <cmath>

#include "Atom.h"

void wallHitCheck(Atom atoms[], int nAtoms, double box[]) {

    double pos[3];

    for (int i = 0; i < nAtoms; i++) {

        for (int j = 0; j < 3; j++) {
            pos[j] = *(atoms[i].getPos() + j);
            double boxA = box[j * 2];
            double boxB = box[j * 2 + 1];

            if (pos[j] <= boxA)
                pos[j] = boxB - (boxA - abs(pos[j]));
            else if (pos[j] >= boxB)
                pos[j] = boxA + abs(pos[j] - boxB);
        }
        atoms[i].setPos(pos);
    }

}