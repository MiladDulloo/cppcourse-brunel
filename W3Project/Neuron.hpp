#ifndef NEURON_H
#define NEURON_H
#include <iostream>
#include <vector>

class Neuron
{
	
private:
	
	double Iext;							// Input current
	double V;							   	// Membrane potential
	double spike_t; 					  	// time of last spike
	double spike_num;						// number of spikes
	long local_t;							// local time of neuron
	
//Integration- firing of spikes - calculation for pot

	int C_E;								// number of Excitatory connections recieved (random)
	int C_I;								// number of Inhibitory connections recieved (random)
	int g;		
	double Vext; 							// frequency of external input (background activity)
	const double R;							// membrane resistance
	const double Tau;						// membrane time constant (ms)
	const double thld;						// spike Potential threshold sigma
	const double Vreset;					// reset potential
	const double refrac_t;					// refractory period duration (ms)
	const double h;							// equidistant time-steps
	const double refrac_steps;
	double const1;							// constant for pot calculation
	double const2;							// constant for pot calculation
	std::vector<double> potentials_vector;	// vector to store potential values at each steps
	long delay;								// synaptic delay in ms;
	std::vector<double> buffer;				// spikes buffer ring
	double j;								// amplitude of spike


public:		
	
	Neuron(); 								// constructor

// getters	

	double get_Iext();
	
	double get_V() const;
	
	double get_spike_t() const;
	
	double get_spike_num() const;
	
	
// setters

	void set_Iext(double newExtI);

// Update function	

	bool Neurupdate(double steps);
	
// recieves spikes at time t with amplitude J

	void spike_reception(long receptionT);

};

#endif
