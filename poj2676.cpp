#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char str[10][10],a,b,c,s[90];
int row[10], col[10], grid[10], cnt[512], num[512], tot;

inline int g(int x, int y){
return ((x/3)*3)+(y/3);

}
inline void flip(int x, int y, int z){
    row[x] ^= 1 << z;
    col[y] ^= 1 << z;
    grid[g(x,y)] ^= 1<<z;
}

bool dfs(int now){
    if(now == 0) return 1;
    int temp = 10, x, y;
    for(int i = 1; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(str[i][j] != '.')continue;
            int val = row[i] & col[j] & grid[g(i,j)];
            if(!val) return 0;
            if(cnt[val] < temp){
                temp = cnt[val];
                x = i, y = j;
            }
        }
    }
    int val = row[x] & col[y] & grid[g(x,y)];
    for(; val; val -= val & -val){
        int z = num[val&-val];
        str[x][y] = '1'+ z;
        flip(x,y,z);
        if(dfs(now-1))return 1;
        flip(x,y,z);
        str[x][y] = '.';
    }
    return 0;

}


int main(){
    while(cin>>s+1 && s[1]!='e'){
        for(int i = 1; i<=9;i++){
            for(int j = 1; j<=9;j++){
                str[i][j] = s[i*9-9+j];
            }
        }
        for(int i = 1; i <= 9; i++) row[i] = col[i] = grid[i] = (1 << 9) - 1;
        tot = 0;
        for(int i = 1; i <= 9; i++){
            for(int j =1; j<= 9; j++ ){
                if(str[i][j] !='.') flip(i, j, str[i][j] - '1');
                else tot++;
            }
        }
        dfs(tot);
        for(int i = 1; i <= 9; i++)
            for(int j = 1; j <= 9; j++)s[i*9+j-9] == str[i][j];
        cout<<s+1;
    }
}
