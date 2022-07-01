#include <iostream>
#include <set>

using namespace std;

int main(void){

  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  set<int> s1;
  set<int> s2;
  int A, B;
  int buff;
  int count = 0;
  cin >> A >> B;

  for(int i = 0; i < A; i++){
    cin >> buff;
    s1.insert(buff);
  }

  for(int i = 0; i < B; i++){
    cin >> buff;
    s2.insert(buff);
  }

  for(auto it = s1.begin(); it != s1.end(); it++){
    if(s2.find(*it) == s2.end())
      count++;
  }

  for(auto it = s2.begin(); it != s2.end(); it++){
    if(s1.find(*it) == s1.end())
      count++;
  }

  cout << count;
  
  return 0;
  
}
