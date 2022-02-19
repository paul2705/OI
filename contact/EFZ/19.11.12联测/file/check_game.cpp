#include<iostream>
#include<cstdio>
using namespace std;
int cnt;
int main(){
	while (1){
		cnt++;
		cout<<cnt<<endl;
		system("getin_game");
		system("game");
		system("game_bl");
		if (system("fc game.out game.ans")) break;
	}
	return 0;
}
