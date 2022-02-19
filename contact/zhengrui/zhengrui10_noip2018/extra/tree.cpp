int m;
int sum[5][102*4+10][1002*4+10];
void pushup(int rt,int xrt){
    sum[1][xrt][rt]=max(sum[1][xrt][rt*2],sum[1][xrt][rt*2+1]);
    sum[2][xrt][rt]=max(sum[2][xrt][rt*2],sum[2][xrt][rt*2+1]);
    sum[3][xrt][rt]=max(sum[3][xrt][rt*2],sum[3][xrt][rt*2+1]);
    sum[4][xrt][rt]=max(sum[4][xrt][rt*2],sum[4][xrt][rt*2+1]);
}
void buildy(int rt,int left,int right,int xrt){
    for (int k=1;k<=4;k++) sum[k][xrt][rt] = -1;
    if(left != right){
        int mid=(left+right)/2;
        buildy(rt*2,left,mid,xrt);
        buildy(rt*2+1,mid+1,right,xrt);
    }
}
void build(int rt,int left,int right){
    buildy(1,0,n,rt);
    if(left!=right){
        int mid=(left+right)/2;
        build(rt*2,left,mid);
        build(rt*2+1,mid+1,right);
    }
}
void updatey(int rt,int left,int right,int y,int ad1,int ad2,int ad3,int ad4,int xrt){
    if(left==right&&left==y){
        sum[1][xrt][rt]=max(sum[1][xrt][rt],ad1);
        sum[2][xrt][rt]=max(sum[2][xrt][rt],ad2);
        sum[3][xrt][rt]=max(sum[3][xrt][rt],ad3);
        sum[4][xrt][rt]=max(sum[4][xrt][rt],ad4);
        return;
    }
    int mid=(left+right)/2;
    if(y<=mid) updatey(rt*2,left,mid,y,ad1,ad2,ad3,ad4,xrt);
    if(y>mid) updatey(rt*2+1,mid+1,right,y,ad1,ad2,ad3,ad4,xrt);
    pushup(rt,xrt);
}
void update(int rt,int left,int right,int x,int y,int ad1,int ad2,int ad3,int ad4){
     updatey(1,0,n,y,add,rt);
     if(left!=right){
         int mid=(left+right)/2;
         if(x<=mid) update(rt*2,left,mid,x,y,ad1,ad2,ad3,ad4);
         if(x>mid)  update(rt*2+1,mid+1,right,x,y,ad1,ad2,ad3,ad4);
     }
}
void queryY(int rt,int left,int right,int y1,int y2,int xrt,int id){
    if(left>=y1&&right<=y2){
        mx=max(mx,sum[id][xrt][rt]);
        return;
    }
    int mid=(right+left)/2;
    if(y1<=mid) queryY(rt*2,left,mid,y1,y2,xrt,id);
    if(y2>mid) queryY(rt*2+1,mid+1,right,y1,y2,xrt,id);
}
void query(int rt,int left,int right,int x1,int y1,int x2,int y2,int id){
    if(left>=x1&&right<=x2){
        queryY(1,0,n,y1,y2,rt,id);
        return ;
    }
    int mid=(left+right)/2;
    if(x1<=mid) query(rt*2,left,mid,x1,y1,x2,y2,id);
    if(x2>mid) query(rt*2+1,mid+1,right,x1,y1,x2,y2,id);
}
