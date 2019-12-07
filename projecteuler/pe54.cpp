/*************************************************************************
    > File Name: pe54.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年10月31日 星期四 22时08分27秒
 ************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cstring>

//纯粹为了ac而写的*代码...所以还是想办法重构下吧（

using namespace std;

struct Card{
    int cc;
    int type;
}card[10];

void s2c(char *s, int ci){
    switch(s[0]){
        case 'T':
            card[ci].cc = 10;
            break;
        case 'J':
            card[ci].cc = 11;
            break;
        case 'Q':
            card[ci].cc = 12;
            break;
        case 'K':
            card[ci].cc = 13;
            break;
        case 'A':
            card[ci].cc = 14;
            break;
        default:
            card[ci].cc = s[0]-'0';
    }
    switch(s[1]){
        case 'C':
            card[ci].type = 1;
            break;
        case 'H':
            card[ci].type = 2;
            break;
        case 'S':
            card[ci].type = 3;
            break;
        case 'D':
            card[ci].type = 4;
            break;
    }
}

bool cmp1(const Card &a, const Card &b){
    return a.cc < b.cc || a.cc==b.cc && a.type < b.type;
}

char cs[100];
int cnt[2][20];
int stk[2][10], tot1, tot2;

int main(){
    FILE *fp = fopen("p054_poker.txt", "r");
    int ranka, rankb;
    int wincarda, wincardb;
    int ans = 0;
    bool allsametypea;
    while(fgets(cs, 100, fp) != NULL){
        ranka = 0;
        rankb = 0;
        for(int i = 0; i < 10; i++)
            s2c(&cs[i*3], i);
        bool asa = true, asb = true;
        bool isfla = true, isflb = true;
        sort(&card[0], &card[5], cmp1);
        sort(&card[5], &card[10], cmp1);
        for(int i = 0; i < 4; i++){
            asa = asa && card[i].type == card[i+1].type;
            asb = asb && card[i+5].type == card[i+6].type;
        }
        for(int i = 0; i < 4; i++){
            isfla = isfla && card[i].cc+1 == card[i+1].cc;
            isflb = isflb && card[i+5].cc+1 == card[i+6].cc;
        }
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < 5; i++){
            cnt[0][card[i].cc]++;
            cnt[1][card[i+5].cc]++;
        }
        tot1 = tot2 = 0;
        if(asa && isfla){
            ranka = 9;
            stk[0][tot1++] = card[0].cc;
        }else if(asa){
            ranka = 6;
            for(int i = 4; i >= 0; i--)
                stk[0][tot1++] = card[i].cc;
        }else if(isfla){
            ranka = 5;
            stk[0][tot1++] = card[0].cc;
        }else{
            for(int i = 14; i >= 2; i--)
                if(cnt[0][i] == 4){
                    ranka = 8;
                    stk[0][tot1++] = i;
                    break;
                }else if(cnt[0][i] == 3){
                    ranka = 4;
                    stk[0][tot1++] = i;
                    break;
                }
            if(ranka == 8){
                for(int i = 0; i < 5; i++)
                    if(card[i].cc != stk[0][0])
                        stk[0][tot1++] = card[i].cc;
            }else{
                for(int i = 14; i >= 2; i--)
                    if(cnt[0][i] == 2){
                        if(ranka == 4){
                            ranka = 7;
                            stk[0][tot1++] = i;
                            break;
                        }else if(ranka == 2){
                            ranka = 3;
                            stk[0][tot1++] = i;
                            break;
                        }else{
                            ranka = 2;
                            stk[0][tot1++] = i;
                        }
                    }
                for(int i = 14; i >= 2; i--)
                    if(cnt[0][i] == 1)
                        stk[0][tot1++] = i;
            }
        }
        if(asb && isflb){
            rankb = 9;
            stk[1][tot2++] = card[5].cc;
        }else if(asb){
            rankb = 6;
            for(int i = 9; i >= 5; i--)
                stk[1][tot2++] = card[i].cc;
        }else if(isflb){
            rankb = 5;
            stk[1][tot2++] = card[5].cc;
        }else{
            for(int i = 14; i >= 2; i--)
                if(cnt[1][i] == 4){
                    rankb = 8;
                    stk[1][tot2++] = i;
                    break;
                }else if(cnt[1][i] == 3){
                    rankb = 4;
                    stk[1][tot2++] = i;
                    break;
                }
            if(rankb == 8){
                for(int i = 5; i < 10; i++)
                    if(card[i].cc != stk[1][0])
                        stk[1][tot2++] = card[i].cc;
            }else{
                for(int i = 14; i >= 2; i--)
                    if(cnt[1][i] == 2){
                        if(rankb == 4){
                            rankb = 7;
                            stk[1][tot2++] = i;
                            break;
                        }else if(rankb == 2){
                            rankb = 3;
                            stk[1][tot2++] = i;
                            break;
                        }else{
                            rankb = 2;
                            stk[1][tot2++] = i;
                        }
                    }
                for(int i = 14; i >= 2; i--)
                    if(cnt[1][i] == 1)
                        stk[1][tot2++] = i;
            }
        }
        if(ranka > rankb)
            ans++;
        else if(ranka == rankb){
            for(int i = 0; i < tot1; i++)
                if(stk[0][i] > stk[1][i]){
                    ans++;
                    break;
                }else if(stk[0][i] < stk[1][i])
                    break;
        }
    }
    printf("%d\n", ans);
}

