/*************************************************************************
    > File Name: pe50.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月27日 星期日 12时59分28秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 1000001;
//const int maxn = 1001;

vector<int> allp;
bool isp[maxn];

void init(){
    for(int i = 2; i < maxn; i++){
        bool flag = true;
        for(int j = 0; j < allp.size() && allp[j]*allp[j] <= i; j++)
            if(i % allp[j] == 0){
                flag = false;
                break;
            }
        if(flag){
            isp[i] = true;
            allp.push_back(i);
        }
    }
}

int findans(){
    int ans = 0;
    int cmax = 0;
    for(int i = 0; i < allp.size() && allp.size()-i > cmax; i++){
        int cans = 0;
        int ci = i;
        while(true){
            cans += allp[ci++];
            if(cans > maxn)
                break;
            if(isp[cans] && ci-i > cmax){
                cmax = ci-i+1;
                ans = cans;
            }
            if(ci > allp.size())
                break;
        }
    }
    return ans;
}

int main(){
    init();
    printf("%d\n", allp.size());
    printf("%d\n", findans());

    return 0;
}

