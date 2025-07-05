#include <iostream>
#include <string>
using namespace std;

/*
ë¬¸ì ë¥¼ íìíë ê²ì´ ê°ì¥ ì¤ìíë¤..
íêµ­ì´ë¡ ë¤ì ì í´ë³´ì...

ì°ìë ìë¤ ì¤ ìì ê³¼ ê°ê±°ë, ìì ê³¼ í° ë§ëì í´ë¹íë ë©´ì ì êµ¬íë¤.
ì¤ìí ì ì ì°ìë ìë¼ë ê²ì´ë¤.

í´ë¹ ë©´ì ì´ ê°ì¥ í° ìê° ì ëµì´ë¤
ìì íì í¹ì DPë¡ í ì ìì ê² ê°ë¤.
ìì  íìì´ë©´ ìê° ë³µì¡ëë O(N^N)ì´ë¤.
ê° ë°°ì´ë³ë¡ dpë¥¼ ê°ì§ê³  ì¤ë ìê° ë³µì¡ëë ë¹ì·í´ë³´ì´ ì¼ë¨ ì§íí´ë³´ì...
*/

int get_left(int index, int arr[]) {
  int s_num = (arr[index]);
  int count = 0;
  while(index >=0 && (arr[index]) >= s_num) {
    index--;
    count++;
  }
  //ìì ì ì ì¸í í ì«ìë¥¼ ë°í
  return count - 1;
}

int get_right(int index, int arr[], int arrLength) {
  int s_num = (arr[index]);
  int count = 0;
  while(index < arrLength && (arr[index]) >= s_num) {
    index++;
    count++;
  }
  //ìì ì ì ì¸í í ì«ìë¥¼ ë°í
  return count - 1;
}

int ArrayChallenge(int arr[], int arrLength) {

  int ans = 0;

  for(int i = 0; i < arrLength; i++) {
    int left_count = get_left(i, arr);
    int right_count = get_right(i, arr, arrLength);

    int current_h = arr[i];
    int tmp = current_h + (current_h * left_count) + (current_h * right_count);
    ans = max(ans, tmp);
    
  }
  
  // code goes here  
  return ans;

}

// keep this function call here
int main(void) { 
   
  int A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << ArrayChallenge(A, arrLength);
  return 0;
    
}