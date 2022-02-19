#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
using namespace std;
map<char,char> list;
map<char,char> list2; 
int main() 
{
    string code,recode,homework;
    list.clear();
    list2.clear(); 
    getline(cin,code);
    getline(cin,recode);
    getline(cin,homework);
    int len=code.size();
    for(int i=0;i<len;i++)
    {
        if((list.count(code[i])!=0&&list[code[i]]!=recode[i])||(list2.count(recode[i])!=0&&list2[recode[i]]!=code[i]))
        {
            cout<<"Failed"<<endl;
            return 0;
        }
        else
        {
            list.insert(pair<char,char>(code[i],recode[i]));
            list2.insert(pair<char,char>(recode[i],code[i]));
        }
    } 
    if(list.size()<26)
    {
        cout<<"Failed"<<endl;
        return 0;
    }
    int ll=homework.size();
    for(int i=0;i<ll;i++)
        if(list.count(homework[i])==0)
        {
            cout<<"Failed"<<endl;
            return 0;
        }
    for(int i=0;i<ll;i++)
        cout<<list[homework[i]];
    return 0;
}
