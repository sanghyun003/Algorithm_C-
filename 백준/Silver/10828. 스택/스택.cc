#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    int N, num;
    string cmd;
    stack<int> s;
    
    cin >> N;
    
    while(N-->0){
        cin>>cmd;
        
        if(cmd=="push") {
            cin>>num;
            s.push(num);
        }
        else if(cmd=="pop"){
            if(!s.empty()){
                cout<<s.top()<<'\n';
                s.pop();
            }
            else cout<<-1<<'\n';
        }
        else if(cmd=="size") cout<<s.size()<<'\n';
        else if(cmd=="empty") s.empty()?cout<<1<<'\n':cout<<0<<'\n';
        else if(cmd=="top") s.empty()?cout<<-1<<'\n':cout<<s.top()<<'\n';
    }
    
    return 0;
}