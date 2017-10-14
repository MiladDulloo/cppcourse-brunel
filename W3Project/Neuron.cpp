#include "Neuron.hpp"
#include <iostream>
#include <cmath>
using namespace std;

Neuron::Neuron():
Iext(0.0),V(0.0),
spike_t(0.0),
spike_num(0.0),
local_t(0.0),
R(20.0),
Tau(20.0),
thld(20.0),
Vreset(0.0),
refrac_t(2.0),
h(0.1),
refrac_steps(refrac_t / h)
{
		
	const1 = exp(-h/Tau);
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
	if (steps==0) return false;			//Neuron simulation loop
	bool spike = false;
	const double t_stop =local_t + steps;	
	while(local_t < t_stop)
		{
			if (V > thld) // spike firing threshold potential is reached
				{
				++spike_num;
				spike_t  = local_t;	//latest spike time stores
				spike=true;
				}
			if ((spike_t > 0.0) and (local_t - spike_t) < refrac_steps) //if neuron is refractory (in refrac period)
				{ V = Vreset; } //depolarization reset to Vreset after refractory period
			else
				{ V = const1*V + const2*Iext;} //Membrane equation V(t) = V(t +h)
		++local_t;
		}
	return spike;	
	}
