import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

//package Assignment12
//Problem 3: Write a Java program to capitalize first letter of every word in a file.
public class Assignment12_3 {
    public static void main(String[] args) {

        
        String fileName = "source.txt"; // replace with your file name
        try {
            // Open the input file
            FileReader fileReader = new FileReader(fileName);
            BufferedReader bufferedReader = new BufferedReader(fileReader);
            String line;
            StringBuilder capitalizedText = new StringBuilder();
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
                    }
                }
                capitalizedText.append("\n");
            }
            bufferedReader.close();
            // Write the capitalized text back to the file
            FileWriter fileWriter = new FileWriter(fileName);
            BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
            bufferedWriter.write(capitalizedText.toString());
            bufferedWriter.close();
            System.out.println("Successfully capitalized first letter of every word in the file.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
