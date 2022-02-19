#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void shuffle(char s[][5]){
	strcpy(s[2],"xg");
}
int main(){
	char s[5][5]={"jac","re","we","re"};
	for (int i=0;i<4;i++) printf("%s\n",s[i]);
	shuffle(s);
	for (int i=0;i<4;i++) printf("%s\n",s[i]);
	return 0;
}
