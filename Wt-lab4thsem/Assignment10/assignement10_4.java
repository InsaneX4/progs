
import java.util.Hashtable;
import java.util.Scanner;

/*Problem 4: An anagram is a word or a phrase made by transposing the letters of another word
or phrase; for example, "parliament" is an anagram of "partial men," and "software" is an
anagram of "swear oft." Write a program that figures out whether one string is an anagram of
another string. The program should ignore white space and punctuation. */
public class assignement10_4 {
    public static void main(String[] args) {
           // Scanner s = new Scanner(System.in);
            //System.out.println("Enter First String");
            //String s1 = s.nextLine();
           // System.out.println("Enter Second String");
           // String s2 = s.nextLine();
           boolean isAnagram = isAnagram("Partial men", "Parliament");
           if(isAnagram== true){System.out.println("is an angram");}
           else{System.out.println("Not an angram");}
        
    }

    private static boolean isAnagram(String s1, String s2) {
        Hashtable<Integer,Integer> H = new Hashtable<Integer, Integer>();

        for(int i = 0; i < s1.length(); i++) {
            if(s1.charAt(i) != ' '){
            H.put(s1.charAt(i)-65, 1);
            System.out.print(s1.charAt(i)+": ");
            System.out.println(s1.charAt(i)-65);
            }
            else{
                continue;
            }
        }
        System.out.println("----------------------");
        for(int i = 0; i < s2.length(); i++) {
            if(s2.charAt(i) != ' '){
                
                if(H.containsKey(s2.charAt(i)-65)){
                    if(H.get(s2.charAt(i)-65)> 0){
                    H.put(s2.charAt(i)-65, 0);
                    System.out.print(s2.charAt(i)+": "); 
                    System.out.println(s2.charAt(i)-65);
                    } else{
                       // return false;
                    }
                }else{
                    return false;
                }
            
            }else{
                continue;
            }
        }
        return true;
    }
}
