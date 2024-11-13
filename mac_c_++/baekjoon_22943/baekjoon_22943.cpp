#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define MAXSIZE 99999

int ans = 0;
int K, M;
bool v[10] = {false};
// 나올 수 있는 소수 다 찾기(에라토스테네스의 체)
vector<int> getPrime(int length){
    bool prime[length]; // length 길이만큼 배열 생성
    vector<int> list; // 최종적으로 반환할 vector
    list.reserve(length); // 미리 length만큼의 공간 할당


    for(int i = 2; i <= length; i++) prime[i] = true; // 기본 true

    
    for(int i = 2; i*i <= length; i++){
        if(prime[i]){
            // i가 소수면 i이후의 i 배수는 소수가 아님(약수로 i로 가짐)
            // i * k (k < i)까지 이미 검사됐으므로 j 시작 값을 i*2에서 i*i로 개선 가능
            for(int j = i * i; j <= length; j += i) prime[j] = false;
        }
        // prime[i]가 false면 i와 i 배수는 어차피 소수가 아님(검사할 필요 없음)
    }
    // true(소수) 값을 list에 담음
    for(int i = 2; i <= length; i++) if(prime[i]) list.push_back(i);

    return list;
}

// 서로 다른 소수의 합
vector<bool> getSum(vector<int> prime,int length){
    vector<bool> list;
    list.resize(length,false);
    for(int i = 0; i < prime.size(); i++){
        // 최대 크기를 넘어가면 반복문 탈출
        if(prime[i] >= length) break;
        for(int j = 0; j < prime.size(); j++){
            if(i == j) continue; // 두 소수가 같은 경우 제외
            int val = prime[i] + prime[j];
            // 최대 크기보다 작은 경우만
            if(val < length) list[val] = true;
        }
    }
    return list;
}

vector<bool> getMultiple(vector<int> prime,int length){
    vector<bool> list;
    list.resize(length,false);
    for(int i = 0; i < prime.size(); i++){
        if(prime[i] >= length) break;
        for(int j = 0; j < prime.size(); j++){
            long val = (long)prime[i] * (long)prime[j];
            if(val < length) list[val] = true;
        }
    }
    return list;
}

// 해당 숫자가 소수인지 판단
bool isPossible(int num, vector<bool> addList, vector<bool> mulList){

    if(!addList[num]) return false;
    
    // 나눠지지 않을때까지 나눔
    while(num % M == 0) num /= M;
    
    if(!mulList[num]) return false;
    return true;

}
// 중복되지 않는 K자리 수 만들기
void findCommon(int idx, int cnt,vector<bool> addList, vector<bool> mulList){
    // K자리 수가 다 만들면 소수인지 확인
    if(idx == 0){
        if(isPossible(cnt,addList,mulList)){
            ans++;
        } 
        return;
    }
    // 0 ~ 9까지 한번씩 호출
    for(int i = 0; i <= 9; i++){
        // 맨 앞자리 0이 들어오는 거 방지
        if((i == 0 && idx == K) || v[i]) continue;

        // 방문 체크로 중복 방지
        v[i] = true;
        findCommon(idx-1,cnt*10+i,addList,mulList);
        v[i] = false;
    }
}
int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    cin >> K >> M;
    int length = pow(10,K);
    vector<int> prime = getPrime(length);
    vector<bool> addList = getSum(prime,length);
    vector<bool> mulList = getMultiple(prime,length);

    findCommon(K,0,addList,mulList);
    cout << ans;
}