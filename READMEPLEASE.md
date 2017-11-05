# CS116-2017-milad-dulloo-
Info SV BA3

This project has for objective the implementation of a neural stimulation network from the Brunel paper :
*Dynamics of Sparsely Connected Networks of Excitatory
and Inhibitory Spiking Neurons*

                                          ** Neural Network:**
                                      -10'000 excitatory neurons
                                      -2'500 inhibitory neurons
                                      -Connections generated randomly
                                      
Classes:
  Neuron.hpp : neuron modelization with
                                          - external current input "Iext"
                                          - membrane potential V
                                          - 
                                           




To run the simulation:

  1) Download the github depository from https://github.com/MiladDulloo/cppcourse-brunel
  2) Open the terminal and change to the directory containing the downloaded repositaroy with the project file.
  3) Change directory to the "build" folder, you should be somwhere like: ~/whereyoudownloadedtherep/CS116-2017-milad-dulloo-   /W3Project/build$
  4) Enter the following command in the terminal: make
  5) Enter the following command in the terminal: ./neuron

To visualize spikes plot:
  1) Go to https://try.jupyter.org/
  2) Upload the "Membrane.txt" located in: cppcourse-brunel/W3Project/build
  3) On the top right menu select "New/Python 3"
  4) Write the following code:
   import numpy as np
   import matplotlib.pyplot as pl
   data = np.genfromtxt('MembranePot.txt')
   select= np.array([d for d in data if d[1] < 30])
   data1= select.transpose()
   pl.scatter(0.1*data1[0],data1[1],alpha=0.8, edgecolors='none');
   pl.show();
   n, bins, patches = pl.hist(0.1*data1[0], 50, normed=0, alpha=0.75)
   pl.show();
  5) Click "RUN"
