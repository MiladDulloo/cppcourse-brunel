#ifndef NETWORK_H
#define NETWORK_H
#include "Neuron.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Network
{	
	private:
		
	int N_E;															// number of Excitatory neurons
	int N_I;															// number of Inhibitory neurons
	int C_E;															// number of Excitatory connections recieved (random)
	int C_I;															// number of Inhibitory connections recieved (random)
	int Jex;															// amplitude of excitatory neurons
	int Jin;															// amplitude of inhibitory neurons
	vector<Neuron> neuronsVec;											// vector of neurons
	vector< vector<int> > network;										// vector of neurons network connection

	
	
	public:
	Network();
	void connect();														// connections of neurons
	void updateALL(int, int);													// updates all neurons
	
};

#endif
