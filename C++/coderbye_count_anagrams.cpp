#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

/*
ê²°êµ­ íìì í´ì¼íê³  ì´ë»ê² ì¼ì¹íëê°ì ëí íë³ìì ìê°ì ì¤ì¬ì¼í  ê² ê°ë¤...
mapê³¼ sortingì ì¨ì¼í  ê² ê°ë¤.

log - 1
origin ë¬¸ìì´ì ì¬ì©íë ë°©ë²ì ì³ì§ ììë¤... ê¸°ì¤ì´ ì¬ë¬ê° ë  ì ìë¤... ì ë¶ countíë ê²ì´ ë§ë ê² ê°ë¤.
ì ë ¬ì ê°ì ë¬¸ìì´ì ê°¯ì - ëê°ì ë¬¸ìì´ì ê°¯ì

log - 2
ëë¬´ ì´ë µê² ìê°íë¤... ì¤ë³µì ë¨¼ì  ì ê±°íë©´ ëë ê²ì´ìë¤..
ì¤ë³µ ì ê±° -> setì¬ì© logN
setìì ì ë ¬ í count N * NlogN
O(N * NlongN + logN)ì¼ë¡ í´ê²°ê°ë¥íë¤.
*/

vector<string> get_str_arr(string str) {
  string str_tmp = "";
  vector<string> str_arr;

  for(auto it : str) {
    if(it == ' ') {
      str_arr.push_back(str_tmp);
      str_tmp = "";
    }else {
      str_tmp += it;
    }
  }
  str_arr.push_back(str_tmp);

  return str_arr;
}

string ArrayChallenge(string str) {
  int ans = 0;
  vector<string> str_arr = get_str_arr(str);
  set<string> str_set;
  unordered_map<string, int> count_table;
  unordered_map<string, int> origin_table;

  for(int i = 0; i < str_arr.size(); i++) {
    str_set.insert(str_arr[i]);
  }

  for(auto it : str_set) {

    string str = it;
    string sorted_str = str;
    sort(sorted_str.begin(), sorted_str.end());
    count_table[sorted_str]++;

    // if(count_table[sorted_str] + 1 ==  1) {
    //   count_table[sorted_str]++;
    //   origin_table[sorted_str] = str;
    // }else {
    //   if(origin_table[sorted_str] != str) {
    //     count_table[sorted_str]++;
    //   }
    // }
  }

  for(auto it : count_table) {
    ans += it.second - 1;
  }
  
  // code goes here  
  return to_string(ans);

}

// keep this function call here
int main(void) { 
   
  cout << ArrayChallenge(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}