#include<iostream>
#include<cstring>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;

class ppp{public: int k;int j;int shi;
};
stack <ppp> zsy;
int n;
int se[100005] = {0}; 
int tu[100005] = {0}; 

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        se[a] = i;
        tu[i] = a;
    }
    for(int i = 1; i <= n;i++)
    {
        if(tu[i] == 0) continue;
        else
        {
            ppp temp;
            temp.k = i;
            temp.j = se[tu[i]];
            temp.shi = 1;
            zsy.push(temp);
            i = se[tu[i]];
        }
    }
    int sss = 0; 
    while(!zsy.empty())
    {
        ppp temp = zsy.top();
        if(temp.shi > sss) sss = temp.shi;
        zsy.pop();
        for(int i = temp.k + 1; i <= temp.j-1;i++)
        {
            if(tu[i] == tu[temp.k]) continue;
            if(tu[i] == 0)
            {
                cout << -1 << endl;
                return 0;
            }
            if(tu[i] != tu[temp.k] && se[tu[i]] > temp.j)
            {
                cout << -1 << endl;
                return 0;
            }
            ppp temp1;
            temp1.k = i;
            temp1.j = se[tu[i]];
            temp1.shi = temp.shi + 1;
            zsy.push(temp1);
            i = se[tu[i]];
        }
    }
    cout << sss << endl;
    return 0; 
} 
