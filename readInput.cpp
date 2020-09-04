// readInput.cpp: read input file (input.txt) and assign the parameters to the object di tipo Params

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <stdlib.h>

#include "Params.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::stringstream;
using std::getline;
using std::scientific;

void parsing(string &input);

void readInput(Params &myParams){

	int value_i = 0;
	double value_d = 0.0;
	double s_box[6];
	string s_ofname;
	
	ifstream infile("input.txt");
	string line;
	
	if (infile.is_open()) {
		while (getline(infile, line, '=')) {
			parsing(line);
			if (line.compare("NATOMS") == 0) {
				infile >> value_i;
				myParams.setNatoms(value_i);
				getline(infile, line);
			}
			else if (line.compare("DT") == 0) {
				getline(infile, line);
				stringstream ss_dt(line);
				ss_dt >> scientific >> value_d;
				myParams.setDt(value_d);
			}
			else if (line.compare("TEMP") == 0) {
				infile >> value_d;
				myParams.setTemp(value_d);
				getline(infile, line);
			}
			else if (line.compare("STEPS") == 0) {
				infile >> value_i;
				myParams.setSteps(value_i);
				getline(infile, line);
			}
			else if (line.compare("FREQ") == 0) {
				infile >> value_i;
				myParams.setFreq(value_i);
				getline(infile, line);
			}
			else if (line.compare("BOX") == 0) {
				getline(infile, line);
				stringstream ss_box(line);
				for (int i = 0; i < 6; i++) {
					ss_box >> scientific >> s_box[i];
				}
				myParams.setBox(s_box);
			}
			else if (line.compare("OFNAME") == 0) {
				infile >> s_ofname;
				myParams.setOfname(s_ofname);
			}
			else
				getline(infile, line);
		}
	
	}
	else {
		cout << "Unable to open the file input.txt or the file does not exist." << endl;
		cout << "Program terminated." << endl;
		exit(EXIT_FAILURE);
	}
	infile.close();
}

void parsing (string &input){

	int position = 0;
	
	position = input.find_first_of(' ');

	while (position != input.npos) {
		input.erase(position, 1);
		position = input.find_first_of(' ');
	}
	
}
