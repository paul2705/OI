#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct card{
	int x,y;
};
struct card a[5];
int main(){
	a[1]=(struct card){1,3};
	return 0;
}
