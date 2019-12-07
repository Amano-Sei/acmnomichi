/*************************************************************************
    > File Name: pe53.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月30日 星期三 09时32分28秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int findans(){
    int ans = 0;
    for(int cn = 1; cn <= 100; cn++){
        int cse = 1;
        for(int cr = 1; cr <= (cn>>1); cr++){
            cse = cse*(cn-cr+1)/cr;
            if(cse > 1000000){
                ans += cn+1-cr*2;
                break;
            }
        }
    }
    return ans;
}
            

int main(){
    printf("%d\n", findans());
    return 0;
}

