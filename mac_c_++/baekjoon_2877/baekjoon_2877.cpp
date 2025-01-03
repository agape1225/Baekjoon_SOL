#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// 몇 자리인지 얻는 함수
int getDigit(int k){

    int idx = 1; // 자리수
    int sum = 1; //합
    do{
        sum += pow(2,idx); // 2의 제곱씩 더함
        idx++;
    }while(k >= sum); // sum이 더 커질때까지 반복
    return idx-1;
}
void makeTable(string base, int remain){

    for(int i = base.length()-1; i >= 0; i--){
        if(remain % 2 != 0) base[i] = '7';
        remain /= 2;
    }
    cout << base << "\n";
}
int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int K;
    cin >> K;

    int digit = getDigit(K);
    int remain;
    int consume = 0; // 소비한 수
    
    //remain을 구하기 위해 자릿수만큼 번째를 다 구함
    for(int i = 0; i < digit; i++) consume += pow(2,i);

    remain = K-consume;
    string base;
    for(int i = 0; i < digit; i++) base.push_back('4'); // digit큼 4로 채움
    makeTable(base,remain);
}