#include <iostream>
#include <queue>
using namespace std;

int arr[100][100];
int ans[100][100] = {0};

int main(void){

  int N;
  queue<int> q;
  cin >> N;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> arr[i][j];
    }
  }

  for(int i = 0; i < N; i++){
    bool visited[100] = {0};
    for(int j = 0; j < N; j++){
      if(arr[i][j]){
        //ans[i][j] = 1;
        //visited[j] = true;
        q.push(j);
      }
      while(!q.empty()){
        int front = q.front();
        q.pop();
        ans[i][front] = 1;
        visited[front] = true;
        for(int k = 0; k < N; k++){
           if(!visited[k] && arr[front][k]){
           q.push(k);
          }
        }
      }
    }
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cout << ans[i][j] << ' ';
    }
    cout << '\n';
  }
  
  return 0;
  
}
