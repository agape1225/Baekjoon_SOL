#include <cstdio>
#include <string>
#include <iostream> 
#include <vector>
using namespace std;  

int cache[100] = {0};
int main() { 

    for(int i = 1; i <= 10; i++){
        cache[i] = i;
        cout << cache[i] << endl;
    }
     
    return 0;
} 
