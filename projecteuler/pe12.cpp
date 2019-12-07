/*************************************************************************
    > File Name: pe12.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月19日 星期四 22时21分38秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int getans(){
    int cnum = 1, ci = 1, ccount;
    while(true){
        cnum += ++ci;
        ccount = 1;
        for(int i = 2; i <= cnum/2; i++)
            ccount += (cnum % i == 0);
        if(ccount == 500)
            return cnum;
    }
}

vector<long long> allp;
bool book[6];

int main(){
    //printf("%d\n", getans());
    long long cans, ci, ti;
    allp.push_back(2);
    for(long long i = 3; i < 20000; i++){
        bool flag = true;
        for(int j = 0; j < allp.size() && allp[j]*allp[j] <= i; j++)
            if(i % allp[j] == 0){
                flag = false;
                break;
            }
        if(flag)
            allp.push_back(i);
    }
    printf("allp done...\n");
    //之前不知道为什么脑子抽了，各种抽下面一一列举
    //首先素数跑太多，事实上2w就够了
    //然后分解质因数方法错误
    //最后开始了奇妙的分析，陷入了这是一道需要碰运气的数学题的状态...
    //最终在搜索了dalao的做法后成功悬崖勒马，回归正轨...
    
    for(long long i = 1; ; i++){
        ti = i*(i+1)/2;
        cans = 1;
        ci = 0;
        for(int j = 0; j < allp.size() && allp[j]*allp[j] <= ti; j++){
            if(ti%allp[j] == 0){
                ci = 1;
                while(ti%allp[j] == 0){
                    ti /= allp[j];
                    ci++;
                }
                cans *= ci;
            }
        }
        if(ti != 1)
            cans *= 2;
        if(cans > 500){
            printf("%lld\n", i*(i+1)/2);
            break;
        }
        if(!book[cans/100]){
            printf("%lld found...\n", cans/100);
            book[cans/100] = true;
        }
    }
	return 0;
}

