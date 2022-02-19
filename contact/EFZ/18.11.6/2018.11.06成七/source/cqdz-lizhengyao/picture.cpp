#include<cstdio>
#include<algorithm>
#include<cstring>
//#include<iostream>
using namespace std;
inline int read() {
	int a = 0, c = getchar(), w = 1;
	for(; c < '0' || c > '9'; c = getchar()) if(c == '-') w = -1;
	for(; c >= '0' && c <= '9'; c = getchar()) a = a * 10 + c - '0';
	return a * w;
}

const int maxn = 1000050;
int n, m, n2, m2;
char a[maxn], t[maxn];
int s[2][maxn];

int gcd(int x, int y) {
	return y ? gcd(y, x%y) : x;
}

int en, em;

inline long long calc1(long long row, long long rgt, int typ) {
	long long wrgt = rgt / em;
//	cout<<"C1 "<<row<<", "<<rgt<<" TYP "<<typ<<" = "<<(wrgt?s[typ][row*m+wrgt-1]:0) + ((a[row*m+wrgt]-'0')==typ?rgt-wrgt*em+1:0)<<endl;
	return (wrgt?s[typ][row*m+wrgt-1]:0)*em + ((a[row*m+wrgt]-'0')==typ?rgt-wrgt*em+1:0);
}

inline long long calc(long long up, long long down, long long lft, long long rgt, int typ) {
//	cout<<"CALC "<<up<<", "<<down<<", "<<lft<<", "<<rgt<<" TYP "<<typ<<endl;
	if(up/en == down/en) {
//		cout<<"SM"<<endl;
		long long width = down - up + 1;
//		cout<<"Ret "<<calc1(up/en, rgt, typ) * width - (lft ? calc1(up/en, lft-1, typ) * width : 0)<<endl;
		return calc1(up/en, rgt, typ) * width - (lft ? calc1(up/en, lft-1, typ) * width : 0);
	}else{
//		cout<<"DF"<<endl;
	    long long downwidth = down - down/en*en + 1, upwidth = down/en*en - up;
//	    cout<<"Ret "<<(calc1(down/en, rgt, typ)-(lft?calc1(down/en,lft-1,typ):0))*downwidth + 
//		       (calc1(up/en, rgt, typ)-(lft?calc1(up/en,lft-1,typ):0))*upwidth <<endl;
		return (calc1(down/en, rgt, typ)-(lft?calc1(down/en,lft-1,typ):0))*downwidth + 
		       (calc1(up/en, rgt, typ)-(lft?calc1(up/en,lft-1,typ):0))*upwidth ;
	}
}

int main() {
	freopen("picture.in", "r", stdin);
	freopen("picture.out", "w", stdout);
	n = read(); m = read(); scanf("%s", a);
	n2 = read(); m2 = read(); 
	if(n2 < n) {
		swap(n, n2); swap(m, m2);
		strcpy(t, a);
		scanf("%s", a);
	}else scanf("%s", t);
	for(int i = 0; i < n; i++) {
		s[1][i*m] = a[i*m] - '0'; s[0][i*m] = '1' - a[i*m];
		for(int j = 1; j < m; j++) {
		    s[1][i*m+j] = s[1][i*m+j-1] + a[i*m+j] - '0';
		    s[0][i*m+j] = s[0][i*m+j-1] + '1' - a[i*m+j];
		}
	}
//	for(int i = 0; i < n; i++) {
//		for(int j = 0; j < m; j++) cout<<s[1][i*m+j]<<" ";
//		cout<<endl;
//	}
	int gn = gcd(n, n2), gm = gcd(m, m2), sn = n / gn, sm = m / gm;
	en = n2 / gn; em = m2 / gm;
	long long ans = 0;
	long long up = 0, down = sn, lft = 0, rgt = sm;
	ans += calc(up, down-1, lft, rgt-1, t[0]-'0');
	for(int j = 1; j < m2; j++) {
		lft += sm; rgt += sm;
		ans += calc(up, down-1, lft, rgt-1, t[j]-'0');
	}
	for(int i = 1; i < n2; i++) {
		up += sn; down += sn; lft = 0; rgt = sm;
		ans += calc(up, down-1, lft, rgt-1, t[i*m2]-'0');
		for(int j = 1; j < m2; j++) {
			lft += sm; rgt += sm;
			ans += calc(up, down-1, lft, rgt-1, t[i*m2+j]-'0');
		}
	}
	printf("%lld\n", ans);
	return 0;
}
