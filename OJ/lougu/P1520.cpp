#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=5e3+5;
struct poly{int cof[5001];int size;} CIR[5001];
int factor[5000];
poly FACTOR[400];
int counter = 0;
bool cmp(int aa, int bb){return aa<bb;}
bool cmp2(poly aa, poly bb)
{
    if (aa.size<bb.size)    return 1;
    if (aa.size>bb.size)return 0;
    for (int i = aa.size;i>=0;i--)
    {
        if (abs(aa.cof[i])<abs(bb.cof[i]))    return 1;
        if (abs(aa.cof[i])>abs(bb.cof[i]))return 0;
        if (aa.cof[i]<0 && bb.cof[i]>0)    return 1;
        if (aa.cof[i]>0 && bb.cof[i]<0)    return 0;
    }
    return 1;
}
int divisionPoly(poly* A, poly* B, poly* aim)
{
    int sizeA = A->size;
    int sizeB = B->size;
    if (sizeA<sizeB)    return -1;
    poly AIM;
    memset(AIM.cof, 0, sizeof(AIM.cof));
    AIM.size = sizeA-sizeB;
    int s = AIM.size;
    poly A_ = *A;
    while (s+1)
    {
        int k = A_.cof[s+B->size];
        AIM.cof[s] = k;
        for (int i = B->size;i>=0;i--)
        {
            A_.cof[i+s] -= k*B->cof[i];
        }

        s--;
    }
    *aim = AIM;
    return 0;
}
int output(poly* a) 
{
    int flag = 1;
    for (int i = a->size;i>=0;i--)
    {
        if (a->cof[i]==0)continue;
        if (i==0)
        {
            if (a->cof[i]>0 && !flag)    cout<<"+";
            cout<<a->cof[i];
            continue;
        }
        if (flag)
        {
            flag = 0;if (a->cof[i]<0)cout<<'-';
        }
        else
        {
            if (a->cof[i]>0)    cout<<'+';
            else cout<<"-";
        }
        int t = (a->cof[i]>0?a->cof[i]:-(a->cof[i]));
        if (t!=1)cout<<t;
        if (i==1)cout<<"x";
        else cout<<"x^"<<i;
    }
    return 0;
}
int main()
{
    int n = 0;
    cin>>n;
    if (n==1)
    {
        cout<<"x-1";
        return 0;
    }

    for (int i = 1;i<=sqrt(n);i++)    if (n%i==0)
    {
        factor[++counter] = i;
        if (i*i!=n)    factor[++counter] = n/i;
    }
    sort(factor+1, factor+1+counter, cmp); 

    for (int i = 1;i<=counter;i++) 
    {
        int t = factor[i];
        CIR[t].cof[t] = 1;
        CIR[t].cof[0] = -1;
        CIR[t].size = t;

        for (int k = 1;k<=(int)sqrt(t);k++)    if (t%k==0)
        {
            if (t==1)break;
            divisionPoly(&CIR[t], &CIR[k], &CIR[t]);
            if (k*k!=t && k!=1)
                divisionPoly(&CIR[t], &CIR[t/k], &CIR[t]);
        }        
        FACTOR[i] = CIR[t];

    }
    sort(FACTOR+1, FACTOR+counter+1, cmp2);
    for (int i = 1;i<=counter;i++)
    {
        cout<<"(";
        output(&FACTOR[i]);
        cout<<")";

    }
    return 0;
}
