/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long N;
    int arr[10001] = {0};
    int buff;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> buff;
        arr[buff]++;
    }
    
    for(int i = 0; i < 10001; i++){
        if(arr[i]){
            int tmp = arr[i];
            for(int j = 0; j < tmp; j++){
                cout << i << '\n';
            }
        }
    }
    

    return 0;
}
