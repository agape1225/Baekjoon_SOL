class Solution {
    
    public String get_str(Integer num, Integer n){
        
        /*
        num을 n진법으로 변환
        */
        
        /*String return_str = "";
        
        Integer.parseInt(num, n);
        String.valueOf(number);*/
        
        return Integer.toString(num,n);
        
        
    }
    
    public String solution(int n, int t, int m, int p) {
        
        /*
        n: 진법
        t: 구할 자리의 갯수 ?
        m: 게임에 참가하는 인원
        p: 튜브의 순서
        
        t * m 개의 문자열을 구하고 순서대로 -> O(t * m) -> 100000
        
        숫자 -> n진수로 변환 -> 문자열로 변환 -> 길이 측정 -> 만족 때 까지 반복
        */
        
        
        String answer = "";
        String str_arr = "";
        Integer start_num = 0; 
        
        
        while(str_arr.length() <= t * m){
            str_arr = str_arr + get_str(start_num++, n);
        }
        
        int index = 0;
        while(answer.length() < t){
            
            if((index % m) + 1 == p){
                answer = answer + str_arr.toUpperCase().charAt(index);
            }
            index++;
            
        }
        
        return answer;
    }
}
