package Assignment11;
/*Problem 3: Create an user defined exception named CheckArgumentException to check
the number of arguments passed through command line in a Java Program. If the number of
arguments is less than four, throw the CheckArgumentException, else print the addition of
squares of all the numbers entered through command line. */

public class question3 {
    public static void main(String[] args) throws CheckArgumentException {
        int i = 0;
        int length = 0; 
        for(String s : args) {
           Integer.parseInt(args[i]);
           System.out.println(s);
            length++; 
            i++;
        }
       if(length < 4){
            throw new CheckArgumentException("length must be less than four");
        }else{
            System.out.println("length: "+length);
        }
        
        
    }
    
}

class CheckArgumentException extends Exception {
    String message;
    CheckArgumentException(String message){
        super(message);
        this.message = message;
    }
     //overriding with our custom message
     @Override
     public String toString() {
         return message;
     }
}
