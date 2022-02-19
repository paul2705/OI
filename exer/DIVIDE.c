#include<stdio.h>

int bisect(int interval[],int i,int b,int temp)
{
	if (interval[0]==interval[1]-1){
		if ((1<<interval[1])<b) return interval[1];
		else return interval[0];
	}
	if (interval[0]==interval[1]) return interval[0];
//	printf("%d %d\n",interval[0],interval[1]);
	temp=(interval[0]+interval[1])/2;
   i=1<<temp;
	if (i<=b)
   {
      interval[0]=temp;
      temp=bisect(interval,i,b,temp);
      return temp;
   }
   if (i>b)
   {
      interval[1]=temp-1;
      temp=bisect(interval,i,b,temp);
      return temp;
   }
	return 0;
}

int main (void)
{
   int b,interval[2],i=1,place,temp;
   if(scanf("%d",&b)){};
   interval[0]=0;
   interval[1]=31;
   temp=interval[0]+interval[1];
   place=bisect(interval,i,b,temp);
   printf("%d",place);
return 0;
}
