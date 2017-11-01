#include "Neuron.hpp"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	Neuron n1;

//Simulation Time
	
	double t_stop;
	
	double t_start = 0;
	
//User enters simulation stop time t_stop
	
	cout << " enter simulation time : " << endl;
	cin >> t_stop;
	cout << "t_stop = " << t_stop;
	cout << endl;
	
//User enters external current Iext 

	cout << " enter external Current input : " << endl;
	double newIext;
	cin >> newIext;
	n1.set_Iext(newIext);
	cout << "new external current = " << n1.get_Iext() << endl;
	
//Update of n1	

	n1.Neurupdate(t_stop);
	
//Simulation

  ofstream MembranePotentials;
  MembranePotentials.open ("MembranePot.txt");
  MembranePotentials << "Membrane potentials" << endl;
  
for(t_start; t_start < t_stop ; ++t_start)
{
	bool spiked = n1.Neurupdate(1);
	

}
  
  
  MembranePotentials.close();
	
	return 0;
};
