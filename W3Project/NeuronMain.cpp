#include "Neuron.hpp"
#include <iostream>
using namespace std;

int main()
{
	Neuron n1;
	double t_stop;
//User enters simulation stop time t_stop	
	cout << " enter simulation time : " << endl;
	cin >> t_stop;
	cout << "t_stop = ";
//User enters external current Iext	
	cout << " enter external Current input : " << endl;
	double newIext;
	cin >> newIext;
	n1.set_Iext(newIext);
	cout << "new external current = " << n1.get_Iext() << endl;
	
//Update of n1		
	n1.Neurupdate(t_stop);
	
	
//
	
	
	return 0;
};
