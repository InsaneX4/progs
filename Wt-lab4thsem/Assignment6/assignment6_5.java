import java.util.*;

class Number {
    int i;
    static int biggest;
    static int smallest;
    public static void main(String[] args) {
        Number obj = new Number();
        Scanner s = new Scanner(System.in);
        System.out.println("Enter th number of integers");
        int n = s.nextInt();
        System.out.println("Enter "+n+" integers:");
        for(int i = 0 ;i<n;i++){
            obj.read();
        }

        
        obj.display();
        obj.swap();
        obj.display();
        
    }
     void read(){
        Scanner s = new Scanner(System.in);
        i = s.nextInt();
        if(this.i > biggest  || biggest == 0){
            biggest = i;
        }
        if(this.i<smallest|| smallest == 0){
            smallest = i;
        }
    }

    void swap(){
        int temp = biggest;
        biggest = smallest;
        smallest =  temp;
    }
    void display(){
        System.out.println("Biggest number: - "+biggest);
        System.out.print("Smallest number: - "+smallest);
    }
}
