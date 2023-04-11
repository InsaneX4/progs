public class Count_Binary_Substrings {
    public static void main(String[] args) {
        // 01 10 1100 0011
        // "00110011"
        Count_Binary_Substrings obj = new Count_Binary_Substrings();
        System.out.println(obj.countBinarySubstrings("00110011"));

    }
    public int countBinarySubstrings(String s) {

        int count = 0;
        int length = 0;
        int consecutivesame = 0;
        int consecutivediff = 0;

        for(int i = 0;i<s.length();i++) {
            if(s.charAt(i) != s.charAt(s.length()-1)){
            if(s.charAt(i) == s.charAt(i+1)) {
                consecutivesame++;
                if(consecutivesame != consecutivediff){
                    count++;
                }
            }else{
                consecutivediff++;
                count++;
            }
        }
            
        }
        return count; 
    }
}
