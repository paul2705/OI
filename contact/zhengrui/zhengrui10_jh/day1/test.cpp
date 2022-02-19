#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
multiset<int> s;
int main(){
	s.insert(2); s.insert(2);
	for (multiset<int>::iterator it=s.begin();it!=s.end();it++){
		cout<<" :"<<(*it)<<endl;
	}
	s.erase(2);
	for (multiset<int>::iterator it=s.begin();it!=s.end();it++){
		cout<<(*it)<<endl;
	}
	return 0;
}
