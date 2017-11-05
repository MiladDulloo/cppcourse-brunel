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
	Network Net;
	
	Net.connect();
		
	//cout << "easy" << endl;
	Net.updateALL(t_start, t_stop);
	
	return 0;
};
