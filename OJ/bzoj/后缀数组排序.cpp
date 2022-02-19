//str--权重
//a--原序列
//b--新序列
void radix(int str[],int a[],int b[]){
	memset(c,sizeof(c),0);
	for (int i=0;i<n;i++) ++c[a[i]];
	for (int i=1;i<300000;i++) c[i]+=c[i-1];
	for (int i=n-1;i>=0;i--){
		c[str[a[i]]--;
		b[c[str[a[i]]]]=a[i];
	}
}
int main(){
	for (int i=0;(1<<i)<n;i++){
		for (j=0;j<n;j++){
			k[j]=rank[j]+1;
			if (j+(1<<i)<n) rk[j]=rank[j+(1<<i)]+1;
			else rk[j]=0;
		}
	}
	radix(rk,t,tt);
	radix(k,tt,sa);
	//SA=rank^(-1) rank[3]=3号的排名 SA[7]=第7名的位置
	rank[sa[0]]=0;
	for (int i=1;i<n;i++){
		x=sa[i],y=sa[i-1];
		if (k[x]==k[y]&&rk[x]==rk[y]) rank[x]=rank[y];
		else rank[x]=rank[y]+1;
	}
	return 0;
]
