import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

//Problem 4: Write a Java program to find the longest word in a text file.
public class Assignment12_4 {
    public static void main(String[] args) {
       
        String fileName = "source.txt"; // replace with your file name
        try {
            // Open the input file
            FileReader fileReader = new FileReader(fileName);
            BufferedReader bufferedReader = new BufferedReader(fileReader);
            String line;
            StringBuilder capitalizedText = new StringBuilder();
            int longestlength = 0;
            String longestword = "";
            // Read each line from the file
            while ((line = bufferedReader.readLine()) != null) {
                // Split the line into words
                String[] words = line.split("\\s+");
                // Capitalize the first letter of each word
                for (String word : words) {
                    if (!word.isEmpty()) {
                        char firstChar = Character.toUpperCase(word.charAt(0));
                        String capitalizedWord = firstChar + word.substring(1);
                        capitalizedText.append(capitalizedWord).append(" ");
                        if(word.length()> longestlength ){
                            longestlength = word.length();
                            longestword = word;
                        
                        }
                    }
                }
                capitalizedText.append("\n");
            }
            bufferedReader.close();
            System.out.println("The longest word is " + longestword+" with word length " + longestlength);
        
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
