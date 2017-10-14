#ifndef NEURON_H
#define NEURON_H

class Neuron
{
	
	
	double Iext;	// Input current
	double V;	// Membrane potential
	double spike_t; 	// time of last spike
	double spike_num;	// number of spikes
	double local_t;		// local time of neuron
//Integration- firing of spikes - calculation for pot
	double C_E;		// number of Excitatory connections recieved
	double C_I;		// number of Inhibitory connections recieved3
	double Vext; 	// frequency of external input (background activity)
	const double R;	// membrane resistance
	const double Tau;	// membrane time constant (ms)
	const double thld;	// spike Potential threshold sigma
	const double Vreset;		// reset potential
	const double refrac_t;	// refractory period duration (ms)
	const double h;	// equidistant time-steps
	const double refrac_steps;
	double const1;		// constant for pot calculation
	double const2;		// constant for pot calculation

public:		
	Neuron();	// constructor

// getters	
	double get_Iext();
	
	double get_V() const;
	
	double get_spike_t() const;
	
	double get_spike_num() const;
	
	
// setters
	void set_Iext(double newExtI);

// Update function	
	bool Neurupdate(double steps);
	
};

#endif
