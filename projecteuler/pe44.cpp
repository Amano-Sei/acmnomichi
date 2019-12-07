/*************************************************************************
    > File Name: pe44.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月21日 星期一 23时23分02秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

vector<int> allpen;
bool ispen[10000005];

void findans(){
    int ci = 1;
    while(true){
        int cpen = ci*(3*ci-1)/2;
        ispen[cpen] = true;
        allpen.push_back(cpen);
        for(int i = allpen.size()-2; i >= 0; i--){
            int tmp = cpen-allpen[i];
            if(!ispen[tmp])
                continue;
            int tmp2 = (allpen[i]+cpen)*24+1;
            int tmp3 = sqrt(tmp2);
            if(tmp3*tmp3 == tmp2 && tmp3%6 ==5){
                printf("%d %d %d %d\n", tmp, cpen, allpen[i], ci);
                return;
            }
        }
        ci++;
    }
}
int main(){
    findans();
    return 0;
}

