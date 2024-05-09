#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int maxRow = wallpaper.size();
    int maxCol = wallpaper[0].size();
    
    int ansMaxRow = -1;
    int ansMaxCol = -1;
    int ansMinRow = -1;
    int ansMinCol = -1;
    
    for(int i = 0; i < maxRow; i++){
        // cout << wallpaper[i] << endl;
        if(wallpaper[i].find('#') != string::npos){
            ansMinRow = i;
            break;
        }
    }
    
    for(int i = maxRow - 1; i >= 0; i--){
        if(wallpaper[i].find('#') != string::npos){
            ansMaxRow = i + 1;
            break;
        }
    }
    
    for(int i = 0; i < maxCol; i++){
        bool isFile = false;
        for(int j = 0; j < maxRow; j++){
            if(wallpaper[j][i] == '#'){
                isFile = true;
                break;
            }
        }
        
        if(isFile){
            ansMinCol = i;
            break;
        }
    }
    
    for(int i = maxCol - 1; i >= 0; i--){
        bool isFile = false;
        for(int j = 0; j < maxRow; j++){
            if(wallpaper[j][i] == '#'){
                isFile = true;
                break;
            }
        }
        
        if(isFile){
            ansMaxCol = i + 1;
            break;
        }
    }
    
    answer = {ansMinRow, ansMinCol, ansMaxRow, ansMaxCol};
    
    return answer;
}
