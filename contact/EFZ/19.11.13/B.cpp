#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int MAXN=1e5+5;
const int MAXT=MAXN*4;
char s[MAXN];
int n,M,rt;
struct tnode{
	int l,r,cl,cr;
	ll dat,pre,plen;
	ll suf,psuf;
} t[MAXT];
int newnode(int l,int r,int cl,int cr,ll dat,ll pre,ll plen,ll suf,ll psuf){
	t[++M]=(tnode){l,r,cl,cr,dat,pre,plen,suf,psuf};
	return M;
}
int build(int l,int r){
	if (l==r) return newnode(l,r,cl,cr
