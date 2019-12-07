/*************************************************************************
    > File Name: pe56.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月02日 星期六 20时55分45秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>

using namespace std;

int bits[100][200];

int findans(){
    int ans = 0;
    for(int i = 2; i < 100; i++){
        int t = i;
        int clen = 0;
        while(t){
            bits[0][++clen] = t%10;
            t /= 10;
        }
        bits[0][0] = clen;
        for(int j = 1; j < 99; j++){
            int cc = 0;
            int prelen = bits[j-1][0];
            for(int k = 1; k <= prelen; k++){
                cc += bits[j-1][k]*i;
                bits[j][k] = cc % 10;
                cc /= 10;
            }
            while(cc){
                bits[j][++prelen] = cc%10;
                cc /= 10;
            }
            bits[j][0] = prelen;
            for(int k = 1; k <= prelen; k++)
                cc += bits[j][k];
            //ans = max(ans, cc);
            if(cc > ans){
                printf("%d %d %d %d\n", i, j, cc, prelen);
                ans = cc;
            }
        }
    }
    return ans;
}

int main(){
    printf("%d\n", findans());

    return 0;
}

