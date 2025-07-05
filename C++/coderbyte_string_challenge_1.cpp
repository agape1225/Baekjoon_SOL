#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
ì ê·íë¥¼ ì¬ì©í íì´ê° íìí ê² ê°ë¤. í .. ë¶í ì ë³µ ë¬¸ì ë ìëê² ê°ë¤..
ê° ë¬¸ìì ìì¹ë¥¼ ì¬ì©íë¤ë©´ ê°ë¥í  ê² ê°ê¸°ë íë¤... ì¤ìíì ì ì´ê±¸ string ê°ì²´ íëì ë´ìì¼íë¤ë ê²ì´ë¤.
ìê°í´ë³´ë êµ³ì´ ë¬¸ìì´ì ì¤ë°ê¿ì ë§ë¤ íìë ìì ê² ê°ë¤...

ìì ìê° ë³µì¡ëë O(N^2)
ì ëµ ìê° ë³µì¡ë O(N^M)
*/

string StringChallenge(string strArr[], int arrLength) {
  string ans_str = "";
  int count = stoi(strArr[1]);
  //ê°ê²©
  int diff = (count - 2) * 2 + 1;

  if(count == 1) {
    diff = 0;
  }

  vector<string> str_arr;
  str_arr.push_back(strArr[0]);

  while(str_arr.size() > 0) {
    vector<string> new_str;
    for(auto str : str_arr) {
      //str -> ìë¸ ë¬¸ìì´
      string next_sub_str = "";
      int next_index = 0;

      for(int i = 0; i < str.size(); i++) {
        if(i == next_index) {
          ans_str += str[i];
          if(next_sub_str != "") {
            new_str.push_back(next_sub_str);
            next_sub_str = "";
          }
          next_index += diff + 1;
        }else {
          next_sub_str += str[i];
        }
      }

      if(next_sub_str != "" ) {
        new_str.push_back(next_sub_str);
      }
    }

    str_arr = new_str;
    //diff ì¡°ì ;
    count--;
    diff = (count - 2) * 2 + 1;

    if(count == 1) {
      diff = 0;
    }

  }


  
  // code goes here  
  return ans_str;

}

// keep this function call here
int main(void) { 
   
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << StringChallenge(A, arrLength);
  return 0;
    
}