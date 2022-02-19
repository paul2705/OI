#include<bits/stdc++.h>

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double llf;
typedef std::pair<int,int> pii;

#define xx first
#define yy second

template<typename T> inline T max(T a,T b){return a>b?a:b;}
template<typename T> inline T min(T a,T b){return a<b?a:b;}
template<typename T> inline T abs(T a){return a>0?a:-a;}
template<typename T> inline bool repr(T &a,T b){return a<b?a=b,1:0;}
template<typename T> inline bool repl(T &a,T b){return a>b?a=b,1:0;}
template<typename T> inline T gcd(T a,T b){T t;if(a<b){while(a){t=a;a=b%a;b=t;}return b;}else{while(b){t=b;b=a%b;a=t;}return a;}}
template<typename T> inline T sqr(T x){return x*x;}
#define mp(a,b) std::make_pair(a,b)
#define pb push_back
#define I __attribute__((always_inline))inline
#define mset(a,b) memset(a,b,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))

#define fo0(i,n) for(int i=0,i##end=n;i<i##end;i++)
#define fo1(i,n) for(int i=1,i##end=n;i<=i##end;i++)
#define fo(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define fd0(i,n) for(int i=(n)-1;~i;i--)
#define fd1(i,n) for(int i=n;i;i--)
#define fd(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define foe(i,x)for(__typeof((x).end())i=(x).begin();i!=(x).end();++i)
#define fre(i,x)for(__typeof((x).rend())i=(x).rbegin();i!=(x).rend();++i)

struct Cg{I char operator()(){return getchar();}};
struct Cp{I void operator()(char x){putchar(x);}};
#define OP operator
#define RT return *this;
#define UC unsigned char
#define RX x=0;UC t=P();while((t<'0'||t>'9')&&t!='-')t=P();bool f=0;\
if(t=='-')t=P(),f=1;x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define RL if(t=='.'){lf u=0.1;for(t=P();t>='0'&&t<='9';t=P(),u*=0.1)x+=u*(t-'0');}if(f)x=-x
#define RU x=0;UC t=P();while(t<'0'||t>'9')t=P();x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define TR *this,x;return x;
I bool IS(char x){return x==10||x==13||x==' ';}template<typename T>struct Fr{T P;I Fr&OP,(int&x)
{RX;if(f)x=-x;RT}I OP int(){int x;TR}I Fr&OP,(ll &x){RX;if(f)x=-x;RT}I OP ll(){ll x;TR}I Fr&OP,(char&x)
{for(x=P();IS(x);x=P());RT}I OP char(){char x;TR}I Fr&OP,(char*x){char t=P();for(;IS(t);t=P());if(~t){for(;!IS
(t)&&~t;t=P())*x++=t;}*x++=0;RT}I Fr&OP,(lf&x){RX;RL;RT}I OP lf(){lf x;TR}I Fr&OP,(llf&x){RX;RL;RT}I OP llf()
{llf x;TR}I Fr&OP,(uint&x){RU;RT}I OP uint(){uint x;TR}I Fr&OP,(ull&x){RU;RT}I OP ull(){ull x;TR}};Fr<Cg>in;
#define WI(S) if(x){if(x<0)P('-'),x=-x;UC s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
#define WL if(y){lf t=0.5;for(int i=y;i--;)t*=0.1;if(x>=0)x+=t;else x-=t,P('-');*this,(ll)(abs(x));P('.');if(x<0)\
x=-x;while(y--){x*=10;x-=floor(x*0.1)*10;P(((int)x)%10+'0');}}else if(x>=0)*this,(ll)(x+0.5);else *this,(ll)(x-0.5);
#define WU(S) if(x){UC s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
template<typename T>struct Fw{T P;I Fw&OP,(int x){WI(10);RT}I Fw&OP()(int x){WI(10);RT}I Fw&OP,(uint x){WU(10);RT}
I Fw&OP()(uint x){WU(10);RT}I Fw&OP,(ll x){WI(19);RT}I Fw&OP()(ll x){WI(19);RT}I Fw&OP,(ull x){WU(20);RT}I Fw&OP()
(ull x){WU(20);RT}I Fw&OP,(char x){P(x);RT}I Fw&OP()(char x){P(x);RT}I Fw&OP,(const char*x){while(*x)P(*x++);RT}
I Fw&OP()(const char*x){while(*x)P(*x++);RT}I Fw&OP()(lf x,int y){WL;RT}I Fw&OP()(llf x,int y){WL;RT}};Fw<Cp>out;

const int base = 1000000000;
const int base_digits = 9;

struct bigint {
	std::vector<int> z;
	int sign,id;

	bigint() :
		sign(1) {
	}

	bigint(long long v) {
		*this = v;
	}

	bigint(const std::string &s) {
		read(s);
	}

	void operator=(const bigint &v) {
		sign = v.sign;
		id = v.id;
		z = v.z;
	}

	void operator=(long long v) {
		sign = 1;
		if (v < 0)
			sign = -1, v = -v;
		z.clear();
		for (; v > 0; v = v / base)
			z.push_back(v % base);
	}

	bigint operator+(const bigint &v) const {
		if (sign == v.sign) {
			bigint res = v;

			for (int i = 0, carry = 0; i < (int) max(z.size(), v.z.size()) || carry; ++i) {
				if (i == (int) res.z.size())
					res.z.push_back(0);
				res.z[i] += carry + (i < (int) z.size() ? z[i] : 0);
				carry = res.z[i] >= base;
				if (carry)
					res.z[i] -= base;
			}
			return res;
		}
		return *this - (-v);
	}

	bigint operator-(const bigint &v) const {
		if (sign == v.sign) {
			if (abs() >= v.abs()) {
				bigint res = *this;
				for (int i = 0, carry = 0; i < (int) v.z.size() || carry; ++i) {
					res.z[i] -= carry + (i < (int) v.z.size() ? v.z[i] : 0);
					carry = res.z[i] < 0;
					if (carry)
						res.z[i] += base;
				}
				res.trim();
				return res;
			}
			return -(v - *this);
		}
		return *this + (-v);
	}

	void operator*=(int v) {
		if (v < 0)
			sign = -sign, v = -v;
		for (int i = 0, carry = 0; i < (int) z.size() || carry; ++i) {
			if (i == (int) z.size())
				z.push_back(0);
			long long cur = z[i] * (long long) v + carry;
			carry = (int) (cur / base);
			z[i] = (int) (cur % base);
			//asm("divl %%ecx" : "=a"(carry), "=d"(a[i]) : "A"(cur), "c"(base));
		}
		trim();
	}

	bigint operator*(int v) const {
		bigint res = *this;
		res *= v;
		return res;
	}

	friend std::pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) {
		int norm = base / (b1.z.back() + 1);
		bigint a = a1.abs() * norm;
		bigint b = b1.abs() * norm;
		bigint q, r;
		q.z.resize(a.z.size());

		for (int i = a.z.size() - 1; i >= 0; i--) {
			r *= base;
			r += a.z[i];
			int s1 = b.z.size() < r.z.size() ? r.z[b.z.size()] : 0;
			int s2 = b.z.size() - 1 < r.z.size() ? r.z[b.z.size() - 1] : 0;
			int d = ((long long) s1 * base + s2) / b.z.back();
			r -= b * d;
			while (r < 0)
				r += b, --d;
			q.z[i] = d;
		}

		q.sign = a1.sign * b1.sign;
		r.sign = a1.sign;
		q.trim();
		r.trim();
		return std::make_pair(q, r / norm);
	}

	friend bigint sqrt(const bigint &a1) {
		bigint a = a1;
		while (a.z.empty() || a.z.size() % 2 == 1)
			a.z.push_back(0);

		int n = a.z.size();
		
		int firstDigit = (int) sqrt((double) a.z[n - 1] * base + a.z[n - 2]);
		int norm = base / (firstDigit + 1);
		a *= norm;
		a *= norm;
		while (a.z.empty() || a.z.size() % 2 == 1)
			a.z.push_back(0);
		
		bigint r = (long long) a.z[n - 1] * base + a.z[n - 2];
		firstDigit = (int) sqrt((double) a.z[n - 1] * base + a.z[n - 2]);
		int q = firstDigit;
		bigint res;
 
		for(int j = n / 2 - 1; j >= 0; j--) {
			for(; ; --q) {
				bigint r1 = (r - (res * 2 * base + q) * q) * base * base + (j > 0 ? (long long) a.z[2 * j - 1] * base + a.z[2 * j - 2] : 0);
				if (r1 >= 0) {
					r = r1;
					break;
				}
			}
			res *= base;
			res += q;

			if (j > 0) {
				int d1 = res.z.size() + 2 < r.z.size() ? r.z[res.z.size() + 2] : 0;
				int d2 = res.z.size() + 1 < r.z.size() ? r.z[res.z.size() + 1] : 0;
				int d3 = res.z.size() < r.z.size() ? r.z[res.z.size()] : 0;
				q = ((long long) d1 * base * base + (long long) d2 * base + d3) / (firstDigit * 2);
			}		   
		}
		
		res.trim();
		return res / norm;
	}

	bigint operator/(const bigint &v) const {
		return divmod(*this, v).first;
	}

	bigint operator%(const bigint &v) const {
		return divmod(*this, v).second;
	}

	void operator/=(int v) {
		if (v < 0)
			sign = -sign, v = -v;
		for (int i = (int) z.size() - 1, rem = 0; i >= 0; --i) {
			long long cur = z[i] + rem * (long long) base;
			z[i] = (int) (cur / v);
			rem = (int) (cur % v);
		}
		trim();
	}

	bigint operator/(int v) const {
		bigint res = *this;
		res /= v;
		return res;
	}

	int operator%(int v) const {
		if (v < 0)
			v = -v;
		int m = 0;
		for (int i = z.size() - 1; i >= 0; --i)
			m = (z[i] + m * (long long) base) % v;
		return m * sign;
	}

	void operator+=(const bigint &v) {
		*this = *this + v;
	}
	void operator-=(const bigint &v) {
		*this = *this - v;
	}
	void operator*=(const bigint &v) {
		*this = *this * v;
	}
	void operator/=(const bigint &v) {
		*this = *this / v;
	}

	bool operator<(const bigint &v) const {
		if (sign != v.sign)
			return sign < v.sign;
		if (z.size() != v.z.size())
			return z.size() * sign < v.z.size() * v.sign;
		for (int i = z.size() - 1; i >= 0; i--)
			if (z[i] != v.z[i])
				return z[i] * sign < v.z[i] * sign;
		return false;
	}

	bool operator>(const bigint &v) const {
		return v < *this;
	}
	bool operator<=(const bigint &v) const {
		return !(v < *this);
	}
	bool operator>=(const bigint &v) const {
		return !(*this < v);
	}
	bool operator==(const bigint &v) const {
		return !(*this < v) && !(v < *this);
	}
	bool operator!=(const bigint &v) const {
		return *this < v || v < *this;
	}

	void trim() {
		while (!z.empty() && z.back() == 0)
			z.pop_back();
		if (z.empty())
			sign = 1;
	}

	bool isZero() const {
		return z.empty() || (z.size() == 1 && !z[0]);
	}

	bigint operator-() const {
		bigint res = *this;
		res.sign = -sign;
		return res;
	}

	bigint abs() const {
		bigint res = *this;
		res.sign *= res.sign;
		return res;
	}

	long long longValue() const {
		long long res = 0;
		for (int i = z.size() - 1; i >= 0; i--)
			res = res * base + z[i];
		return res * sign;
	}

	friend bigint gcd(const bigint &a, const bigint &b) {
		return b.isZero() ? a : gcd(b, a % b);
	}
	friend bigint lcm(const bigint &a, const bigint &b) {
		return a / gcd(a, b) * b;
	}

	void read(const std::string &s) {
		sign = 1;
		z.clear();
		int pos = 0;
		while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) {
			if (s[pos] == '-')
				sign = -sign;
			++pos;
		}
		for (int i = s.size() - 1; i >= pos; i -= base_digits) {
			int x = 0;
			for (int j = max(pos, i - base_digits + 1); j <= i; j++)
				x = x * 10 + s[j] - '0';
			z.push_back(x);
		}
		trim();
	}

	friend std::istream& operator>>(std::istream &stream, bigint &v) {
		std::string s;
		stream >> s;
		v.read(s);
		return stream;
	}

	friend std::ostream& operator<<(std::ostream &stream, const bigint &v) {
		if (v.sign == -1)
			stream << '-';
		stream << (v.z.empty() ? 0 : v.z.back());
		for (int i = (int) v.z.size() - 2; i >= 0; --i)
			stream << std::setw(base_digits) << std::setfill('0') << v.z[i];
		return stream;
	}

	static std::vector<int> convert_base(const std::vector<int> &a, int old_digits, int new_digits) {
		std::vector<long long> p(max(old_digits, new_digits) + 1);
		p[0] = 1;
		for (int i = 1; i < (int) p.size(); i++)
			p[i] = p[i - 1] * 10;
		std::vector<int> res;
		long long cur = 0;
		int cur_digits = 0;
		for (int i = 0; i < (int) a.size(); i++) {
			cur += a[i] * p[cur_digits];
			cur_digits += old_digits;
			while (cur_digits >= new_digits) {
				res.push_back(int(cur % p[new_digits]));
				cur /= p[new_digits];
				cur_digits -= new_digits;
			}
		}
		res.push_back((int) cur);
		while (!res.empty() && res.back() == 0)
			res.pop_back();
		return res;
	}

	typedef std::vector<long long> vll;

	static vll karatsubaMultiply(const vll &a, const vll &b) {
		int n = a.size();
		vll res(n + n);
		if (n <= 32) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					res[i + j] += a[i] * b[j];
			return res;
		}

		int k = n >> 1;
		vll a1(a.begin(), a.begin() + k);
		vll a2(a.begin() + k, a.end());
		vll b1(b.begin(), b.begin() + k);
		vll b2(b.begin() + k, b.end());

		vll a1b1 = karatsubaMultiply(a1, b1);
		vll a2b2 = karatsubaMultiply(a2, b2);

		for (int i = 0; i < k; i++)
			a2[i] += a1[i];
		for (int i = 0; i < k; i++)
			b2[i] += b1[i];

		vll r = karatsubaMultiply(a2, b2);
		for (int i = 0; i < (int) a1b1.size(); i++)
			r[i] -= a1b1[i];
		for (int i = 0; i < (int) a2b2.size(); i++)
			r[i] -= a2b2[i];

		for (int i = 0; i < (int) r.size(); i++)
			res[i + k] += r[i];
		for (int i = 0; i < (int) a1b1.size(); i++)
			res[i] += a1b1[i];
		for (int i = 0; i < (int) a2b2.size(); i++)
			res[i + n] += a2b2[i];
		return res;
	}

	bigint operator*(const bigint &v) const {
		std::vector<int> a6 = convert_base(this->z, base_digits, 6);
		std::vector<int> b6 = convert_base(v.z, base_digits, 6);
		vll a(a6.begin(), a6.end());
		vll b(b6.begin(), b6.end());
		while (a.size() < b.size())
			a.push_back(0);
		while (b.size() < a.size())
			b.push_back(0);
		while (a.size() & (a.size() - 1))
			a.push_back(0), b.push_back(0);
		vll c = karatsubaMultiply(a, b);
		bigint res;
		res.sign = sign * v.sign;
		for (int i = 0, carry = 0; i < (int) c.size(); i++) {
			long long cur = c[i] + carry;
			res.z.push_back((int) (cur % 1000000));
			carry = (int) (cur / 1000000);
		}
		res.z = convert_base(res.z, 6, base_digits);
		res.trim();
		return res;
	}
};

const int N=10005,M=100007;

int n,ans[N];
bigint s[N],sma,req;
std::vector<int>fax,fay;

inline std::vector<bigint> solve(bigint req)
{
	std::cout<<"start solve: "<<req<<std::endl;
	std::vector<bigint>res;
	//static int ccc=0;ccc++;
	if(req>sma/16)
	{
		auto s=solve(req/2);
		std::sort(s.begin(),s.end());
		for(int i=0,j=s.size()-1;i<s.size();i++)
		{
			for(;~j&&s[i]+s[j]>req;j--)
			{
				bigint tmp=s[i]+s[j];
				tmp.id=fax.size();
				fax.pb(s[i].id);
				fay.pb(s[j].id);
				res.pb(tmp);
			}
			if(!~j)break;
			bigint tmp=s[i]+s[j];
			tmp.id=fax.size();
			fax.pb(s[i].id);
			fay.pb(s[j].id);
			res.pb(tmp);
		}
	}
	if(req<sma*2||res.size()<M)
	{
		fo1(i,n)res.pb(s[i]);
	}
	std::sort(res.begin(),res.end(),[&](const bigint&a,const bigint&b){
		return abs(a-req)<abs(b-req);
	});
	res.resize(std::unique(res.begin(),res.end())-res.begin());
	while(res.size()>M)res.pop_back();
	std::cout<<"solve ok: "<<req<<std::endl;
	std::cout<<"best: "<<res[0]<<' '<<res[0].id<<std::endl;
	return res;
}

inline void dfs(int x)
{
	assert(x);
	//out,"dfs:",x,'\n';
	if(x<=n)
	{
		ans[x]++;
		return;
	}
	dfs(fax[x]);
	dfs(fay[x]);
}

int main()
{
	freopen("data\\x9.in","r",stdin);
	in,n;
	std::cin>>req;
	//req/=2000000;
	fo0(i,10)(int)in;
	fo1(i,n)
	{
		std::cin>>s[i];
		(ll)in;
	}
	fo1(i,n)s[i].id=i;
	fo(i,0,n)fax.pb(i);
	fo(i,0,n)fay.pb(i);
	std::sort(s+1,s+n+1);
	sma=*std::max_element(s+1,s+n+1);
	auto t=solve(req);
	dfs(t[0].id);
	freopen("data\\x9.out","w",stdout);
	fo1(i,n)out,ans[i],'\n';
}
