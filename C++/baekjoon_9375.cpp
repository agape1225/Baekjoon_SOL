#include <iostream>
#include <map>

using namespace std;

int main(void){

  int T;
  cin >> T;

  
  
  for(int t = 0; t < T; t++){
    int n;
    map<string, int> costume;
    string name, type;
    int count = 0;
    int ans = 0;

    cin >> n;

    for(int i = 0; i < n; i++){
      
      cin >> name >> type;
      auto it = costume.find(type);

      if(it == costume.end()){
        count++;
        costume.insert(make_pair(type, 1));  
      }else{
        int buff = (*it).second;
        buff++;
        costume.erase(type);
        costume.insert(make_pair(type, buff));
      }
    }

    ans += costume.size();
    
    for(int i = 2; i <= count; i++){
      
    }
    
    /*for(auto it = costume.begin(); it != costume.end(); it++){
      cout << (*it).first << ' ' << (*it).second << endl;
    }*/
  }

  

  return 0;
  
}
