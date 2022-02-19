#include<iostream>
for (int s=1;s<(1<<4);s++){
	for (int ss=(s-1)&s;ss>0;ss=(ss-1)&s){

