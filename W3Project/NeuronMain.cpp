/*! Main simulation file */
// MILAD DULLOO SVBA3
#include "Neuron.hpp"
#include "Network.hpp"
#include <iostream>
#include <fstream>
using namespace std;

/*! \brief NeuronMain
 *         
 *
 *  Simulation will run from here
 * 	during the time enterval specified by t_start
 * 	and t_stop, here delta time = 1000ms
 */

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
