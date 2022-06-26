#include <iostream>

using namespace std;

int arr[64][64];

void solution(int startRow, int startCol, int size){
  

  int standard = arr[startRow][startCol];
  bool dir = true;

  for(int i = startRow; i < startRow + size; i++){
    for(int j = startCol; j < startCol + size; j++){
      if(standard != arr[i][j]){
        dir = false;
      }
    }
  }

  if(dir){
    cout << standard;
  }else{

    cout << '(';

    int newSize = size / 2;
    solution(startRow, startCol, newSize);
    solution(startRow, startCol + newSize, newSize);
    solution(startRow + newSize, startCol, newSize);
    
    solution(startRow + newSize, startCol + newSize, newSize);
    cout << ')';
    
  }

  
  
  
}

int main(void){
  int N;
  cin >> N;
  string buff;

  for(int i = 0; i < N; i++){
    cin >> buff;
    for(int j = 0; j < N; j++){
      arr[i][j] = buff[j] - 48;
    }
  }

  /*for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cout << arr[i][j] << ' ';
    }
    cout << endl;
  }*/

  solution(0, 0, N);

  

  return 0;
}
