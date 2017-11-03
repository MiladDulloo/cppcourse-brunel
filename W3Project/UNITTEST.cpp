// UNITTEST google tests

#include <iostream>
#include <cmath>
#include "Neuron.hpp"
#include "gtest/gtest.h"

TEST (NeuronTest, PositiveInput) {
	
	Neuron n1;
	n1.set_Iext(1);
	
	// Testing update
	
	n1.Neurupdate(1);
	EXPECT_EQ(20.0*(1.0-std::exp(-0.1/20.0)), n1.get_V());
	
	n1.Neurupdate(10000);
	
	EXPECT_EQ(0,n1.get_spike_num());
	EXPECT_GT(1E-3, std::fabs(19.999 - n1.get_V()));
	
	n1.set_Iext(0.0);
	
	n1.Neurupdate(2000);
	EXPECT_NEAR(0, n1.get_V(), 1e-3);
}

TEST (NeuronTest, StandaloneSimulation) {
	Neuron n1;
	n1.set_Iext(1.01);
	n1.Neurupdate(4000);
	EXPECT_EQ(4, n1.get_spike_num());
}

TEST (TwoNeurons, NoPSSpike) {
	Neuron n1, n2;
	int delay = 15;
	n1.set_Iext(1.01);
	
	for (auto i=0; i<925+delay; i++){
		if(n1.Neurupdate(1))
		{
			n2.spike_reception(i + static_cast<unsigned long>(delay), 0.1);
			EXPECT_EQ(0.0,n1.get_V());
		} 
	
	n2.Neurupdate(1);
	}
	

	EXPECT_EQ(0.1, n2.get_V());
	}
	


TEST (TwoNeurons, WithPSSpike) {
	Neuron n1, n2;
	int delay = 15;
	n1.set_Iext(1.01);
	n2.set_Iext(1.0);
	for (auto i=0; i<923+delay;i++){
		if(n1.Neurupdate(1))
		{
			n2.spike_reception(i+static_cast<unsigned long>(delay), 0.1);
			EXPECT_EQ(0.0, n1.get_V());
		}
		n2.Neurupdate(1);
	}
	
	EXPECT_EQ(0,n2.get_spike_num());
	n2.Neurupdate(1);
	EXPECT_EQ(0, n2.get_V());
	EXPECT_EQ(1, n2.get_spike_num());
    }
   
   


int main(int argc, char **argv) 
{
		::testing::InitGoogleTest(&argc, argv);
		return RUN_ALL_TESTS();
}
		
