#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
#define ll long long
const int N = 500010;
struct node
{
    ll v;
    int id;
    bool operator <(node b) const
    {
        return v < b.v;
    }
};
ll a[N], ans;
int l[N], r[N];
bool bj[N];
priority_queue<node> q;
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        q.push((node){a[i], i});
        l[i] = i-1, r[i] = i+1;
    }
    int len = n;
    for(int i = 1; i <= k; i++)
    {
        while(!q.empty() && bj[q.top().id]) q.pop();
        if(q.empty() || q.top().v < 0) break;
        node t = q.top();q.pop();
        ans += t.v;
        bj[t.id] = bj[l[t.id]] = bj[r[t.id]] = 1;
        a[++len] = a[l[t.id]]+a[r[t.id]]-a[t.id];
        int l1 = l[t.id], r1 = r[t.id];
	l[len] = l[l1], r[len] = r[r1];
	r[l[len]] = len, l[r[len]] = len;
	q.push((node){a[len], len});
    }
    printf("%lld\n", ans);
    return 0;
}
