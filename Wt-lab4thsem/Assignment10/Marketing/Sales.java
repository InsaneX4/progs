package Marketing;

import java.util.Scanner;

/*In marketing package, define a public class Sales inheriting the Employee class and containing
an additional method travelallowance() that calculates Travelling Allowance as 5% of total
earning of the employee. Write a Java program to find out the total earning of a group of five
sales persons for the given basic pay amount and print along with their employee ids. Use array
of objects where necessary. Assign employee ids as randomly-generated four-digit numbers.*/

import General.*;

public class Sales extends Employee {

    public void travelallowance(int total_earnings){
        System.out.println("Travel Allowance: "+(total_earnings*0.05));
    }

    public static void main(String[] args) {
       Sales[] s = new Sales[5];

       for(int i =0;i<2;i++){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter name and Basic Salary of the employee: ");
        s[i]=new Sales();
        s[i].earnings(sc.next(),sc.nextInt());
       }

       for(int i =0;i<2;i++){
        System.out.println(s[i].empid+"  "+s[i].getEname()+" "+s[i].earningss);
    
       }

    }
    
}
