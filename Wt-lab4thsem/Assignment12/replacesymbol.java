import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class replacesymbol {
    public static void main(String[] args) {
        String fileName = "Employee_emails.txt";
        int count = 0;
        try (BufferedReader reader = new BufferedReader(new FileReader(fileName));
             BufferedWriter writer = new BufferedWriter(new FileWriter(fileName + ".fixed"))) {
            String line;
            while ((line = reader.readLine()) != null) {
                if (line.contains("#")) {
                    count++;
                    line = line.replace("#", "@");
                }
                writer.write(line);
                writer.newLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println("Number of erroneously typed email addresses: " + count);
    }
}
