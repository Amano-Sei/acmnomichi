/*************************************************************************
    > File Name: pe35.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月12日 星期六 14时55分15秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 1000000;
vector<int> allp;
bool isp[maxn];

void init(){
    allp.push_back(2);
    isp[2] = true;
    for(int i = 3; i < maxn; i++){
        bool flag = true;
        for(int j = 0; j < allp.size() && allp[j]*allp[j] <= i; j++)
            if(i%allp[j] == 0){
                flag = false;
                break;
            }
        if(flag){
            allp.push_back(i);
            isp[i] = true;
        }
    }
}

int tnum[6];
int clen;

int getans(){
    int ans = 0;
    for(int i = 0; i < allp.size(); i++){
        int cnum = allp[i];
        bool flag = true;
        for(clen = 0; cnum; clen++, cnum/=10)
            tnum[clen] = cnum%10;
        for(int i = 0; i < clen; i++){
            cnum = 0;
            for(int j = clen-1; j >= 0; j--)
                cnum = cnum*10+tnum[(i+j)%clen];
            if(!isp[cnum]){
                flag = false;
                break;
            }
        }
        if(flag){
            printf("%d\n", allp[i]);
            ans++;
        }
    }
    return ans;
}

int main(){
    init();
    printf("%d\n", getans());
    return 0;
}

