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

vector<int> trees;

int main()
{
    int N, M, buff, ans = 0;                 //M : 만들고자 하는 나무의 길이
    long long sum;
    
    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        cin >> buff;
        trees.push_back(buff);
    }
    
    int left    = 0;
    int right   = *max_element(trees.begin(), trees.end());
    int mid     = 0;             //톱의 길이
    
    while(left <= right){
        sum = 0;
        mid = (left + right) / 2;
        
        
        
        for(auto it = trees.begin(); it != trees.end(); it++){
            
            if(mid < (*it)){
                sum += (*it) - mid;
            }
            
        }
        
        if(sum >= M){
            
            if(mid > ans){
                ans = mid;
            }
            
            left = mid + 1;
            
            
        }else{
            right = mid - 1;
        }
        
        //cout << left << ' ' << right << ' ' << ans << ' ' << mid << endl;
        
    }
    
    //cout << "ans: " << ans;
    cout << ans;

    return 0;
}
