#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> arr[1001];

int BFS(int startNum){
  int ans = 0;
  //int depth = 1;
  bool visited[1001] = {0};
  queue<pair<int, int>> q;
  q.push(make_pair(startNum, 0));
  visited[startNum] = true;

  while(!q.empty()){
    pair<int, int> num = q.front();
    q.pop();
    for(auto i : arr[num.first]){
      if(visited[i] == false){
        //cout << i << ' ' << num.second + 1 << endl;
        q.push(make_pair(i, num.second + 1));
        ans += num.second + 1;
        visited[i] = true;
      }
    }
  }
  
  return ans;
}

int main(void){

  int N, M, buff1, buff2;
  cin >> N >> M;

  for(int i = 0; i < M; i++){

    cin >> buff1 >> buff2;
    arr[buff1].push_back(buff2);
    arr[buff2].push_back(buff1);
    
  }
  
  for(int i = 1; i <= N; i++){
    sort(arr[i].begin(), arr[i].end());  
  }

  int min = 5000;
  int ans = 0;
  for(int i = 1; i <= N; i++){
    if(min > BFS(i)){
      min = BFS(i);
      ans = i;
    }
      
  }

  cout << ans;
  //cout << BFS(1);
  
  /*for(int i = 1; i <= N; i++){
    BFS(i);  
  }*/
  
  
  return 0;
  
}
