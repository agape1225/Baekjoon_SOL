/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

stack<int> s;
vector<int> input;
vector<char> ans;

int main()
{
    int n, buff;

    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> buff;
        input.push_back(buff);
    }
    
    int index = 1;
    
    for(auto it = input.begin(); it != input.end(); it++){
        
        int target = (*it);
        
        if(s.empty()){
            
            if(index <= target){
                while(index <= target){
                    s.push(index);
                    index++;
                    ans.push_back('+');
                    //cout << '+' << '\n';
                }
                //cout << '-' << '\n';
                ans.push_back('-');
                s.pop();    
            }
            else{
                cout << "NO";
                return 0;
            }
        }else{
            
            if(s.top() <= target){
                while(index <= target){
                    s.push(index);
                    index++;
                    ans.push_back('+');
                    //cout << '+' << '\n';
                }
                //cout << '-' << '\n';
                ans.push_back('-');
                s.pop();
            }else{
                cout << "NO";
                return 0;
            }
            
        }
    }
    
    for(auto it = ans.begin(); it != ans.end(); it++){
        
        cout << *it << '\n';
    }

    return 0;
}
