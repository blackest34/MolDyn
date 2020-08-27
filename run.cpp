#include <iostream>
#include <random>
#include <stdlib.h>
#include <fstream>

#include "Params.h"
#include "Atom.h"
#include "functions.h"

using std::ofstream;
using std::cout;
using std::endl;

void run(Params myParams) {

    double temp = myParams.getTemp();
    double dt = myParams.getDt();
    int nAtoms = myParams.getNatoms();
    int nSteps = myParams.getSteps();
    int freq = myParams.getFreq();
    
    std::default_random_engine gen;
    std::uniform_real_distribution<double> distrPos(0.0, 1.0);
    std::uniform_real_distribution<double> distrVel(-1.0, 1.0);

    double box[6];
    for (int i = 0; i < 6; i++)
        box[i] = *(myParams.getBox() + i);

    Atom* atoms = new Atom[nAtoms];

    double init[3];

    //initial positions (bound to the box)
    for (int i = 0; i < nAtoms; i++) {
        for (int j = 0; j < 3; j++)
            init[j] = abs(box[1 + 2 * j] - box[0 + 2 * j]) * distrPos(gen);
        atoms[i].setPos(init);
    }

    //initial velocities
    for (int i = 0; i < nAtoms; i++) {
        for (int j = 0; j < 3; j++)
            init[j] = distrVel(gen);
        atoms[i].setVel(init);
    }

    ofstream myfile;

    ofstream outputThermo;

    myfile.open(myParams.getOfname());
    
    //output contains thermodynamical quantities
    outputThermo.open("thermo.txt");
    
    int step = 0;

    double gamma = 0; //gamma for NH thermostat

    while (step <= nSteps) {

        double inst_temp = computeTemp(atoms, nAtoms);
        
        cout << inst_temp << endl;

        double lambda = computeLambda(&gamma, dt, temp, inst_temp);
       
        integrate(atoms, nAtoms, dt, lambda); 

        wallHitCheck(atoms, nAtoms, box);

        if (step % freq == 0)
            dump(atoms, nAtoms, myfile, outputThermo, inst_temp, box, step);

        step++;
    }

    myfile.close();
    outputThermo.close();
}