/*! Main simulation file */
// MILAD DULLOO SVBA3
#include "Neuron.hpp"
#include "Network.hpp"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
//Simulation Time Interval
	double t_start = 0;
	
	double t_stop = 1000;
	

//Simulation
	Network Net;							// Network creation
	Net.connect();							// Network connection
	Net.updateALL(t_start, t_stop);			// Network simulation run
	
	return 0;
};
