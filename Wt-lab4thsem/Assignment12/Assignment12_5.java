import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;


/*Problem 5: Write a Java program that will count the number of lines, the number of words, and
the number of characters in each file that is specified on the command line. Assume that the files
are text files. Note that multiple files can be specified, as in "java LineWordCharCount filel .txt
file2.txt file3.txt". Write each file name, along with the number of lines, the number of words,
and the number of characters in that file, to standard output. If an error occurs while trying to
read from one of the files, you should print an error message for that file, but you should still
process all the remaining files. */
public class Assignment12_5 {
    public static void main(String[] args) {
       // BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int i = 0;
        for(i = 0; i < args.length; i++) {
        System.out.println(args[i]);
        fileread(args[i]);
        }
    
    }

    public static void fileread(String fileName){
        // replace with your file name
        try {
            // Open the input file
            FileReader fileReader = new FileReader(fileName);
            BufferedReader bufferedReader = new BufferedReader(fileReader);
            String line;
            StringBuilder capitalizedText = new StringBuilder();
            int wordcount = 0;
            //String longestword = "";
            int linecount = 0;
            int charcount = 0;

            // Read each line from the file
            while ((line = bufferedReader.readLine()) != null) {
                linecount++;
                // Split the line into words
                String[] words = line.split("\\s+");
                // Capitalize the first letter of each word
                for (String word : words) {
                    if (!word.isEmpty()) {
                        char firstChar = Character.toUpperCase(word.charAt(0));
                        String capitalizedWord = firstChar + word.substring(1);
                        capitalizedText.append(capitalizedWord).append(" ");
                        wordcount++;
                        for(int i = 0; i < word.length(); i++) {
                            if(word.charAt(i) != ' '){
                                charcount++;
                            }
                        }
                    }
                }
                capitalizedText.append("\n");
            }
            bufferedReader.close();
            System.out.println("Linecount: " + linecount);
            System.out.println("Wordcount: " + wordcount);
            System.out.println("charcount: " + charcount);
        
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
