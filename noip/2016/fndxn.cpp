#include<cstdio>
#include<cstring>
#include<cmath> 
using namespace std;

const int MAXN = 18;
const int MAXM = 262144;
struct Point
{
    double x,y;
};
Point nd[MAXN+2];
int sol[MAXN*MAXN+MAXN];
int g[MAXM+2];
int n,m,c,s;

void solve(double a1,double b1,double c1,double a2,double b2,double c2,double *ansx,double *ansy)
{
    if(a1*b2 != a2*b1)
    {
        *ansx = (b2*c1-b1*c2)/(a1*b2-a2*b1);
        *ansy = (a1*c2-a2*c1)/(a1*b2-a2*b1);
    }
}

void DFS(int pos,int cod,double a,double b)
{
    int i,j;
    double arga,argb;

    if(pos == n) return;
    if(cod == 0)
    {
        for(i=0; i<n; i++)
        {
            for(j=i+1; j<n; j++)
            {
                if(nd[i].x != nd[j].x)
                {
                    solve(nd[i].x*nd[i].x,nd[i].x,nd[i].y,nd[j].x*nd[j].x,nd[j].x,nd[j].y,&arga,&argb);
                    if(arga < -1e-6)
                    {
                        DFS(j,(1<<i)+(1<<j),arga,argb);
                    }
                }
            }
        }
    }
    else
    {
        for(i=pos+1; i<n; i++)
        {
            if(fabs(nd[i].x*nd[i].x*a+nd[i].x*b-nd[i].y) < 1e-12)
            {
                DFS(i,cod+(1<<i),a,b);
                return;
            }
        }
        sol[s] = cod;
        g[cod] = 1;
        s++;
    }
}

bool match(int spos,int gpos)
{
    int i;
    for(i=n-1; i>=0; i--)
    {
        if((sol[spos]&(1<<i)) && (gpos&(1<<i))) return false;
    }
    return true;
}

int main()
{
    int t,i,j;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&c);
        m = 1<<n;
        for(i=0; i<n; i++)
        {
            scanf("%lf%lf",&nd[i].x,&nd[i].y);
        }

        if(n == 1)
        {
            printf("1\n");
            continue;
        }
        memset(g,42,sizeof(g));
        memset(sol,0,sizeof(sol));
        s = 0;
        for(i=0; i<n; i++)
        {
            sol[s++] = 1<<i;
            g[1<<i] = 1;
        }
        DFS(0,0,0.0,0.0);

        g[0] = 0;
        for(j=0; j<s; j++)
        {
            for(i=0; i<m; i++)
            {
                if(g[i|sol[j]] > g[i]+1) g[i|sol[j]] = g[i]+1;
            }
        }

        printf("%d\n",g[m-1]);
    }

    return 0;
}
