#include<cstring>
#include<iostream>
using namespace std;
const int  N = 6;
int a[N], ans, aa[N];
char s[N];

void dj(int x, int y){
    aa[x] ^= (1 << y);
    if(x!= 1) aa[x-1] ^= (1 << y);
    if(x!= 5) aa[x+1] ^= (1 << y);
    if(y !=0) aa[x] ^= (1 << (y - 1));
    if(y != 4)aa[x] ^= (1 << (y + 1));
}

void pd(int p){
    int k = 0;
    memcpy(aa, a, sizeof(a));
    for(int i = )


}
void abc{
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= 5; i++){
        cin >> (s+1);
        for(int j = 1; j <= 5; j++) a[i] = a[i] * 2 + (s[j] - '0')
    }
    ans = 7;
    for(int p = 0; p < (1 << 5); p++)pd(p);
    if(ans == 7) cout<<"-1" << endl;
    else cout<< ans << endl;

}

int main(){
    int n;
    cin >> n;
    while(n--) abc();
    return 0;
}
