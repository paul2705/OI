#include<cstdio>
#include<ctime>
#include<algorithm>
using namespace std;
#define gi Get_int()
#define gui Get_unsigned_int()
#define gd Get_double()
#define gud Get_unsigned_double()
#define ra rand()
inline int fh					 (void){return ra%2?1:-1;}//符号
inline int Get_unsigned_int		 (void){return ra*ra;}//正整数
inline int Get_int				 (void){return gui*fh();}//整数
inline double Get_double		 (void){return 1.0*gi/100;}//小数
inline double Get_unsigned_double(void){return 1.0*gui/100;}//正小数
const int mod=1E5+10,T=2;/*数据组数*/
int n,m;
int main(){
	srand(time(0));
    freopen("picture.in","w",stdout);
	//gi整数,gui正整数,gd小数,gud正小数,fh符号
	for(int ii=1;ii<=T;ii++){
		n=gui%mod+1;m=1000000/n;
		printf("%d %d\n",n,m);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				printf("%d",gui%2);
			}
		}puts("");
	}
	return 0;
}
