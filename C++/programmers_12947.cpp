#include <string>
#include <vector>

using namespace std;

int get_num(int x){
    int sum = 0;
    
    while(x > 0){
        sum += (x % 10);
        x /= 10;
    }
    
    return sum;
}

bool solution(int x) {
    bool answer = true;
    int num = get_num(x);
    
    return x % num == 0;
}
