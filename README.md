# MolDyn vs 0.2

A molecular Dynamic code written in C++ by Giuliano Carchini

The program simulates a box of noninteracting particles (hydrogen mass) with Berendsen thermostat. 

The paramters are defined in the input.txt file (REQUIRED). An example is included in the repository.
The parameters are to be included in ALL CAPS followed by an equal sign '=' Any amount of spaces can be included.
The parameters are the following:

NATOMS = (INT) total number of atoms.
TEMP = (DOUBLE) temperature
DT = (DOUBLE) timestep in seconds (scientific notation allowed)
STEPS = (INT) total number of steps in the simulation
FREQ = (INT) frequence of steps for writing for the trajectory and the thermodynamical data
BOX = (6xDOUBLE) six values that define the box (xmin, xmax, ymin, ymax, zmin, zmax) separated by space (scientific notation allowed).
OFNAME = (STRING) name for the trajectory file

No default values are included (yet)

More to come...
