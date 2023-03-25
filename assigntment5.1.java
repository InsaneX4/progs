import java.util.*;


class assigntment5_1 {
    public static void main(String[] args) {
        try (Scanner s = new Scanner(System.in)) {
            while(true){
                System.out.println("Enter the number");
                Double a = s.nextDouble();
                Double b = s.nextDouble();
                Double result;
                
                System.out.println("Enter your choice");
                System.out.println("+");
                System.out.println("-");
                System.out.println("*");
                System.out.println("/");
                char choice = s.next().charAt(0);
                System.out.println("Result: - ");
                switch(choice){
                    case '+':{
                        result = a+b;
                        System.out.println(result);
                        break;
                    }
                    case '-':{
                        result = a-b;
                        System.out.println(result);
                        break;
                    }
                    case '*':{
                        result = a*b;
                        System.out.println(result);
                        break;
                    }
                    case '/':{
                        result = a/b;
                        System.out.println(result);
                        break;
                    }
                    default:{
                        System.out.println("Not Available");
                    }
                }

            }
        }
    }
}
