class Subtracter{  
    static int Subtract(int a, int b){return a-b;}  
    static double Subtract(double a, double b){return a-b;}  
    } 
public class assignment6_6 {
    public static void main(String[] args) {
        System.out.println(Subtracter.Subtract(11,11));  
        System.out.println(Subtracter.Subtract(12.3,12.6));  
    }}
