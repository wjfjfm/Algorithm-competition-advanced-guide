
#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

int main(){
        vector<int> v;
        for (int i = 0; i < 10; i++){
                v.push_back(i);
                v.push_back(i);
        }

        set<int> s(v.begin(), v.end());
        printf("%d\n", v.size());
        printf("%d\n", s.size());
        return 0;
}
