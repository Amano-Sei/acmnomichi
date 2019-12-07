/*************************************************************************
    > File Name: pe51.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月28日 星期一 22时13分57秒
 ************************************************************************/

#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 1000005;
//题意理解错了就很伤

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

int bits[10], tot;
void getbits(int x){
    tot = 0;
    while(x){
        bits[tot++] = x%10;
        x /= 10;
    }
}

void solve(){
    for(int i = 0; i < allp.size(); i++){
        int cnum = allp[i];
        getbits(cnum);
        for(int j = 0; j < 3; j++){
            int tnum = 0;
            int baseadd = 0;
            bool flag = false;
            for(int jj = tot-1; jj >= 0; jj--){
                baseadd *= 10;
                tnum *= 10;
                if(bits[jj] != j)
                    tnum += bits[jj];
                else{
                    baseadd += 1;
                    flag = true;
                }
            }
            if(!flag)
                continue;
            int anscnt = 1;
            for(int ii = j+1; ii < 10; ii++)
                if(isp[tnum+baseadd*ii])
                    anscnt++;
            if(anscnt == 8){
                printf("%d %d %d\n", cnum, tnum, baseadd);
                return;
            }
        }
    }
}
int main(){
    init();
    solve();
    return 0;
}


