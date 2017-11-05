// DULLOO MILAD SVBA3

#include "Network.hpp"
#include "Neuron.hpp"
#include <iostream>
#include <cmath>
#include <random>
#include <fstream>
using namespace std;




	Network::Network():													// Constructor initialization list								
	N_E(10000), N_I(2500), C_E(1000), C_I(250),		
	Jex(0.1), Jin(-0.5)
	{
	    	
	for (int i(0); i<12500; ++i)										// Initializes new neurons in neuron vector
		{ 
			neuronsVec.push_back(Neuron());								
	    }
	    
	for (int i(0); i<12500; ++i)										// Initializes the network vector connections
	    {  
			vector<int> addconect;	
			network.push_back(addconect);
			
		}
	}
	

	void Network::connect()												// Connects network randomly
{ 
	for (int n=0; n<12500; ++n)											// FOR ALL neurons:
		{
			for (int e=0; e<1000; ++e)									// Excitatory connections
			{
				 static random_device rd;								//// choses a connected neuron
				 static mt19937 gen(rd());								//// with a uniform distribution
				 static uniform_int_distribution<> connections(0, N_E -1);
				network[connections(gen)].push_back(n);					// assigns the randomly chosen neuron to the eth excitatory neuron
			}
	
			for (int i=10000; i<12500; ++i)								// Inhibitory connections
			{
				static random_device rd;								////
				static mt19937 gen(rd());								////choses a connected inhib neuron with a uniform distribution
				static uniform_int_distribution<> connections(N_E, 12500 -1);////
				network[connections(gen)].push_back(n);					// assigns the randomly chosen neuron to the nth inhibitory neuron
		}
	}
}

	void Network::updateALL(int runningSimulation, int stopTime)		// Transfers spikes from neurons to their connected targets
	{
		
			ofstream MembranePotentials ;								// prints spikes on a text file..
			MembranePotentials.open ("MembranePot.txt");
			int loadRate(0.01*stopTime);
	  while(runningSimulation < stopTime)								// ..while the simulation is running
	  {	
			
			if(runningSimulation > loadRate)
			{
				cout << "loading" << endl;
				loadRate += 0.01*stopTime;
			}
			
			
		for(int i=0; i<12500; ++i)
		{
			
			int J;														// Amplitude value..
			if (i<=10000)												// ..for first 10000 excitatory neurons
			{J = Jex;} 
			else 
			{J = Jin;}													// ..for last 2500 neurons are inhibitory
				
			if (neuronsVec[i].Neurupdate(1))							// IF SPIKE HAPPENED at neuron "i"
			{		
          MembranePotentials << runningSimulation << "\t " << i << endl;// writes time at which spike happened
								
		
						
			for (int k=0; k < network[i].size(); ++k)					// iterates over all target neurons to check conncections	
				{	
							 
				int target_neuron = network[i][k];						// finds all target neurons locations
				neuronsVec[target_neuron].spike_reception(runningSimulation + 15, J);	// gives that spike to the connected target neurons
							
				}				 
			}
		}
				
		++runningSimulation;
	 }
		  	MembranePotentials.close();	
	    }
		
		
		
		
		
		
