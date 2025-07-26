import java.util.Arrays;
import java.util.Collections;

class Solution 
{
    public int solution(int []A, int []B)
    {
        int answer = 0;
        Arrays.sort(A);
        Arrays.sort(B);
        
        for(int i = 0; i < A.length; i++) {
            answer += (A[i] * B[B.length - 1 - i]);
            // System.out.println(answer);
            // System.out.println(A[i] * B[i]);
            // System.out.println(B[i]);
        }

        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        // System.out.println("Hello Java");

        return answer;
    }
}