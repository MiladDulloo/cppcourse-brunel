// DULLOO MILAD SVBA3
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
	

//Simulation of the network connection and spike transfers
	Network Net;											//Creates network of neurons
	Net.connect();											//Connects neurons randomly
	Net.updateALL(t_start, t_stop);							//Transfers spikes between connected neurons
	
	return 0;
};
