#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <queue>
using namespace std;

/*
mapì ì¬ì©íì¬ ë¸ëë¤ì ì ì¥íë©´ ë  ê² ê°ë¤.
visitedë ëë¤ë¥¸ ë¬¸ì ... nodeë³ë¡ ì ì¥ìê° ìì¼ë©´ ìê°ì ì¤ì¼ ì ìì ê²ì´ë¤.
ìµë ìë ¥ê°ì´ ìê¸°ì ëª¨ë  ê²ì ê°ë³ ì»¨íì´ëë¡ ì§ì í´ì¼í  ê² ê°ë¤.

ìììê° ë³µì¡ëë íë²í BFS.. ê°ì ì ê°ì¤ì¹ë¥¼ ì ë¶ 1ë¡ ëìê¸° ëë¬¸ì´ë¤. O(V + E) 

1. BFSë¥¼ ìí ë°ì´í° ì²ë¦¬ -> visited graph
2. BFS ì§í
*/

void get_nodes(string str, string &final_str1, string &final_str2) {
  string str1 = "";
  string str2 = "";
  bool is_str1 = true;
  for(auto it: str){
    if(it == '-') {
      is_str1 = false;
    }else {
      if(is_str1) {
        str1+=it;
      }else {
        str2+=it;
      }
    }
  }
  final_str1 = str1;
  final_str2 = str2;
}

string GraphChallenge(string strArr[], int arrLength) {

  string ans = "-1";

  //ë¸ëë¡ ì¸ë±ì¤ë¥¼ ì°¾ì ë ì¬ì©í  ìë£í
  unordered_map<string, int> node_to_index_dic;
  //ì¸ë±ì¤ë¡ ë¸ëë¥¼ ì°¾ì ë ì¬ì©í  ìë£í
  vector<string> index_to_node_dic;
  vector<bool> visited;

  //grdph
  unordered_map<string, vector<string>> graph;

  int count_node = stoi(strArr[0]);
  for(int i = 1; i < 1 + count_node; i++) {
    index_to_node_dic.push_back(strArr[i]);
    node_to_index_dic[strArr[i]] = i - 1;
    visited.push_back(false);
  }

  //create graph
  for(int i = 1 + count_node; i < arrLength; i++) {
    string from, to;
    get_nodes(strArr[i], from, to);
    graph[from].push_back(to);
    graph[to].push_back(from);
  }

  //start bfs

  //first -> node name, second -> history
  queue<pair<int, string>> q;
  visited[0] = true;
  q.push(
    make_pair(0, index_to_node_dic[0])
  );

  while(!q.empty()) {
    int current_node_index = q.front().first;
    string history = q.front().second;

    q.pop();

    if(current_node_index == count_node - 1) {
      ans = history;
      break;
    }

    for(auto next_node : graph[index_to_node_dic[current_node_index]]) {
      //ë°©ë¬¸íì§ ìì nodeë§ push
      int next_index = node_to_index_dic[next_node];
      if(!visited[next_index]) {
        visited[next_index] = true;
        q.push(
          make_pair(next_index, history + "-" + index_to_node_dic[next_index])
        );
      }
    }
  }



  return ans;

}

// keep this function call here
int main(void) { 
   
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << GraphChallenge(A, arrLength);
  return 0;
    
}