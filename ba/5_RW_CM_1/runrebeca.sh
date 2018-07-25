#!/bin/bash

sourcee=$1
output=$sourcee'_output'
graph=$3

rmc='rmc-2.6.0-SNAPSHOT.jar'
transformer='statespacetransformer-1.0.0-SNAPSHOT.jar'
echo $sourcee

	echo 'write c++ files...'

echo 	java -jar $rmc -s $sourcee -e $2 -o rmc -x
	java -jar $rmc -s $sourcee -e $2 -o rmc -x

	echo 'compile c++...'
	g++  rmc/*.cpp -w -o rmc/executeable

	echo 'execute model...'
	echo 'write into '$output'...'
	rmc/executeable -o $output


echo 'convert states for graphviz...'
java -jar $transformer -e CoreRebeca -s statespace.xml -o states -t GRAPH_VIZ

echo 'create graph...'
if [ ! -n $graph ]
then
   $graph='dot'
fi
$graph -Tpng states -o Graph.png

echo 'End'

