/*************************************************************************
    > File Name: c.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月08日 星期日 13时00分37秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int> > all102;
int n, q;
char s[200005];

int main(){
    int cs, ce, cnum = -1;
    scanf("%d%d", &n, &q);
    scanf("%s", s+1);
    for(int i = 1; i <= n; i++){
        switch(cnum){
            case -1:
                if(s[i] == '1'){
                    cs = i;
                    cnum = 1;
                }
                break;
            case 1:
                if(s[i] == '1'){
                    cs = i;
                    cnum = 1;
                }else if(s[i] == '0')
                    cnum = 0;
                break;
            case 0:
                if(s[i] == '2'){
                    all102.push_back({cs, i});
                }
                break;
            case 2:
                break;
        }
    }
	return 0;
}

