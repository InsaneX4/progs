import java.util.*;
class assigntment5_4 {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter three numbers");
        int a = s.nextInt();
        int b = s.nextInt();
        int c = s.nextInt();
        int res = (a<b)?a:b;
        res = (res<c)? res:c;
        System.out.println("Smallest number among these three is: "+res);
        res = (a>b)?a:b;
        res = (res>c)? res:c;

        System.out.println("largest number among these three is: "+res);
    }
}
