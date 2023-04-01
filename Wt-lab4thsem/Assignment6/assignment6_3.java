import java.util.Scanner;
class assignment6_3{
    int length;
    int breadth;
    Scanner s = new Scanner(System.in);

    public void area(){
        int i = 1;
        System.out.println("Enter the length and breadth");
        length  = s.nextInt();
        breadth = s.nextInt();
        display(length*breadth,i);;
    }
    public  void perimeter(){
        int i = 2;
        System.out.println("Enter the length and breadth");
        length  = s.nextInt();
        breadth = s.nextInt();
        display(2*(length+breadth),i);
    }
    public void read(){
        System.out.println("1.Area");
        System.out.println("2.Perimeter");
        int choice = s.nextInt();
        switch(choice){
            case 1:{
                area();
                break;
            }
            case 2:{
                perimeter();
                break;
            }
        }
    }

    public void display(int n,int i){
        if(i == 1){
        System.out.println("Area = "+n);
        }else{
            System.out.println("Perimeter = "+n);

        }
    }
    public static void main(String[] args) {
        assignment6_3 r = new assignment6_3();
        while(true){
            r.read();
        }
    }
}