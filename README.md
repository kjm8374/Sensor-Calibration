# Sensor-Calibration
This program was developed for me to understand how to improve the accuracy of a sensor.
The basic logic to this is I try to model the error and then subtract it from the input data to produce more accurate results.
My approach is to model the sensor error function, generate a matching polynomial and then simulate the effects of the correction polynomial on the results.

# Makefile

```UNIX
make all 
```
makes hw11.c and correction.c files

```UNIX
make plot
```
makes a plot called 'graph.png' which displays the graph.

```UNIX
display graph.png
```
displays the graph
