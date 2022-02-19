#include <iostream>  
#include <cstdio>
#include <algorithm>    
using namespace std;

int mark[1000002] = {0},zheng[1000002] = {0},jy[1000002] = {0};
int zd = 0,zdgg = 1,n,fs = 0,sxzs = 1;

class zsy{public: int z;int g;}g[1000002];

bool bi(int x,int y){return y < x;}

int dfs(int dq,int gg)
{
    if(gg >= sxzs) gg = sxzs - 1;
    if(dq <= jy[gg]) return 0;
    jy[gg] = dq;
    if(dq + zheng[gg] > zd) zd = dq + zheng[gg];
    for(int i = 0; i < fs;i++)
    {
        if(!mark[i])
        {
            mark[i] = 1;
            dfs(dq + g[i].z,gg + g[i].g - 1);
            mark[i] = 0;
        }
    }
    return 0;
} 

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int t1,t2;
        cin >> t1 >> t2;
        if(t1 > 0 && t2 > 0)
        {
            zd += t2;
            zdgg += t1 - 1;
        }
        else if(t1 < 2 && t2 <= 0) continue;
        else
        {
            if(t2 > 0) zheng[sxzs++] = t2;
            else 
            {
                g[fs].g = t1;
                g[fs].z = t2;
                fs++;
            }
        }
    }
    sort(zheng + 1,zheng + sxzs + 1,bi);
    jy[1] = -0x3f3f3f;
    jy[0] = -0x3f3f3f;
    for(int i = 2; i < sxzs ;i++)
    {
        zheng[i] = zheng[i - 1] + zheng[i];
        jy[i] = -0x3f3f3f;
    }
    dfs(zd,zdgg);
    cout << zd;
    return 0;
} 
