import java.util.*;
public class assignment6_2 {
    
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        while(true){
            System.out.println("1.area of square ");
            System.out.println("2.area of circle");
            System.out.println("3.area of triangle");
            int choice = s.nextInt();
            switch (choice) {
                case 1:{
                    System.out.println("Enter the side of square: ");
                    int side = s.nextInt();
                    area(side);
                    break;
                }
                case 2:{
                    System.out.println("Enter the radius of circle: ");
                    double r = s.nextDouble();
                    area(r);
                    break;
                }
                case 3:{
                    System.out.println("Enter the height and base: ");
                    int height = s.nextInt();
                    int base = s.nextInt();
                    area(height,base);
                    break;
                }
                default:
                    break;
            }
        }
    }
    
    static void  area(int side){
    
        System.out.println(side*side);
    }

     static void area(double r){
        System.out.println(2*3.14*r*r);
    }
     static void area(int height, int base){
        System.out.println(0.5*height*base);
    }
}
