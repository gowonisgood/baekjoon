#include <iostream>
#include <list>
#include <string>

using namespace std;
int main()
{
    list<char> charList = {};


    string input;
    getline(cin,input);

    for(char c:input) charList.push_back(c);

    int  N;
    cin>>N;

    list<char>::iterator t = charList.end();
    //t--;


    for(int i=0;i<N;i++) {
        char ch;
        cin>>ch;
        switch (ch) {
            case 'P': {
                char x;
                cin>>x;
                charList.insert(t,x);
                break;
            }
            case 'L': {
                if(t!=charList.begin()) {
                    t--;
                }
                break;
            }
            case 'D': {
                if(t!=charList.end()) {
                    t++;
                }
                break;
            }
            case 'B': {
                if(t!=charList.begin()) {
                    t--;
                    t = charList.erase(t);
                }
                break;
            }
        }
    }

    for (list<char>::iterator it = charList.begin();it!=charList.end();it++)
        cout<<*it;
    return 0;
}
