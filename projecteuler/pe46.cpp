/*************************************************************************
    > File Name: pe46.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月23日 星期三 12时51分35秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

const int maxn = 10005;
bool isp[maxn];
vector<int> allp;

void findans(){
    allp.push_back(2);
    isp[2] = true;
    for(int i = 3; ; i++){
        bool flag = true;
        for(int j = 0; j < allp.size() && allp[j]*allp[j] <= i; j++)
            if(i % allp[j] == 0){
                flag = false;
                break;
            }
        if(flag){
            allp.push_back(i);
            isp[i] = true;
        }else{
            bool isans = true;
            for(int j = 0; j < allp.size(); j++){
                int tmp = (i-allp[j])/2;
                int tsqr = sqrt(tmp);
                if(tsqr*tsqr == tmp){
                    isans = false;
                    break;
                }
            }
            if(isans){
                printf("%d\n", i);
                return;
            }
        }
    }
}

int main(){
    findans();

    return 0;
}

