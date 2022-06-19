/******************************************************************************
Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.
*******************************************************************************/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N;
    long long startNum = 666;
    
    cin >> N;
    
    while(true){
        string buff = to_string(startNum);
        if(buff.find("666") != string::npos){
            N--;
        }
        
        startNum++;
        
        if(N == 0){
            cout << buff;
            break;
        }
    }

    return 0;
}
