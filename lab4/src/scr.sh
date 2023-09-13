#!/bin/bash
var=2
N=0
while [[ $var -eq 2 ]] && [[ $N -ne 2000 ]] 
do
var=$(./$1)
N=$(($N+1))
done
echo $N
