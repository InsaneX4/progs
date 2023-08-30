class Solution {
    public boolean isPalindrome(int x) {
        if (x == 0) {
            return true;
        }
        if (x < 0 || x % 10 == 0) {
            return false;
        }
        
        int reversed_int = 0;
        while (x > reversed_int) {
            int pop = x % 10;
            x /= 10;
            reversed_int = (reversed_int * 10) + pop;
        }
        
        return x == reversed_int || x == reversed_int / 10;
    }
     public static void main(String[] args) {
        
        Solution obj = new Solution();
        int num1 = 121;
        int num2 = -121;
        int num3 = 10;
        
        System.out.println(num1 + " is palindrome: " + obj.isPalindrome(num1));
        System.out.println(num2 + " is palindrome: " + obj.isPalindrome(num2));
        System.out.println(num3 + " is palindrome: " + obj.isPalindrome(num3));
    }
}


