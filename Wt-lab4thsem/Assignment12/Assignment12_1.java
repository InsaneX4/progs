//package Assignment12;
/*Problem 1: Write a program in Java to copy the content of a given file to another user entered
file using character stream.*/

import java.io.*;

public class Assignment12_1 {
    public static void main(String[] args) throws IOException {

        try{
            FileReader fr = new FileReader("source.txt");
            FileWriter fw = new FileWriter("destination.txt");

            String s = "";

            int i;
            while((i = fr.read()) != -1){
                s += (char)i;
            }
            System.out.println(s);
            fw.write(s);
            fr.close();
            fw.close();
            System.out.println("File reading and writing both done");

        }catch(Exception e){
            System.out.println("There was an error");
        }
        
    }
    
}

