#include <string>
#include <vector>

using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

vector<int> solution(string command) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);

    int direction = 0;

    for(int i=0;i<command.length();i++){
        char c = command[i];
        switch(c){
            case 'G':
                answer[0] += dx[direction];
                answer[1] += dy[direction];
                break;
            case 'B':
                answer[0] -=dx[direction];
                answer[1] -=dy[direction];
                break;
            case 'R':
                direction = (direction + 1)%4;
                break;
            case 'L':
                direction = (direction-1);
                if(direction<0) direction = 3;
                break;
            default:
                break;
        }
    }
    return answer;
}