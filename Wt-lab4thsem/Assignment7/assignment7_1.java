public class assignment7_1 {
    public static void main(String[] args) {
         double a = Double.parseDouble(args[0]);
         double b = Double.parseDouble(args[1]);
         double c = Double.parseDouble(args[2]);
        if(a>b && a>c){
            System.out.println("a is greatest: "+a);
        } if(b>a && b>c){
            System.out.println("b is greatest: "+b);
        } if(c>b && c>a){
            System.out.println("c is greatest: "+c);
        }
    }
}
