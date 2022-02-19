#include <bits/stdc++.h>

#define MAXN 300010
#define endl '\n'
#define oo (1ll<<64)

using namespace std;

typedef long long ll;

ll N, A[MAXN], dp[MAXN][2], ans;

int main(){

    #ifndef ONLINE_JUDGE
        freopen( "a.in", "r", stdin );
    #endif // ONLINE_JUDGE

	ios_base::sync_with_stdio( false );
	cin.tie( NULL ), cout.tie( NULL );

	cin >> N;

    for ( ll i = 1; i <= N; ++i ){
        cin >> A[i];
        A[i] = __builtin_popcountll( A[i] );
    }

    dp[0][0] = 1;
    for ( ll i = 1, j, mx, sum, psum = 0; i <= N; ++i ){
        sum = mx = 0;
        for ( j = i; j > 0 && i-j < 65; --j ){
            sum += A[j];
            mx = max( mx, A[j] );
            if ( mx > sum-mx && sum%2 == 0 )
                --ans;
        }
        psum += A[i];
        ans += dp[i-1][psum&1];
        dp[i][0] = dp[i-1][0];
        dp[i][1] = dp[i-1][1];
        if ( psum&1 )
            ++dp[i][1];
        else
            ++dp[i][0];
    }

//    for ( int i = 1; i <= N; ++i ){
//        for ( int j = 0; j < 2; ++j )
//            cout << dp[i][j] << ' ';
//        cout << endl;
//    }

    cout <<  ans << '\n';

return 0;
}
