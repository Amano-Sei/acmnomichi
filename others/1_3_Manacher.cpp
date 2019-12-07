#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 110010;
char Ma[maxn*2];
int Mp[maxn*2];

void Manacher(char s[], int len){
	int l = 0;
	Ma[l++] = '$';
	Ma[l++] = '#';
	for(int i = 0; i < len; i++){
		Ma[l++] = s[i];
		Ma[l++] = '#';
	}
	Ma[l] = 0;
	Mp[0]=1;
	int mx = 1, id = 0;
	for(int i = 1; i < l; i++){
		Mp[i] = mx > i ? min(Mp[2*id-i], mx-i):1;
		while(Ma[i+Mp[i]] == Ma[i-Mp[i]])
			Mp[i]++;
		if(i+Mp[i] > mx){
			id = i;
			mx = i+Mp[i];
		}
	}
}

int main(){
	printf("hello world");
	return 0;
}

