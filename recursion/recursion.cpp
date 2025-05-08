#include <iostream>

int recursion(int N) {
    if(N==1) return 1;
    return N+recursion(N-1);
}

using namespace std;
int main() {
    int N;
    cin >> N;
    cout << recursion(N);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
