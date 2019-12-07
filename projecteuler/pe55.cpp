/*************************************************************************
    > File Name: pe55.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月01日 星期五 22时27分38秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100;

int num[maxn][maxn];
int maxlen;

bool ispl(int ci){
    for(int l = 1, r = num[ci][0]; l < r; l++, r--)
        if(num[ci][l] != num[ci][r])
            return false;
    return true;
}

int findans(){
    int ans = 0;
    for(int i = 1; i < 10000; i++){
        int clen = 0;
        int t = i;
        while(t){
            num[0][++clen] = t%10;
            t/=10;
        }
        num[0][0] = clen;
        bool flag = true;
        for(int j = 1; j < 50; j++){
            int prelen = num[j-1][0];
            int cc = 0;
            for(int jj = 1; jj <= prelen; jj++){
                cc += num[j-1][jj]+num[j-1][prelen-jj+1];
                num[j][jj] = cc%10;
                cc /= 10;
            }
            while(cc){
                num[j][++prelen] = cc%10;
                cc /= 10;
            }
            num[j][0] = prelen;
            if(ispl(j)){
                maxlen = max(maxlen, j);
                flag = false;
                break;
            }
        }
        if(flag){
            printf("%d\n", i);
            ans++;
        }
    }
    return ans;
}

int main(){
    printf("%d\n", findans());
    printf("%d\n", maxlen);
    return 0;
}

