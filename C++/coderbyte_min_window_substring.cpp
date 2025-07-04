#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string MinWindowSubstring(string strArr[], int arrLength) {
  // int count_alphabet[30] = {0};

  string str1 = strArr[0];
  string str2 = strArr[1];

  int ans_left = -1;
  int ans_right = -1;

  int left = 0;
  int right = 0;
  int count = 987654321;
  int count_matched_char = 0;
  int required_matched_char = 0;

  unordered_map<char, int> sub_str_map;
  unordered_map<char, int> main_str_map;

  // sub str map ìì±
  for(auto it: str2) {
    sub_str_map[it]++;
  }

  required_matched_char = sub_str_map.size();

  while(right < str1.size()) {

    char current_char = str1[right];

    main_str_map[current_char]++;

    if( 
      str2.find(current_char) != string::npos &&
      main_str_map[current_char] == sub_str_map[current_char]
      ) 
    {
      count_matched_char++;
    }

    while(left <= right && count_matched_char == required_matched_char) 
    {
      //ê°±ì 
      if(ans_left == -1 || right - left + 1 < count) {
        count = right - left + 1;
        ans_left = left;
        ans_right = right;
      }

      //leftë¥¼ ì¤ì¸ë¤
      // left++;
      char next_str = str1[left];
      main_str_map[next_str]--;
      if(str2.find(next_str) != string::npos &&
      main_str_map[next_str] < sub_str_map[next_str]) {
        count_matched_char--;
      }
      left++;
    }
    right++;
  }
  return str1.substr(ans_left, count);
}

// keep this function call here
int main(void) { 
   
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << MinWindowSubstring(A, arrLength);
  return 0;
    
}