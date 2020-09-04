#include <cmath>
#include <iostream>

using std::cout;
using std::endl;


double computeLambda(double dt, double temp, double inst_temp) {
	
	double lambda = 0;

	/*
	//velocity scaling

	lambda = sqrt(temp / inst_temp);
	*/
	
	//Berendsen
	double tau = 1e-13; //in seconds

	lambda = sqrt(1 + dt / tau * (temp / inst_temp - 1));
	
	return lambda;

}

