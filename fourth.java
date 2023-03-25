import java.util.*;
class fourth {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = 0;
        System.out.println("Enter the number");
        n = s.nextInt();
        int temp = n;
       while(true){
    System.out.println("1.Press 1 to check palindrome");
    System.out.println("2.Press 2 to check amstrong");
    System.out.println("3.New number");
       int choice = s.nextInt();
       switch(choice){
           case 1:{
        int sum = 0;
        int rev = 0;
        temp = n;
        for(int i =0 ;i<=n;i++){
            rev = (n%10);
            sum = (sum*10)+rev;
            n = n/10;
        }
        if(temp == sum){
            System.out.println("Yes,it is a plaindrome number");
        } else{
          System.out.println("NO!,not an palindrome number");
        }
        break;
      }
        case 2:{
             // amstrong = sum of cube of each digits equal to the same number
        
        n = temp;
        int sum = 0;
        for(int i = 0;i<=n;i++){
            sum += (n%10) * (n%10) * (n%10);
            n = (n/10);
           
        }
        if(temp == sum){
            System.out.println("Yes,it is a amstrong number");
        } else{
          System.out.println("NO!,not an amstrong number");
        }
        break;
      }
      case 3:{
           System.out.println("Enter the number");
        n = s.nextInt();
      }
       }
       }
    }
}