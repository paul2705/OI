#include <cstdio>
#define MaxNode 100001
#define f(i , a , b) for(int i=a ; i <= b ; i++)
int Input()
{
    char c=getchar();
    int n=0;
    while(c  < '0' || c  > '9') c=getchar();
    while(c >= '0' && c <= '9') n=(n << 1)+(n << 3)+(c-48) , c=getchar();
    return n;
}
int v[MaxNode*3];
int Find(int n)
{
    return v[n] == n ? n : (v[n]=Find(v[n]));
}
int main()
{
    int n=Input() , m=Input() , a , b , c , s=0;
    f(i , 1 , n*3) v[i]=i;
    f(i , 1 , m)
    {
        a=Input() , b=Input() , c=Input();
        if(b > n || c > n) s++; else
        if(a == 1)
            if(Find(b+n) == Find(c) || Find(b) == Find(c+n)) s++; else
            v[Find(b)]=v[Find(c)] , v[Find(b+n)]=v[Find(c+n)] , v[Find(b+n*2)]=v[Find(c+n*2)];
        else
            if(Find(b) == Find(c) || Find(b) == Find(c+n)) s++; else
            v[Find(b+n)]=v[Find(c)] , v[Find(b+n*2)]=v[Find(c+n)] , v[Find(b)]=v[Find(c+n*2)];
    }
    printf("%d" , s);
    return 0;
}
