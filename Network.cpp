#include "Network.hpp"
#include "Neuron.hpp"
#include <iostream>
#include <cmath>
#include <random>
#include <fstream>
using namespace std;


// Constructor initialization list

	Network::Network():																	
	N_E(10000), N_I(2500), C_E(1000), C_I(250),		
	Jex(0.1), Jin(-0.5)
	{
	    	
	for (int i(0); i<12500; ++i)												// Creates new neurons in neuron vector
		{ 
			neuronsVec.push_back(Neuron());								
	    }
	    
	for (int i(0); i<12500; ++i)												// Initializes the network vector to all 0s
	    {  
			vector<int> addconect;
			network.push_back(addconect);
			
		}
	}
	

	void Network::connect()												// Connects network randomly
{ 
	for (int n=0; n<12500; ++n)												// On ALL neurons
		{
			for (int e=0; e<1000; ++e)										// Excitatory connections
			{
				 static random_device rd;									//// 
				 static mt19937 gen(rd());									////	choses a connected neuron with a uniform distribution
				 static uniform_int_distribution<> connections(0, N_E -1);		////
				network[connections(gen)].push_back(n);					// assigns the randomly chosen excit neuron to the nth excitatory neuron
			}
	
			for (int i=10000; i<12500; ++i)								// Inhibitory connections
			{
				static random_device rd;									////
				static mt19937 gen(rd());									////	choses a connected inhib neuron with a uniform distribution
				static uniform_int_distribution<> connections(N_E, 12500 -1);	////
				network[connections(gen)].push_back(n);					// assigns the randomly chosen neuron to the nth inhibitory neuron
		}
	}
}

	void Network::updateALL(int simtime, int stop)											// Transfers spikes from neurons and their connected targets
	{
		
			ofstream MembranePotentials ;
			MembranePotentials.open ("MembranePot.txt");
			
			
			int progress(1);
			int progress_rate(0.01*stop);
			
			
	    while(simtime < stop)
		{	
			
			if(simtime > progress_rate)
			{
				cout << progress << "%" << endl;
				++progress;
				progress_rate += 0.01*stop;
			}
			
			
			for(int i=0; i<12500; ++i)
		   {
			
				int J;												// Amplitude value..
						if (i<=10000)										// ..for first 10000 excitatory neurons
						{J = Jex;} 
						else 
						{J = Jin;}											// ..for last 2500 neurons are inhibitory
				
				if (neuronsVec[i].Neurupdate(1))								// IF SPIKE HAPPENED at neuron "i"
				{ 

					
                    MembranePotentials << simtime << "\t " << i << endl;
								
		
						
						for (int k=0; k < network[i].size(); ++k)								// iterates over all target neurons to check conncections	
						{	
						  
							 //cout << "ici" << endl;
							 
							 int target_neuron = network[i][k];
							 neuronsVec[target_neuron].spike_reception(simtime + 15, J);	// gives that spike from "i neuron" to the connected target neurons k
							
						}
						 
				}
			}
				
			++simtime;
		  }
		  	MembranePotentials.close();	
	    }
		
		
		
		
		
		
