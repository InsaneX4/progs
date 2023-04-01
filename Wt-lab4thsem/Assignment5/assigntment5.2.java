import java.util.*;
class assigntment5_2 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int number;
        System.out.println("Enter the number of rows");
        number = s.nextInt();
        System.out.println("Enter the character to print");
        char spc = s.next().charAt(0);
        int m,n;
        for (m = 1; m <= number; m++) {
 
            
            for (n = 1; n <= number - m; n++) {
                System.out.print(" ");
            }
 
            
            for (n = 1; n <= m * 2 - 1; n++) {
                System.out.print(spc);
            }
 
        
            System.out.println();
        }
 
       
     
        
        for (m = number - 1; m > 0; m--) {
 
        
            for (n = 1; n <= number - m; n++) {
                System.out.print(" ");
            }
 
            
            for (n = 1; n <= m * 2 - 1; n++) {
                System.out.print(spc);
            }
 
            // Ending line after each row
            System.out.println();
        }
}
}