//Write a Java program to print the corresponding grade for the given mark using
//if..else statement.
import java.util.*;
class Second{
	public static void main(String[] args){
	
	// > 90 = A grade
	// > 80 = B grade
	Scanner s = new Scanner(System.in);
	System.out.println("Enter your marks: - ");
	int x = s.nextInt();
	if(x>40){
	System.out.println("Congrats!,You have passed");
	System.out.println("Your Grade is:  ");
	if(x>90 && x<=100){System.out.print("A");}
	if(x>80 && x<=90){System.out.print("B");}
	if(x>70 && x<=80){System.out.print("C");}
	if(x>60 && x<=70){System.out.print("D");}
	if(x>40 && x<=60){System.out.print("E");}
	}else{
		System.out.println("Failed!");
	}

}
}