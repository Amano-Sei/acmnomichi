/*************************************************************************
    > File Name: b.cpp
    > Author: Amano Sei
    > Mail: amano_sei@outlook.com 
    > Created Time: 2019年09月08日 星期日 09时17分55秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int eps = 1e-8;
int sgn(double x){
    if(fabs(x) < eps)
        return 0;
    if(x < 0)
        return -1;
    else
        return 1;
}
struct point{
    double x, y;
    point(){}
    point(int cx, int cy){
        x = cx;
        y = cy;
    }
    point(double cx, double cy):x(cx), y(cy){}
    double operator ^ (const point &b) const{
        return x*b.y-y*b.x;
    }
    point operator - (const point &b) const{
        return point(x-b.x, y-b.y);
    }
    bool operator != (point b) const{
        return sgn(x-b.x) !=0 || sgn(y-b.y)  != 0;
    }
}bl[4];
struct line{
    point s, e;
    line(){}
    line(point a, point b){
        s = a;
        b = e;
    }
}ll[2];

int main(){
    int t, tx, ty;
    scanf("%d", &t);
    while(t--){
        for(int i = 0; i < 4; i++){
            scanf("%d%d", &tx, &ty);
            bl[i] = point(tx, ty);
        }
        if(bl[0].y > bl[1].y)
            swap(bl[0], bl[1]);
        if(bl[2].y > bl[3].y)
            swap(bl[2], bl[3]);
        if(((bl[2]-bl[0])^(bl[1]-bl[0]))*((bl[3]-bl[0])^(bl[1]-bl[0])) <= 0 && ((bl[0]-bl[2])^(bl[3]-bl[2]))*((bl[1]-bl[2])^(bl[3]-bl[2])) <= 0){
            bl[0].y = bl[2].y = max(bl[0].y, bl[2].y);
            bl[1].y = bl[3].y = min(bl[1].y, bl[3].y);
            if(bl[0] != bl[2] && bl[1] != bl[3]){
                double a1 = (bl[2]-bl[3])^(bl[1]-bl[3]);
                double a2 = (bl[2]-bl[3])^(bl[0]-bl[3]);
                point cr = point((bl[1].x*a2-bl[0].x*a1)/(a2-a1), (bl[1].y*a2-bl[0].y*a1)/(a2-a1));
                for(int i = 0; i < 4; i++)
                    bl[i] = bl[i]-cr;
                printf("%.2lf\n", (fabs(bl[0]^bl[2])+fabs(bl[1]^bl[3]))/2);
            }else{
                printf("0.00\n");
            }
        }else{
            printf("0.00\n");
        }
    }
	return 0;
}

