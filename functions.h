#pragma once

#include <fstream>

#include "Atom.h"
#include "Params.h"

using std::ofstream;

void integrate(Atom atoms[], int nAtoms, double dt, double lambda);

void wallHitCheck(Atom atoms[], int nAtoms, double box[]);

double computeTemp(Atom atoms[], int nAtoms);

double computeLambda(double* gamma, double dt, double temp, double inst_temp);

void dump(Atom atoms[], int nAtoms, ofstream& myfile, ofstream& outputThermo, double inst_temp, double box[], int step);

void run(Params myParams);

