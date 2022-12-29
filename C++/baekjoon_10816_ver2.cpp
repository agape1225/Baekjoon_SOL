#include <iostream>
#include <vector>
#include <map>


using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    map<int, int> mp;
    int N, M, buff;
    vector<int> nums;
    vector<int> cards;
    
    cin >> N;
    for(int i = 0; i < N; i++){
        
        cin >> buff;
        
        auto flag = mp.find(buff);
        
        if(flag != mp.end()){
            //cout << "is in";
            
            
            int num = (*flag).second;
            num += 1;
            //cout << ' ' << num << endl;
            mp.erase(buff);
            mp.insert({buff, num});
            
        }else{
            //cout << "is not in";
            mp.insert({buff,1});
        }
        
        //nums.push_back(buff);
        
    }
    
    cin >> M;
    for(int i = 0; i < M; i++){
        
        cin >> buff;
        auto it = mp.find(buff);
        
        if(it != mp.end()){
            cout << (*it).second << ' ';
        }else{
            cout << 0 << ' ';
        }
        
    }
    
    /*for(auto it = mp.begin(); it != mp.end(); it++){
        
        cout << (*it).first << ' ' << (*it).second << endl;
        
    }*/

    return 0;
}
