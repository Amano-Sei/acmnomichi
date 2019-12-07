/*************************************************************************
    > File Name: pe58.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月04日 星期一 17时42分05秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 100000005;

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
            allp.push_back(i);
            isp[i] = true;
        }
    }
}

bool checkp(long long x){
    for(long long i = 2; i*i <= x; i++)
        if(x%i == 0)
            return false;
    return true;
}

long long getans(){
    long long ans = 3;
    long long ansup = ans*ans;
    int pcnt = 0;
    while(true){
        if(checkp(ansup-(ans-1)))
            pcnt++;
        if(checkp(ansup-(ans-1)*2))
            pcnt++;
        if(checkp(ansup-(ans-1)*3))
            pcnt++;
        double crate = (double)pcnt / (2*ans-1);
        printf("%d %d %lf\n", pcnt, ans, crate);
        if(crate < 0.1)
            return ans;
        ans += 2;
        ansup = ans*ans;
    }
    return -1;
}

int main(){
    printf("%lld\n", getans());

    return 0;
}

