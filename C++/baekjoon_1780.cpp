/*
  -1: 0
   0: 1
   1: 2
*/

#include <iostream>

using namespace std;

int arr[2187][2187];
int ans[3] = {0};             //정답 저장 변수, 전역변수로 저장

void add_ans(int standard){
  if(standard == -1){
      ans[0]++;
    }else if(standard == 0){
      ans[1]++;
    }else{
      ans[2]++;
    }
}

void solution(int start_row, int start_col, int size){

  int standard = arr[start_row][start_col];
  bool dir = true;

  //cout << endl << start_row << ' ' << start_col << ' ' << size  << endl;
  
  for(int i = start_row; i < start_row + size; i++){
    for(int j = start_col; j < start_col + size; j++){
      //cout << arr[i][j] << ' ';
      if(standard != arr[i][j]){
        dir = false;
        //break;
      }
    }
    //cout << endl;
  }

  if(dir){
    //cout << start_row << ' ' << start_col << ' ' <<  size << ' ' << standard << endl;
    add_ans(standard);
  }else{
    int new_size = size / 3;
    int new_start_row = start_row;
    int new_start_col = start_col;

    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        solution(start_row + new_size * i, start_col + new_size * j, new_size);
      }
    }
    
    /*while(new_start_row < start_row + size){
      solution(new_start_row, start_col, new_size);
      //cout << new_start_row << ' ' << start_col << ' ' << new_size << endl;
      new_start_row = new_start_row + new_size;
    }

    //new_start_col = new_start_col + new_size;
    
    while(new_start_col < start_col + size){
      solution(start_row, new_start_col, new_size);
      //cout << start_row << ' ' << new_start_col << ' ' << new_size << endl;
      new_start_col = new_start_col + new_size;
    }

    solution(start_row + new_size, start_col + new_size, new_size);
    solution(start_row + new_size * 2, start_col + new_size * 2, new_size);*/
  }
  
}

int main(void){

  int N;
  cin >> N;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> arr[i][j];
    }
  }

  int start_row = 0;
  int start_col = 0;
  int size = N;

  solution(start_row, start_col, size);

  for(int i = 0; i < 3; i++)
    cout << ans[i] << endl;
  
  return 0;
  
}
