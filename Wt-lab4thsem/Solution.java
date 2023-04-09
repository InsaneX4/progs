public class Solution 
{
    public static void main(String[] args) {
        String s = "Madam oyo cat";
        int i = countNumberOfPalindromeWords(s);
        System.out.println("Stringlen: " + s.length());
    }
    public static int countNumberOfPalindromeWords(String s) 
	{
        int length2= 0;
        int count = 0;
        for(int i = 0 ;i<s.length();i++){
            int length =+ 1;
            if(s.charAt(i) == ' ' || s.charAt(i) == s.charAt(s.length()-1)){
                System.out.println("s.charAt(i): "+s.charAt(i)+"charAt(s.length()-1): "+s.charAt(s.length()-1)+"i: "+i);
                String s1 = new String();                               // "Madam oyo cat"
                for(int j = 0;j<length;j++){
                    
                    if(s.charAt(length2) != ' '){
                     s1  = s.substring(length2, i);
                    }else if(i == s.length()-1){
                        length2 = i -length2;
                        s1  = s.substring(length2+1, i);

                    }else{
                        s1  = s.substring(length2+1, i);
                    }
                System.out.println("length: "+length+"length2: "+length2+"length1: "+length+"i: "+i);

                    length2 = s1.length();
                
                System.out.println("length: "+length+"length2: "+length2+"length1: "+length+"i: "+i);
                System.out.println(s1);
                }
            }
            
        }
        return count;
    }
}