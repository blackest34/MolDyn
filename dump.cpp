#include <fstream>
#include <iostream>

#include "Atom.h"

using std::cout;
using std::endl;

using std::ofstream;

void dump(Atom atoms[], int nAtoms, ofstream& myfile, ofstream& outputThermo, double inst_temp, double box[], int step) {
    myfile << "ITEM: TIMESTEP" << endl;
    myfile << step << endl;

    myfile << "ITEM: NUMBER OF ATOMS" << endl;
    myfile << nAtoms << endl;

    myfile << "ITEM: BOX BOUNDS pp pp pp" << endl;
    int i = 0;
    while (i < 6) {
        myfile << box[i] << " ";
        myfile << box[i + 1] << endl;
        i += 2;
    }

    myfile << "ITEM: ATOMS radius x y z v_x v_y v_z" << endl;
    for (int i = 0; i < nAtoms; i++) {
        myfile << atoms[i].getRadius() << " ";
        for (int j = 0; j < 3; j++)
            myfile << *(atoms[i].getPos() + j) << " ";
        for (int j = 0; j < 3; j++)
            myfile << *(atoms[i].getPos() + j) << " ";
        myfile << endl;
    }

    outputThermo << step << " " << inst_temp << endl;
}