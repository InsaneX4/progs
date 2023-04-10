public class Count_Binary_Substrings {
    public static void main(String[] args) {
        // 01 10 1100 0011
        // "00110011"

    }
    public int countBinarySubstrings(String s) {

        int count = 0;
        int length = 0;
        int consecutivesame = 0;
        int consecutivediff = 0;

        for(int i = 0;i<s.length();i++) {
            if(s.charAt(i) == s.charAt(i+1)) {
                consecutivesame++;
            }else{
                consecutivediff++;
                count++;
                if(consecutivesame > 0) {

                }
            }
            
        }
        return 0; 
    }
}
