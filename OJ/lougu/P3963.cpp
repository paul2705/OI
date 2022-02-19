#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#define llint long long
using namespace std;
int set_[200010],cnt[200010];
struct node{
        node *lson,*rson;
        int val,sum_;
        node(int ql,int qr,bool full){
                // build a void tree
                if(ql == qr){
                        lson = rson = NULL;
                        val = full * cnt[ql];sum_ = val * set_[ql];
                }
                else{
                        int mid = ((qr - ql) >> 1) + ql;
                        lson = new node(ql,mid,full);
                        rson = new node(mid + 1,qr,full);
                        val = full * (lson->val + rson->val);
                        sum_ = full * (lson->sum_ + rson->sum_);
                }
        }
        node(node *ori,node *ls,node *rs,int ival){
                lson = ls;rson = rs;
                val = ori->val + 1;sum_ = ori->sum_ + set_[ival];
        }
        node* insert(int ival,int l,int r){
                int mid = ((r - l) >> 1) + l;
                if (ival == l && ival == r)
                        return new node(this,NULL,NULL,ival);
                if (ival <= mid)
                        return new node(this,lson->insert(ival,l,mid),rson,ival);
                else 
                        return new node(this,lson,rson->insert(ival,mid + 1,r),ival);
        }

}*full,*suf[200010];
int query(node *op,int k,int l,int r){
        int mid = ((r - l) >> 1) + l;
        if (l == r)
                return k * set_[l];
        if (k <= op->lson->val)
                return query(op->lson,k,l,mid);
        else 
                return op->lson->sum_ + query(op->rson,k - op->lson->val,mid + 1,r);
}
int query2(node *op,node *ff,int k,int l,int r){
        int mid = ((r - l) >> 1) + l;
        if (l == r)
                return k * set_[l];
        if (k <= ff->lson->val - op->lson->val)
                return query2(op->lson,ff->lson,k,l,mid);
        else 
                return ff->lson->sum_ - op->lson->sum_ + query2(op->rson,ff->rson,k -(ff->lson->val -  op->lson->val),mid + 1,r);
}

struct xxx{
        int score,money;
        bool operator < (const xxx &be)const{
                return score < be.score;
        }
}data[200010];
int main (){
//      freopen("wb.in","r",stdin);
        //readin
        int n,k,p;
        cin>> k >> n >> p;
        for (int i = 1;i <= n;++ i){
                scanf("%d%d",&data[i].score,&data[i].money);
        }
        sort(data + 1,data + 1 + n);
        //discrete
        for (int i = 1;i <= n;++ i)
                set_[i] = data[i].money;
        sort(set_ + 1,set_ + 1 + n);
        int size_ = unique(set_ + 1,set_ + 1 + n) - set_ - 1;
        for (int i = 1;i <= n;++ i)
                data[i].money = lower_bound(set_ + 1,set_ + size_ + 1,data[i].money) - set_,
                cnt[data[i].money] ++;
        //build trees
        suf[n + 1] = new node (1,size_,0);
        full = new node (1,size_,1);
        for (int i = n;i > n - (k >> 1);-- i)
                suf[i] = suf[i + 1]->insert(data[i].money,1,size_);
        //query
        for (int i = n - (k >> 1);i > (k >> 1);-- i){
                suf[i] = suf[i + 1]->insert(data[i].money,1,size_);
                if(query2(suf[i],full,k >> 1,1,size_) + query(suf[i + 1],k >> 1,1,size_) + set_[data[i].money] <= p){
                        cout << data[i].score;
                        return 0;
                }
        }
        cout << -1 ;
        return 0;
}
