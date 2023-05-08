import java.util.Scanner;

public class StringOperations {
    public static void main(String[] args) {
        String str = "Stay Home Stay Safe";
        System.out.println("String: " + str);
        // Create a StringBuffer object with the input string
        StringBuffer sb = new StringBuffer(str);

        // Change the upper case characters to lower case
        for (int i = 0; i < sb.length(); i++) {
            char c = sb.charAt(i);
            if (Character.isUpperCase(c)) {
                sb.setCharAt(i, Character.toLowerCase(c));
            }
        }
        System.out.println("String: " + sb.toString());

        // Insert "And" after "Home"
        int index = sb.toString().toLowerCase().indexOf("home");
        System.out.println("Index:"+index);
        if (index != -1) {
            sb.insert(index + 4, " And ");
        }
        System.out.println("String: " + sb.toString());
        // Find the index of "Safe"
        index = sb.indexOf("Safe");

        // Reverse the string
        sb.reverse();

        // Display the results
        System.out.println("Lower case string: " + sb.toString());
        System.out.println("Index of 'Safe': " + index);
        System.out.println("Reversed string: " + sb.toString());
        System.out.println("String: " + sb.toString());
    }
}
