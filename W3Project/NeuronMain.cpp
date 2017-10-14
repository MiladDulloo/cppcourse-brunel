#include "Neuron.hpp"
#include <iostream>
using namespace std;

int main()
{
	Neuron n1;
	double t_stop;
	
	cout << " enter simulation time : " << endl;
	cin >> t_stop;
	cout << "t_stop = ";
	
	n1.Neurupdate(t_stop);
	
	return 0;
};
