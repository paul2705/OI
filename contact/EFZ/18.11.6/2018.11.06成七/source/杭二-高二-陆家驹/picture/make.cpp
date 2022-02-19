#include<cstdio>
#include<cstdlib>
#include<ctime>
int main()
{
	freopen("picture.in","w",stdout);
	srand(time(0));
	int h=rand()%30+1,w=rand()%30+1;
	printf("%d %d\n",h,w);
	for (int i=1;i<=h*w;i++) printf("%d",rand()%2); puts("");
	h=rand()%30+1,w=rand()%30+1;
	printf("%d %d\n",h,w);
	for (int i=1;i<=h*w;i++) printf("%d",rand()%2); puts("");
	return 0;
}
