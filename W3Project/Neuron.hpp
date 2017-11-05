// DULLOO MILAD SVBA3
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
	double j;								// amplitude
	std::vector<double> buffer;				// spikes buffer ring


public:		
	
	Neuron(); 								// constructor

// getters	

	double get_Iext();													// gets neuron external current
	
	double get_V() const;												// gets neuron membrane potential
	
	double get_spike_t() const;											// gets neuron last spike time
	
	double get_spike_num() const;										// gets neuron spike number
	
	
// setters

	void set_Iext(double newExtI);										// sets a new external current input
								
	bool Neurupdate(double steps);										// Updates neuron spikes state
	void spike_reception(long receptionT, double j);						// neuron recieves spike at time reception t with amplitude j

};

#endif
