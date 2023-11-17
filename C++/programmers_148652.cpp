#include <string>
#include <vector>

using namespace std;

int get_bit(int index){
    if(index % 5 == 2)
        return 0;
    if(index <= 4)
        return 1;
    return get_bit(index / 5);
}

int solution(int n, long long l, long long r) {
    int answer = 0;
    for(int i = l - 1; i < r; i++){
        answer += get_bit(i);
    }
    return answer;
}
