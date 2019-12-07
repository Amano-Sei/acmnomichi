/*************************************************************************
    > File Name: testp.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年11月08日 星期五 09时11分37秒
 ************************************************************************/

#include <cstdio>
#include <cstdlib>

bool isp(long long x){
    for(long long i = 2; i*i < x; i++)
        if(x%i == 0)
            return false;
    return true;
}

int main(int argc, char *argv[]){
    for(int i = 1; i < argc; i++){
        long long cx = atoi(argv[i]);
        printf("%s %s\n", argv[i], isp(cx)?"YES":"NO");
    }
    return 0;
}

