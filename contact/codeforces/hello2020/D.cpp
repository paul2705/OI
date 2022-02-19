#include <iostream>
#include <ctime>
#include <functional>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>
//#define int long long
using namespace std;
 
struct Event{
    int x;
    int mean;
    int sb;
    int eb;
    Event(int x, int mean, int sb, int eb): x(x), mean(mean), sb(sb), eb(eb){}
    Event(): x(-1), mean(-1), sb(-1), eb(-1){}
};
 
bool comp(Event a, Event b){
    return make_pair(a.x, a.mean) < make_pair(b.x, b.mean);
}
 
int n;
bool check(Event* events){
    multiset<int> end;
    multiset<int> start;
    sort(events, events + 2 * n, comp);
    for (int i=0; i<2 * n; ++i){
        Event e = events[i];
        if (e.mean == 0){
            if (!start.empty()){
                int max_start = *(start.rbegin());
                int min_end = *(end.begin());
                if (max_start > e.eb || min_end < e.sb)
                    return false;
            }
            end.insert(e.eb);
            start.insert(e.sb);
        }else{
            end.erase(end.find(e.eb));
            start.erase(start.find(e.sb));
        }
    }
    return true;
}
 
 
signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    cin >> n;
    Event events1[2 * n];
    Event events2[2 * n];
    for (int i=0; i<n; ++i){
        int sa, ea, sb, eb;
        cin >> sa >> ea >> sb >> eb;
        events1[i * 2] = Event(sa, 0, sb, eb);
        events1[i * 2 + 1] = Event(ea, 1, sb, eb);
        events2[i * 2] = Event(sb, 0, sa, ea);
        events2[i * 2 + 1] = Event(eb, 1, sa, ea);
    }
    if (check(events1) && check(events2))
        cout << "YES\n";
    else
        cout << "NO\n";
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}
