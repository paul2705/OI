#include<cstdio>
using namespace std;
const int N=1007;
int n,input[N],stack1[N],stack2[N],ans[2*N],ansid;
int outputting=1,stackid1,stackid2;
bool failed;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&input[i]);
    for(int i=1;i<=n;i++){
        bool mayienterstack1=true;
        int all=input[i]-outputting;
        if(outputting!=input[i]&&stackid1!=0)
            for(int j=i+1;j<=n;j++){
                if(input[j]>=outputting&&input[j]<input[i])
                    all--;
                if(all==0)
                    break;
                if(input[j]>stack1[stackid1])
                    break;
                if(input[j]>stack2[stackid2]&&stackid2>0){
                    mayienterstack1=false;
                    break;
                }
            }
        if((mayienterstack1&&input[i]<stack1[stackid1])||stackid1==0||outputting==input[i]){
            stack1[++stackid1]=input[i];
            ans[++ansid]=0;
        }else if(input[i]<stack2[stackid2]||stackid2==0){
            stack2[++stackid2]=input[i];
            ans[++ansid]=2;
        }else {
            failed=true;
            break;
        }
        while(1){
            if(outputting==stack1[stackid1]){
                stackid1--;
                outputting++;
                ans[++ansid]=1;
            }else if(outputting==stack2[stackid2]){
                stackid2--;
                outputting++;
                ans[++ansid]=3;
            }else break;
        }
    }
    if(failed)
        printf("0\n");
    else {
        for(int i=1;i<ansid;i++)
            printf("%c ",ans[i]+'a');
        printf("%c\n",ans[ansid]+'a');
    }
return 0;}
