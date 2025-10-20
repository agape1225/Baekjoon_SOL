
class Solution {
    public String solution(String s) {
        String[] numbers = s.split(" ");
        
        int max = Integer.parseInt(numbers[0]);
        int min = Integer.parseInt(numbers[0]);
        
        for(int i = 1; i < numbers.length; i++) {
            int currentNumber = Integer.parseInt(numbers[i]);
            
            min = Math.min(min, currentNumber);
            max = Math.max(max, currentNumber);
        }
        
        return min + " " + max;
    }
}