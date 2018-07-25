#Railway Communication Model 1
In this folder a Code Example for explaining the structure of Rebeca can be found.

## Prerequisites
During this thesis Ubuntu 17.10 was used as Operating System. 
RW-CM-1 is tested with/needs following packages:
-Java 1.8.0_x
-gcc version 7.2.0 
-graphviz version 2.38.0

##How to run
The source code of the example can be found in src. To start the modelchecking process with RMC run make.sh in src/. This also will generate a Graph.png and statespace.xml.

For using the workaround:
java -jar statespace_viewer_1_1.jar 
The workaround tries to reads in statespace.xml per default. The current version of the workaround does not support a generic read in. Please check if a statespace.xml exists before starting the workaround.
