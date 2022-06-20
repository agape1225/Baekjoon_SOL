/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    
    int L, buff;
    int M = 1234567891;
    string input;
    long long ans = 0;
    long long R = 1;
    
    cin >> L;
    cin >> input;
    
    for(int i = 0; i < L; i++){
        
        buff = input[i] - 96;
        ans = (ans + (buff  * R ))% M;
        R = (R * 31) % M;
        
    }
    
    cout << ans;
    
    /*for(auto it = input.begin(); it != input.end(); it++){
        
        buff = *(it) - 96;
        
        
    }*/
    
    /*char input;
    cin >> input;
    
    int buff = input - 96;
    
    cout << buff << endl;*/

    return 0;
}
