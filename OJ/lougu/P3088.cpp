#include<bits/stdc++.h>
using namespace std;
pair<int,int> q[50050];
multiset<int > x,y;
int main(){
    int n,d;
    scanf("%d%d",&n,&d);
    for (int i=0;i<n;i++)
        scanf("%d%d",&q[i].first,&q[i].second);
    sort(q,q+n);
    int k=0,j=0,ans=0;
    for (int i=0;i<n;i++){
        while (k<n && q[i].first+d>=q[k].first)
            y.insert(q[k++].second);
        while (q[i].first-d>q[j].first)
            x.erase(x.find(q[j++].second));
        x.insert(q[i].second);
        if (*--x.end()>=q[i].second*2 && *--y.end()>=q[i].second*2) 
            ans++;
        y.erase(y.find(q[i].second));
    }
    cout<<ans;
    return 0;
}
