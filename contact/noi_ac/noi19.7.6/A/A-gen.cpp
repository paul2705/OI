#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main() {
	freopen("A.in","w",stdout);
	printf("%d %d %d\n", 1000, 1000, 1000);
	for (int i = 1; i < 1000; i++) cout << rand()%100 << endl;
	for (int i = 1; i <= 1000; i++) cout << rand()%1000+1 << " " << rand() << endl;
	fclose(stdin); fclose(stdout);
	return 0;
}
