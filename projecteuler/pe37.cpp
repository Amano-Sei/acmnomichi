/*************************************************************************
    > File Name: pe37.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月14日 星期一 19时55分23秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 1000005;

int ans;
vector<int> allp;
bool isp[maxn];

void checknum(int c){
    int tten = 10;
    while(c%tten != c){
        if(!isp[c%tten])
            return;
        tten *= 10;
    }
    int tnum = c;
    c /= 10;
    while(c){
        if(!isp[c])
            return;
        c /= 10;
    }
    printf("%d\n", tnum);
    ans += tnum;
}

void getans(){
    int ccnt = 11;
    isp[2] = isp[3] = isp[5] = isp[7] = true;
    allp.push_back(2);
    allp.push_back(3);
    allp.push_back(5);
    allp.push_back(7);
    for(int i = 11; ccnt && i < maxn; i++){
        bool flag = true;
        for(int j = 0; j < allp.size() && allp[j]*allp[j] <= i; j++)
            if(i % allp[j] == 0){
                flag = false;
                break;
            }
        if(flag){
            allp.push_back(i);
            isp[i] = true;
            checknum(i);
        }
    }
}

int main(){
    getans();
    printf("%d\n", ans);
    return 0;
}

