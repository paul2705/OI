#include<iostream>
#include<set>
#include<map>

using namespace std;
const int maxn = 1 << 19;
const int maxm = 300001;

unsigned int ans = 0;

int n;
int tag[maxn << 1];
int first[maxn << 1], last[maxn << 1];
unsigned int minval[maxn << 1];

multimap<pair<int, int>, int> idmap;

bool inOpt[maxn+1];
int opt_best_id[maxn << 1];
int pending_best_id[maxn << 1];
map<int, multiset<pair<int, int> > > pending_store;

int d[maxm], p[maxm];

void s_gen(int pos, int left, int right) {
  if (left == right) {
    last[pos] = first[pos] = left;
    minval[pos] = left;    
  } else {
    int mid = (left + right) / 2;
    s_gen(pos*2,    left, mid);
    s_gen(pos*2+1, mid+1, right);
    minval[pos] = last[pos] = first[pos] = left;
  }
}

void s_add(int begin, int delta, int pos, int left, int right) {
  if (right < begin) {
    return;
  }
  if (begin <= left) {
    tag[pos] += delta;
    minval[pos] += delta;
    return;
  }
  int mid = (left + right) / 2;
  int lc = 2 * pos;
  int rc = 2 * pos + 1;
  s_add(begin, delta, lc, left, mid);
  s_add(begin, delta, rc, mid+1, right);
  if (minval[lc] < minval[rc]) {
    minval[pos] = minval[lc] + tag[pos];
    first[pos] = first[lc];
    last[pos] = last[lc];
  } else if (minval[rc] < minval[lc]) {
    minval[pos] = minval[rc] + tag[pos];
    first[pos] = first[rc];
    last[pos] = last[rc];  
  } else {
    minval[pos] = minval[rc] + tag[pos];
    first[pos] = first[lc];
    last[pos] = last[rc];  
  }
}

int s_first(int begin, int pos, int left, int right) {
  if (right < begin) {
    return 0;
  }
  if (begin <= left) {
    if (minval[pos] == 0) return first[pos];
    else return 0;
  }
  int mid = (left + right) / 2;
  
  int lc = pos * 2;
  int rv = s_first(begin, lc, left, mid);
  if (rv != 0) return rv;
  
  int rc = lc + 1;
  rv = s_first(begin, rc, mid+1, right);
  if (rv != 0) return rv;

  return 0;  
}

int s_last(int end, int pos, int left, int right) {
  if (end < left) {
    return 0;
  }
  if (right <= end) {
    if (minval[pos] == 0) return last[pos];
    else return 0;
  }
  int mid = (left + right) / 2;
  
  int lc = pos * 2;
  int rc = lc + 1;
  
  int rv = s_last(end, rc, mid+1, right);
  if (rv != 0) return rv;
  
  rv = s_last(end, lc, left, mid);  
  if (rv != 0) return rv;

  return 0;  
}

void opt_update_by_child(int pos) {
  int lc = pos * 2;
  int lc_id = opt_best_id[lc];

  int rc = lc + 1;
  int rc_id = opt_best_id[rc];

  if (rc_id == 0) 
    opt_best_id[pos] = lc_id;
  else if (lc_id == 0) 
    opt_best_id[pos] = rc_id;
  else {
    if (p[lc_id] < p[rc_id]) {
      opt_best_id[pos] = lc_id;
    } else {
      opt_best_id[pos] = rc_id;
    }
  }
}

void opt_set(int pos, int id) {
  opt_best_id[pos] = id;
  while (pos > 1) {
    pos = pos / 2;
    opt_update_by_child(pos);
  }  
}

void add(int id) {
  ans += p[id];
  inOpt[id] = true;
  s_add(d[id], -1, 1, 1, maxn);  
  int pos = maxn - 1 + d[id];  
  opt_set(pos, id);
}

void del(int id) {
  ans -= p[id];
  inOpt[id] = false;
  s_add(d[id], 1, 1, 1, maxn);
  int pos = maxn - 1 + d[id];  
  opt_set(pos, 0);
}

void pending_update_by_child(int pos) {
  int lc = pos * 2;
  int lc_id = pending_best_id[lc];

  int rc = lc + 1;
  int rc_id = pending_best_id[rc];

  if (rc_id == 0) 
    pending_best_id[pos] = lc_id;
  else if (lc_id == 0) 
    pending_best_id[pos] = rc_id;
  else {
    if (p[lc_id] > p[rc_id]) {
      pending_best_id[pos] = lc_id;
    } else {
      pending_best_id[pos] = rc_id;
    }
  }
}


void pending_set(int pos, int id) {
  pending_best_id[pos] = id;
  while (pos > 1) {
    pos = pos / 2;
    pending_update_by_child(pos);
  }  
}


void pending_add(int id) {
  int pos = maxn - 1 + d[id];
  pair<int, int> entry = make_pair(p[id], id);
  pending_store[d[id]].insert(entry);
  multiset<pair<int, int> > :: iterator iter = pending_store[d[id]].end();
  iter--; 
  int best_id = iter -> second;
  if (best_id == id) pending_set(pos, id);
}

void pending_del(int id) {
  int pos = maxn - 1 + d[id];
  pair<int, int> entry = make_pair(p[id], id);
  pending_store[d[id]].erase(pending_store[d[id]].find(entry));
  if (pending_store[d[id]].size() > 0) {
  multiset<pair<int, int> > :: iterator iter = pending_store[d[id]].end();
  iter--;      
  int id = iter -> second;   
     pending_set(pos, id);  
  } else {
     pending_set(pos, 0);  
  }
}


int pending_max(int begin, int pos, int left, int right) {
  if (right < begin) {
    return 0;
  } 
  if (begin <= left) {
    return pending_best_id[pos];
  }
  int mid = (left + right) / 2;
  int lc = pos * 2;
  int rc = lc + 1;
  int lc_id = pending_max(begin, lc, left, mid);
  int rc_id = pending_max(begin, rc, mid+1, right);
  if (lc_id == 0) return rc_id;
  if (rc_id == 0) return lc_id;
  if (p[rc_id] > p[lc_id]) 
    return rc_id; 
  else 
    return lc_id;
}

int opt_min(int begin, int pos, int left, int right) {
  if (right < begin) {
    return 0;
  } 
  if (begin <= left) {
    return opt_best_id[pos];
  }
  int mid = (left + right) / 2;
  int lc = pos * 2;
  int rc = lc + 1;
  int lc_id = opt_min(begin, lc, left, mid);
  int rc_id = opt_min(begin, rc, mid+1, right);
  if (lc_id == 0) return rc_id;
  if (rc_id == 0) return lc_id;
  if (p[rc_id] < p[lc_id]) 
    return rc_id; 
  else 
    return lc_id;
}

int main() {
  int m;
  int newid = 0;
  cin >> n >> m;
  s_gen(1, 1, maxn);
 
  while(m --> 0) {

    string cmd;
    int dd, pp;
    cin >> cmd >> dd >> pp;

    if (cmd == "ADD") {
      newid++;
      d[newid] = dd;
      p[newid] = pp;
      int k = s_first(dd, 1, 1, maxn);
      if (k == 0) {
         add(newid); 
      } else {
         int victim = opt_min(k, 1, 1, maxn);
         if (p[victim] < p[newid]) {
            del(victim);
            add(newid);
            pending_add(victim);
         } else {
            pending_add(newid);
         }
      }
      pair<int,int> entry = make_pair(dd, pp);
      idmap.insert(make_pair(entry, newid));
      
    }
    if (cmd == "DEL") {
      // todo int id = get(dd, pp);
      pair<int,int> entry = make_pair(dd, pp);
      multimap<pair<int, int>,int>::iterator iter = 
	    idmap.find(entry);
	  int id = iter->second;
	  idmap.erase(iter);
      
      if (!inOpt[id]) {
        pending_del(id);
      } else {
        del(id);
        int k = s_last(d[id], 1, 1, maxn); 
        if (k == -1) {
          k = 1;
        }
        int best_id = pending_max(k, 1, 1, maxn);
        if (best_id != 0) {
          pending_del(best_id);
          add(best_id);          
        }
      }
      // todo: 
      // del (d[i], p[i]) to multimap;    
    } 
    cout << ans << endl;   
  }
}

