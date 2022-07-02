#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void){
  int T;
  cin >> T;

  for(int t = 0; t < T; t++){
    string p, input;
    vector<int> arr;
    string buff = "";
    int n;
    bool is_front = true;
    bool dir = true;
    int index, front, end;

    cin >> p >> n >> input;
    for(auto it = input.begin() + 1; it < input.end() - 1; it++){
      if((*it) != ','){
        buff += *it;
      }else{
        arr.push_back(stoi(buff));
        buff = "";
      }
    }
    if(!buff.empty())
      arr.push_back(stoi(buff));

    index = front = 0;
    end = arr.size() - 1;

    /*for(auto it : arr)
      cout << it << ' ';
    cout << endl;
    cout << index << ' ' << front << ' ' << end << endl;*/
    
    for(auto it : p){
      if(it == 'R'){
        if(is_front)
          index = end;
        else
          index = front;
        is_front = !is_front;
      }else{
        if(front > end){
          cout << "error";
          dir = false;
          break;
        }else{
          if(is_front){
            index++;
            front++;
          }else{
            end--;
            index--;
          }
        }
          
      }
    }
    if(dir){
      if(is_front){
        cout << '[';
        for(int i = front; i < end + 1; i++){
          if(i == end)
            cout << arr[i];
          else
            cout << arr[i] << ',';
          }
        cout << ']';
      }else{
        cout << '[';
        for(int i = end; i >= front; i--){
          if(i == front)
            cout << arr[i];
          else
            cout << arr[i] << ',';
        }
        cout << ']';
      }
    }
    /*for(auto it : arr){
      cout << it << ' ';
    }*/
    cout << '\n';
  }
  return 0;
}
