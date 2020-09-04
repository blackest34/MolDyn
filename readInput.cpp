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

	int pos = 0;
	string line;
	string key;
	stringstream value;
	
	int value_i = 0;
	double value_d = 0.0;
	double s_box[6];
	string s_ofname;
	
	ifstream infile("input.txt");
	
	if (infile.is_open()) {
		while (getline(infile, line)) {
			if (line.empty()) 
				continue;
			pos = line.find_first_of("=");
			key = line.substr(0, pos);
			stringstream value(line.substr(pos + 1));
			parsing(key);
			
			if (key.compare("NATOMS") == 0) {
				value >> value_i;
				myParams.setNatoms(value_i);
			}
			else if (key.compare("TEMP") == 0) {
				value >> value_d;
				myParams.setTemp(value_d);
			}
			else if (key.compare("DT") == 0) {
				value >> scientific >> value_d;
				myParams.setDt(value_d);
			}
			else if (key.compare("STEPS") == 0) {
				value >> value_i;
				myParams.setSteps(value_i);
			}
			else if (key.compare("FREQ") == 0) {
				value >> value_i;
				myParams.setFreq(value_i);
			}
			else if (key.compare("BOX") == 0) {
				for (int i = 0; i < 6; i++) {
					value >> scientific >> s_box[i];
				}
				myParams.setBox(s_box);
			}
			else if (key.compare("OFNAME") == 0) {
				value >> s_ofname;
				myParams.setOfname(s_ofname);
			}
		}
	}
	else {
		cout << "Unable to open the file input.txt or the file does not exist." << endl;
		cout << "Program terminated." << endl;
		exit(EXIT_FAILURE);
	}
	infile.close();
}

void parsing (string &key){

	int pos = 0;
	
	pos = key.find_first_of(' ');

	while (pos != key.npos) {
		key.erase(pos, 1);
		pos = key.find_first_of(' ');
	}
	
}
