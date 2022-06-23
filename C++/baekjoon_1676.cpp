/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    
    int N;
    int count = 0;
    vector<int> nums;
    vector<int> ans;
    
    cin >> N;
    
    
    for(int i = 2; i <= N; i++){
        
        nums.push_back(i);
        
    }
    

    
    for(auto it = nums.begin(); it != nums.end(); it++){
        if((*it) % 5 == 0){
            count++;
        }
        if((*it) % 25 == 0){
            count++;
        }
        if((*it) % 125 == 0){
            count++;
        }
    }
    
    cout << count;

    return 0;
}
