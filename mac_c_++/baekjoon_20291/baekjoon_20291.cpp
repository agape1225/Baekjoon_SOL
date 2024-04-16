#include <iostream>
#include <string>
#include <map>

using namespace std;

string get_file_extenstion(string file_name){
    string extenstion = "";
    int index = 0;
    for(int i = 0; i < file_name.size(); i++){
        if(file_name[i] == '.'){
            index = i+ 1;
        }
    }

    for(int i = index; i < file_name.size(); i++){
        extenstion += file_name[i];
    }

    return extenstion;

}

int main(void){
    map<string, int> file_dic;
    int N;

    cin >> N;

    for(int i = 0; i < N; i++){
        string file;
        string extenstion;
        cin >> file;

        extenstion = get_file_extenstion(file);
        auto it = file_dic.find(extenstion); 
        if(it != file_dic.end()){
            int file_count = it->second;
            file_dic.erase(it);
            file_dic.insert(make_pair(extenstion, file_count + 1));
        }else{
            file_dic.insert(make_pair(extenstion, 1));
        }
    }

    for(auto it : file_dic){
        cout << it.first << ' ' << it.second << '\n';
    }

    return 0;

}