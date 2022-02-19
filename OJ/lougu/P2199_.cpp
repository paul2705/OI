#include<cstdio>
#include<algorithm>
#include<vector>
#define LL long long
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)>(b))?(b):(a))
#define For(a,b,c,d) for(register int a=b;a<=c;a+=d)
#define FOR(a,b,c,d) for(register int a=b;a<c;a+=d)
#define Rep(a,b,c,d) for(register int a=b;a>=c;a-=d)
#define REP(a,b,c,d) for(register int a=b;a>c;a-=d)
#define INF 0xffffff

const int N = 230 , mx[ 4 ] = { 1 , 0 , -1 , 0 } , my[ 4 ] = { 0 , 1 , 0 , -1 } ;
int n , m , r ; 
int a[ N ][ N ] , ans[ N ] , b[ N ] , minn ;

inline void Swap( int i , int j , int p ) {
    For( k , p , r , 1 ) {
        std::swap( a[ i ][ k ] , a[ j ][ k ] ) ;
    }
}

inline void Xor( int i , int j , int p ) {
    For( k , p , r , 1 ) {
        a[ i ][ k ] ^= a[ j ][ k ] ;
    }
}

void dfs( int res , int cnt ) {
    if( cnt > minn )
        return ;
    if( res < 0 ) {
        FOR( i , 0 , r , 1 ) {
            ans[ i ] = b[ i ] ;
        }
        minn = Min( minn , cnt ) ;
        return ; 
    }
    if( !a[ res ][ res ] && a[ res ][ r ] ) {
        return ;
    }
    std::vector< int > vis ;
    if( !a[ res ][ res ] && !a[ res ][ r ] ) {
        b[ res ] = a[ res ][ r ] = 1 ;
        Rep( j , res - 1 , 0 , 1 ) {
            if( a[ j ][ res ] ) {
                a[ j ][ r ] ^= 1 ;
                vis.push_back( j ) ;
            }
        }
        dfs( res - 1 , cnt + 1 ) ;
        Rep( j , vis.size() - 1 , 0 , 1 ) {
            a[ vis[ j ] ][ r ] ^= 1 ;
        }
        a[ res ][ r ] = b[ res ] = 0 ; 
        dfs( res - 1 , cnt ) ;
        return ;
    }
    b[ res ] = a[ res ][ r ] ;
    if( b[ res ] ) {
        Rep( j , res - 1 , 0 , 1 ) {
            if( a[ j ][ res ] ) {
                a[ j ][ r ] ^= 1 ;
                vis.push_back( j ) ;
            }
        }
        dfs( res - 1 , cnt + b[ res ] ) ; 
        Rep( j , vis.size() - 1 , 0 , 1 ) {
            a[ vis[ j ] ][ r ] ^= 1 ;
        }
    }
    else {
        dfs( res - 1 , cnt ) ;
    }
}

int main() {
    scanf("%d %d ", &n , &m ) ;
    int t , p , tx , ty ;
    r = m * n ;
    FOR( i , 0 , n , 1 ) {
        FOR( j , 0 , m , 1 ) {
            p = i * m + j ;
            scanf("%d", &t ) ;
            if( t )
                a[ p ][ r ] = 1 ;
            a[ p ][ p ] = 1 ;
            For( k , 0 , 3 , 1 ) {
                tx = i + mx[ k ] ;
                ty = j + my[ k ] ;
                if( tx < 0 || ty < 0 || tx >= n || ty >= m )
                    continue ; 
                a[ tx * m + ty ][ p ] = 1 ;
            }
        } 
    }
    bool flag ;
    FOR( i , 0 , r , 1 ) {
        flag = 0 ;
        FOR( j , i , r , 1 ) {
            if( a[ j ][ i ] ) {
                flag = 1 ;
                Swap( j , i , i ) ;
                break ;
            }
        }
        if( !flag )
            continue ;
        FOR( j , i + 1 , r , 1 ) {
            if( a[ j ][ i ] )
                Xor( j , i , i ) ;
        }
    }
    minn = INF ;
    dfs( r - 1 , 0 ) ;
    if( minn == INF ) {
        printf("IMPOSSIBLE") ;
        exit( 0 ) ;
    }
    FOR( i , 0 , n , 1 ) {
        FOR( j , 0 , m , 1 ) {
            printf("%d " , ans[ i * m + j ] ) ;
        }
        printf("\n") ;
    }
    return 0 ;
} 
