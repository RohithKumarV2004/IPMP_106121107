#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int> h;
    h.insert(1);
    h.insert(2);
    h.insert(6);
    h.insert(4);
    h.insert(1);
    for(auto i:h){
        cout<<i<<endl;
    }
}