#include <iostream>
#include <string>
using namespace std;

string ans = "not possible";

// ê° ìì + í¹ì -ë¥¼ ë¶ì´ë ë¬¸ì  ê²°êµ­ì ìì íìì¼ë¡ íì´ì¼í  ê² ê°ë¤.

/*
count: 100, 10 -> 0ì´ë©´ ì¢ë£ ì¡°ê±´
*/

//26721ì´ë©´ 10000ë°í -> ëª«ë§ì ì¶ë ¥í  ì ìê²
int get_count(int num) {
  int count = 1;
  while(num / count > 9) {
    count *= 10;
  }
  return count;
}

int count_minus(string pre) {
  int count = 0;
  for(auto it : pre) {
    if(it == '-') {
      count++;
    }
  }
  return count;
}

void get_math(int count, int num, string ans_pre, int final_num) {
  //ì¬ê·ì ì¢ë£ì¡°ê±´
  if(num == 0) {
    if(final_num == 0) {
      if(ans == "not possible") {
        ans = ans_pre;
      }else if(count_minus(ans) < count_minus(ans_pre)) {
        ans = ans_pre;
      }
    }
    return;
  }

  get_math(count / 10, num % count, ans_pre + "-", final_num - num / count);
  get_math(count / 10, num % count, ans_pre + "+", final_num + num / count);
}

string MathChallenge(int num) {

  int count = get_count(num);
  get_math(count / 10, num % count, "", num / count);
  
  // code goes here  
  return ans;

}

// keep this function call here
int main(void) { 
   
  cout << MathChallenge(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}