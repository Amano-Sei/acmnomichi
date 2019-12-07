/*************************************************************************
    > File Name: tcmd.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月14日 星期六 10时49分22秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(){
    FILE *fp = NULL;
    char cmd[1024] = "ls";
    if(fp = popen(cmd, "r"))
        while(fgets(cmd, 1024, fp))
            printf("===%s===\n", cmd);
	return 0;
}

