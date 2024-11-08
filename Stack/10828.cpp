#include <iostream>
#include <stack>
#include <string.h>
using namespace std;


int main()
{
    int N;

    cin>>N;
    stack<int> s;
    enum Op {
        push,
        top,
        size,
        empty,
        pop
    };




    for(int i=0;i<N;i++) {
        enum Op op;
        string opString;
        cin>>opString;

        if(opString=="push") {
            op = push;
        } else if(opString=="top") {
            op = top;
        } else if (opString=="size") {
            op = size;
        } else if (opString=="empty") {
            op = empty;
        } else if (opString=="pop") {
            op = pop;
        }

        switch(op) {
            case push:
                int numP;
                cin>>numP;
                s.push(numP);
                break;
            case top:
                if(s.empty()) {
                    cout<<-1<<'\n';
                }
                else {
                    int numT = s.top();
                    cout<<numT<<'\n';
                }
                break;
            case size:
                cout<<s.size()<<'\n';
                break;
            case empty:
                if(s.empty()) {
                    cout<<1<<'\n';
                }else {
                    cout<<0<<'\n';
                }
                break;
            case pop:
                if(s.empty()) {
                    cout<<-1<<'\n';
                }else {
                    int numT = s.top();
                    cout<<numT<<'\n';
                    s.pop();
                }
                break;
            default:
                break;
        }
    }


    return 0;
}
