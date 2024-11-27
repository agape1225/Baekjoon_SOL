#include <iostream>
#include <algorithm>

using namespace std;

int count_alphabet[26] = {0};

int get_alpha_count(){
    int count = 0;
    for(int i = 0; i < 26; i++){
        if(count_alphabet[i] > 0){
            count++;
        }
    }
    return count;
}

int main(void){
    
    int N;
    string str;
    int ans = 0;

    cin >> N >> str;

    count_alphabet[str[0] - 'a']++;

    int begin = 0;
    int end = 0;

    ans = max(ans, end - begin + 1);

    for(end = 1; end < str.size(); end++){
        char current_alpha = str[end];
        count_alphabet[current_alpha - 'a']++;

        int alphabet_count = get_alpha_count();

        if(alphabet_count <= N){
            ans = max(ans, end - begin + 1);
        }else{
            while(alphabet_count > N){
                char prev_alpha = str[begin];
                begin++;

                count_alphabet[prev_alpha - 'a']--;
                alphabet_count = get_alpha_count();
            }
            ans = max(ans, end - begin + 1);
        }
    }

    cout << ans;

    return 0;
}