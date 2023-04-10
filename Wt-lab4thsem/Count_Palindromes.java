class Solution 
/*7
refer aios      atv we sbdfcdkb ata i   u sdhsd oo qwenr xsd fgf
asad adsdsd fjdfd jhfgjf fghfg fgkfg fkgtyukf khkgh fkrj rktkrt rtkrjtjrt rtkrtrtrtjkrjt rkjt rkt
ioi wow aww makes sende sense what senes dogo foo fuf abbba sdj djf fghf rtrh rghrf rtrth
A mad man sees beyond what a normal person sees it sometimes doesnt make senes but its true
aaa aaa aa aa a a aaaaaaa aaaa aaa aaaaaaaaaaa aaaa aaaa aaaaaaa aaa aaaaaaa aaa aaa a aaaaaaa
racecar madam nitin nilin malayalam are examples of palindromes you should understand this
fgj sjd zaz djf jaj dkf abba df dkf quq dkfkd dkf waw paw kf wrap push pop pull ppp kg fkjg fg */
{
    public static void main(String[] args) {
        String s = "refer aios      atv we sbdfcdkb ata i   u sdhsd oo qwenr xsd fgf";
        int i = countNumberOfPalindromeWords(s);
        System.out.println("No of Plaindrome " + i);
    }
    public static int countNumberOfPalindromeWords(String s) 
	{   
        
        int count = 0;
        int length2 = 0;
        int length = 0;
        String s1 = "";
        for(int i = 0; i < s.length(); i++){
            length++;
            if(s.charAt(i) == ' ' || i == s.length()-1){
                System.out.println("length2 " + length2 + " length " + length);
                s1 = s.substring(length2, length);
                length2 = i+1;
                System.out.println("S1: "+s1);
                if(isplaindrome(s1) == true){
                    count++;
                }
                
            }
        }
        return count;
    }
    

    static boolean isplaindrome(String s){


        if(s.startsWith(" ")){
            return false;
        }else{
        boolean t = false;
       
        s = s.toLowerCase();  
        //System.out.println(s);
        for(int i=0,j=s.length()-1; i<=j;i++,j--){
            if(s.charAt(j) == ' '){
                j = j-1;
            }
           // System.out.println("i: "+s.charAt(i)+" j: "+s.charAt(j));
            if(s.charAt(i) == s.charAt(j)){
             //   System.out.println(s);
                continue; 
            }else{
                return false;
            }
        }


        return true;
    }
    }
}

