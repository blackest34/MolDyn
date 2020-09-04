#include <stdlib.h>
#include <random>
#include <iostream>
#include <fstream>

//Constants and Functions
#include "Constants.h"

//Classes
#include "Atom.h"
#include "Params.h"

using std::ofstream;
using std::cout;
using std::endl;

//function declarations
void readInput(Params &myParams);
void integrate(Atom atoms[], int nAtoms, double dt, double lambda);
void wallHitCheck(Atom atoms[], int nAtoms, double box[]);
double computeTemp(Atom atoms[], int nAtoms);
double computeLambda(double dt, double temp, double inst_temp);
void dump(Atom atoms[], int nAtoms, ofstream& myfile, ofstream& outputThermo, double inst_temp, double box[], int step);

int main() {

    Params myParams;

    readInput(myParams);
    
    int nAtoms = myParams.getNatoms();
    double temp = myParams.getTemp();
    double dt = myParams.getDt();
    int nSteps = myParams.getSteps();
    int freq = myParams.getFreq();
    string ofName = myParams.getOfname();
       
    std::default_random_engine gen;
    std::uniform_real_distribution<double> distrPos(0.0, 1.0);
    std::uniform_real_distribution<double> distrVel(-1.0, 1.0);

    cout << "nAtoms = " << nAtoms << endl;
    cout<< "temp = " << temp << endl;
    cout << "dt = " << dt << endl;
    cout << "nsteps = " << nSteps << endl;
    cout << "freq = " << freq << endl;
    cout << "box = ";
    for (int i = 0; i < 6; i++)
        cout << *(myParams.getBox() + i) << "\t"; 
    cout << endl;
    cout << "ofname = " << ofName << endl;

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

     //main loop
     while (step <= nSteps) {

         double inst_temp = computeTemp(atoms, nAtoms);

         double lambda = computeLambda(dt, temp, inst_temp);

         integrate(atoms, nAtoms, dt, lambda);
         
         wallHitCheck(atoms, nAtoms, box);

         if (step % freq == 0)
            dump(atoms, nAtoms, myfile, outputThermo, inst_temp, box, step);

         step++;
     }

     myfile.close();
     outputThermo.close();
    
    return 0;
}