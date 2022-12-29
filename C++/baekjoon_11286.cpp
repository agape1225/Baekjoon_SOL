#include <iostream>
#include <algorithm>>
#include <vector>
#include <set>

using namespace std;

struct Compare {
	bool operator() (const long &a, const long &b) const{
		  long buffA = a;
      long buffB = b;
      if(a < 0)
        buffA = a * - 1;
      

      if(b < 0)
        buffB = b * -1;

      if(buffA == buffB)
        return a <= b;
      else
        return buffA <= buffB;
	}
};



int main(void){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  long input;
  set<long, Compare> s;
  
  cin >> N;

  for(int t = 0; t < N; t++){
    
    cin >> input;
    if(input != 0){
      s.insert(input);

    }else{

      if(s.empty())
        cout << 0 << '\n';
      else{
        cout << *s.begin() << endl; 
        s.erase(s.begin());
      }
    }
      
  }

  return 0;
}
