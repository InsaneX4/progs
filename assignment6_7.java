import java.util.*;

public class assignment6_7 {
public static void main(String[] args) {

Scanner sc=new Scanner(System.in);

System.out.println("1. Area of Square.");

System.out.println("2. Area of a Rectangle.");

System.out.println("3. Area of a circle.");

System.out.print("\nEnter your choice: ");

switch(sc.nextInt())

{

case 1:

System.out.print("Enter side length: ");

double s=sc.nextDouble();

s*=s;

System.out.println("Area of the Square is: "+s);

break;

case 2:

System.out.print("Enter length of rectangle: ");

double l=sc.nextDouble();

System.out.print("Enter breadth of rectangle: ");

double b=sc.nextDouble();

System.out.println("Area of the rectangle is: "+l*b);

break;

case 3:

System.out.print("Enter radius of the circle: ");

double rad=sc.nextDouble();

double ar=Math.PI*rad*rad;

System.out.println("Area of the circle is: "+ar);

break;

default: System.out.println("Invalid Choice.");

}

sc.close();

}

}

