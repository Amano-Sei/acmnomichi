//Memory Time
//204K   0MS
 
#include <iostream>
#include <cstring>
#include <map>
using namespace std;
 
int main(int i,int k)
{
    int test,c;
    int t=0;
    cin>>test;
    while(++t<=test)
    {
        cin>>c;
        char s1[201];   //牌堆1
        char s2[201];   //牌堆2
        char s12[401];  //预设最终的牌堆状态
        cin>>s1>>s2>>s12;
 
        map<string,bool>vist;   //记录出现过的洗牌状态(map缺省值为0)
        vist[s12]=true;
 
        int step=0;  //洗牌次数
        while(true)
        {
            char s[201];  //当前s1与s2洗牌后的状态
            int ps=0;  //s[]指针
            for(i=0;i<c;i++)    //s1与s2洗牌
            {
                s[ps++]=s2[i];
                s[ps++]=s1[i];
            }
            s[ps]='\0';
 
            step++;
             
            if(!strcmp(s,s12))   //当洗牌后的状态能达到预设状态时，输出
            {
                cout<<t<<' '<<step<<endl;
                break;
            }
            else if(vist[s] && strcmp(s,s12))  //当前洗牌后状态 与 前面出现过的状态重复了，但该状态不是预设状态
            {                                  //说明预设的状态无法达到
                cout<<t<<' '<<-1<<endl;
                break;
            }
 
            vist[s]=true;   //状态记录
 
            for(i=0;i<c;i++)   //分拆出s1与s2
                s1[i]=s[i];
            s1[i]='\0';
 
            for(k=0;i<2*c;i++,k++)
                s2[k]=s[i];
            s2[i]='\0';
        }
    }
    return 0;
}
