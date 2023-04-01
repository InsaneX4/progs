
import java.util.HashSet;
import java.util.Scanner;

/*Problem 4: An anagram is a word or a phrase made by transposing the letters of another word
or phrase; for example, "parliament" is an anagram of "partial men," and "software" is an
anagram of "swear oft." Write a program that figures out whether one string is an anagram of
another string. The program should ignore white space and punctuation. */
public class assignement10_4 {
    public static void main(String[] args) {
        HashSet<Character> hs = new HashSet<>();
     try (Scanner sc = new Scanner(System.in)) {
        System.out.print("Enter the first string: ");
         String s1 = sc.nextLine();
         for(int i = 0; i < s1.length(); i++){
            hs.add(s1.charAt(i));
         }
         System.out.print("Enter the second string: ");
         String s2 = sc.nextLine();
         int countlength = 0 ;
         for(int i = 0; i < s2.length(); i++){
         if(hs.contains(s2.charAt(i))){
            countlength += 1;
         }
        }
        if(countlength == s1.length()){
            System.out.println("The strings are anagrams");
        }else{
            System.out.println("The strings are not anagrams");
        }
    }
    }
}
