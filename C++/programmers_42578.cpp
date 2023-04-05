#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;


bool visited[31] = { 0 };

int get_ans(int size, map<string, int> clothes_type, int start_index, int count, int clothes_size) {
    if (count < size) {
        int ans = 0;
        for (int i = start_index; i < clothes_size; i++) {
            if (!visited[i]) {
                visited[i] = true;
                ans += get_ans(size, clothes_type, i + 1, count + 1, clothes_size);
                visited[i] = false;
            }
        }
        return ans;
    }
    else {
        int ans = 1;
        int index = 0;
        for (auto it : clothes_type) {
            if (visited[index] == true)
                ans *= it.second;
            index++;
        }
        return ans;
    }
}

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    //int clothes_type[4] = {0};  //¾ó±¼, »óÀÇ, ÇÏÀÇ, °Ñ¿Ê ¼øÀ¸·Î
    map<string, int> clothes_type;
    int map_size = 0;

    for (auto it : clothes) {

        if (clothes_type.find(it[1]) == clothes_type.end()) {
            clothes_type.insert(make_pair(it[1], 1));
            map_size++;
        }
        else {
            clothes_type[it[1]]++;
        }
    }

    //answer = clothes.size();

    for (auto it : clothes_type) {
        answer *= (it.second + 1);
    }

    /*for(int i = 2; i <= map_size; i++){
        answer += get_ans(i, clothes_type, 0, 0, map_size);
    }*/

    /*for(auto it : clothes_type){
        cout << it.first << " " << it.second << " " << count(clothes) << endl;
    }*/

    return answer - 1;
}