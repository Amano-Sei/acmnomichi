/*************************************************************************
    > File Name: tcantor.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月27日 星期日 11时19分02秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>

using namespace std;

char tnum[5] = "1123";

//在做pe的过程中发现自己组合学的有漏洞...
//不对（我有学过组合数学么（哭

int main(){
    do{
        printf("%s\n", tnum);
    }while(next_permutation(tnum, &tnum[4]));
    return 0;
}


