/*************************************************************************
    > File Name: pe66.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月12日 星期二 09时16分03秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

long long getmaxen(long long x){
    if(x < 2)
        return 0;
    for(long long i = 2; i*i <= x; i++)
        while(x%i==0 && x!=i)
            x/=i;
    return x;
}

bool isp(long long x){
    if(x < 2)
        return false;
    for(long long i = 2; i*i <= x ; i++)
        if(x % i == 0)
            return false;
    return true;
}

int getans(){
    int ans = 0;
    int maxx = 0;
    for(int cd = 2; cd <= 1000; cd++){
        int td = sqrt(cd);
        if(td*td == cd)
            continue;
        //bool flag = isp(cd);
        long long maxen = getmaxen(cd);
        if(maxen != cd)
            continue;
        for(int i = 0; ; i++){
            long long cx = i*maxen-1;
            if(cx >= 4426982938){
                printf("%d warning...\n", cd);
                break;
            }
            //printf("%lld\n", cx);
            if(cx > 1){
                long long tx = cx*cx-1;
                if(tx%cd == 0){
                    tx /= cd;
                    long long ty = sqrt(tx);
                    if(ty*ty == tx){
                        if(cx > maxx){
                            maxx = cx;
                            ans = cd;
                        }
                        //printf("%lld %d\n", cx, cd);
                        break;
                    }
                }
            }
            cx = i*maxen+1;
            if(cx > 1){
                long long tx = cx*cx-1;
                if(tx%cd == 0){
                    tx /= cd;
                    long long ty = sqrt(tx);
                    if(ty*ty == tx){
                        if(cx > maxx){
                            maxx = cx;
                            ans = cd;
                        }
                        //printf("%lld %d\n", cx, cd);
                        break;
                    }
                }
            }
            //if(maxen == cd && i >= 2){
            //    printf("%lld\n", cd);
            //    break;
            //}
        }
    }
    return ans;
}

int main(){
    printf("%d\n", getans());

    return 0;
}

