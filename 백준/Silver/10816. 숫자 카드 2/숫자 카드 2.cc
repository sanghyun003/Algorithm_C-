#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(){
    int N, num;
    unordered_map<int, int> m;
    vector<int> v;
    
    cin>>N;
    while(N-->0){
        cin>>num;
        m[num]++;
    }
    cin>>N;
    while(N-->0){
        cin>>num;
        v.push_back(m[num]);
    }
    for(int i : v){
        cout<< i <<" ";
    }
    
    return 0;
}