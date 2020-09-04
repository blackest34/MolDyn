# MolDynCode v0.21

A molecular Dynamic code written in C++ by Giuliano Carchini

The program simulates a box of noninteracting particles (hydrogen mass) with Berendsen thermostat. 

The paramters are defined in the input.txt file (REQUIRED). An example is included in the repository.
The parameters are to be included in ALL CAPS followed by an equal sign '=' Any amount of spaces or empty lines can be included.
The parameters are the following:

NATOMS = (INT) total number of atoms.

TEMP = (DOUBLE) temperature

DT = (DOUBLE) timestep in seconds (scientific notation allowed)

STEPS = (INT) total number of steps in the simulation

FREQ = (INT) frequence of steps for writing for the trajectory and the thermodynamical data

BOX = (6xDOUBLE) six values that define the box (xmin, xmax, ymin, ymax, zmin, zmax) separated by space (scientific notation allowed).

OFNAME = (STRING) name for the trajectory file

The input file in the repository shows the default values. If any value is not present in the file, the default value is used.

More to come...
