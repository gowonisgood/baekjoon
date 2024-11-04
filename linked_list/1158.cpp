#include <iostream>
#include <list>
using namespace std;

int main() {
    //1.input data
    int N,k;
    cin>>N>>k;

    //2.make yose
    list<int> yose;
    list<int>::iterator iter;

    for(int i=1;i<=N;i++) {
        yose.push_back(i);
    }

    //3.print
    cout<<'<';
    iter = yose.begin();
    int steps;
    for(int i=0;i<N;i++) {
        steps = k-1;
        while(steps-->0) {
            iter++;
            if(iter==yose.end()) {
                iter=yose.begin();
            }
        }

        cout<<*iter;
        if(i!=N-1) cout<<", ";
        iter = yose.erase(iter);
        if(iter==yose.end()) {
            iter=yose.begin();
        }
        //iter--;
    }
    cout<<'>';

    return 0;
}
