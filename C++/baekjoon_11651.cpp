/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }else
        return a.second < b.second;
}

int main()
{
    vector<pair<int,int>> arr;
    int buff1, buff2;
    int N;
    
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> buff1 >> buff2;
        arr.push_back(make_pair(buff1, buff2));
    }
    
    sort(arr.begin(), arr.end(), compare);
    
    for(auto it = arr.begin(); it != arr.end(); it++){
        cout << (*it).first << ' ' << (*it).second << '\n';
    }

    return 0;
}
