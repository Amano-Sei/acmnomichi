/*************************************************************************
    > File Name: pe41.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月18日 星期五 23时40分13秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

//显然8和9是3的倍数不会是质数
//以及只找了14个就找到了...完全没必要跑出来所有的7位以内的质数...

const int maxn = 10000005;

bool isp[maxn];
vector<int> allp;
int cnt;

void init(){
    isp[2] = true;
    for(int i = 3; i < maxn; i++){
        bool flag = true;
        for(int j = 0; j < allp.size() && allp[j]*allp[j] <= i; j++)
            if(i%allp[j] == 0){
                flag = false;
                break;
            }
        if(flag){
            isp[i] = true;
            allp.push_back(i);
        }
    }
    printf("init done...\n");
}

bool checkp(int tnum){
    for(int i = 2; i*i <= tnum; i++)
        if(tnum%i == 0)
            return false;
    return true;
}

bool book[8];
int cnum;
bool dfs(int ci){
    if(ci == 7){
        cnt++;
        bool tor = checkp(cnum);
        if(tor)
            printf("%d %d\n", cnum, cnt);
        return tor;
        //if(isp[cnum])
        //    printf("%d\n", cnum);
        //return isp[cnum];
    }
    for(int i = 7; i > 0; i--){
        if(book[i])
            continue;
        book[i] = true;
        cnum = cnum*10 + i;
        if(dfs(ci+1))
            return true;
        book[i] = false;
        cnum /= 10;
    }
    return false;
}

int main(){
    dfs(0);
    return 0;
}


