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

int get_max(vector<pair<int, int>> arr){
    
    int max = -1;
    
    for(auto it = arr.begin(); it != arr.end(); it++){
        
        if(max < (*it).second){
            max = (*it).second;
        }
        
    }
    return max;
}

int main()
{
    int T;
    cin >> T;
    
    for(int t = 0; t < T; t++){
        vector<pair<int, int>> arr;
        int N, M, buff, max;
        
        cin >> N >> M;
        
        for(int i = 0; i < N; i++){
            
            cin >> buff;
            arr.push_back(make_pair(i, buff));
            
        }
        
        int index = 0;
        int count = 0;
        
        max = get_max(arr);
            
        while(true){
            
            if(arr[index].second == max){
                
                count++;
                if(arr[index].first == M){
                    /*cout << arr[index].first << ' ' << index << endl;
                    for(int i = 0; i < arr.size(); i++){
                        cout << arr[i].first << ',' << arr[i].second << ' ';
                    }
                    cout << endl;*/
                    cout << count << '\n';
                    break;
                }else{
                    /*cout << arr[index].first << ' ' << index << endl;
                    for(int i = 0; i < arr.size(); i++){
                        cout << arr[i].first << ',' << arr[i].second << ' ';
                    }
                    cout << endl;*/
                    arr.erase(arr.begin() + index);
                    if(index == arr.size()){
                        index = 0;
                    }
                    max = get_max(arr);
                }
                
                
            }else{
                index = (index + 1) % arr.size();
            }
                
                
        }
        
        
    }

    return 0;
}
