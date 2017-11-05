#include "Neuron.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <map>
#include <random>

using namespace std;

// Constructor initialization list

Neuron::Neuron():
Iext(0.0), V(0.0), spike_t(0.0), spike_num(0.0), local_t(0.0), g(5), R(20.0), Tau(20.0), thld(20.0), Vreset(0.0), refrac_t(2.0),
h(0.1), refrac_steps(refrac_t / h), delay(15), j(0.1)
{
	buffer.resize(delay + 1, 0.0);
	const1 = exp(-h/Tau);												//constant unit to update membrane pot at each time step
	const2 = R*(1.0-const1);
}

// getters	

double Neuron::get_Iext()
	{ return Iext; }
	
double Neuron::get_V() const
	{ return V; }
	
double Neuron::get_spike_t() const
	{ return spike_t; }
	
double Neuron::get_spike_num() const
	{ return spike_num; }
	
	
// setters

void Neuron::set_Iext(double newExtI)
	{ Iext = newExtI; }
	
	
// Update function

bool Neuron::Neurupdate(double steps)
	{
	if (steps==0) return false;											// Neuron simulation loop
	bool spike = false;
	const double t_stop = local_t + steps;	
	while(local_t < t_stop)
		{
			double inTime = local_t%(delay + 1); 						// ring buffer arrival time of spike. (slide 15 week4)
			if (V > thld) 												// spike firing threshold potential is reached
				{
					spike=true;
					++spike_num;
					spike_t  = local_t;									//latest spike time stores
				
				}
		if ((spike_t > 0.0) and (local_t - spike_t) < refrac_steps) //if neuron is refractory (in refrac period)
				{ V = 0.0;}												//depolarization reset to Vreset after refractory period
				  														
			else
			{ 						
				potentials_vector.push_back(V); 						//Adds new membrane pot to vector
				static random_device rd;
				static mt19937 gen(rd());
				static poisson_distribution<> extnoiseinput(2);
				V = const1*V + const2*Iext + j*buffer[inTime] + j*extnoiseinput(gen); //Membrane equation V(t) = V(t +h) + poisson and reading spikes
			}
				buffer[inTime]= 0.0; 									// spike buffer clearing
				
			++local_t;
		}
	return spike;	
	}
	
	
// Spike reception

void Neuron::spike_reception(long receptionT, double j)
	{
		size_t outTime = receptionT % (delay +1);						//ring buffer ejection time of spik(slide 15 week4)
		buffer[outTime]+=j;												//writing spikes
	}
