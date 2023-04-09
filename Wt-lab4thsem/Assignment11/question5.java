package Assignment11;
/*Problem 5: Write a java program to implement a stack class having methods push () and pop(). These methods must be designed to throw suitable user-defined exceptions when a user tries
either to pop from an empty stack or to push to a full stack. */
public class question5 {
    public static void main(String[] args) {
     stack s = new stack(4);
     s.push(1);   
     s.push(2);
     s.push(3);
     s.push(4);
     s.peek();
     s.pop();
     s.peek();
    }
    
    
}

class stack {
      int top = -1;
      int size;
      int st[];

    stack(int size) {
        this.size = size;
        this.st = new int[size];
        this.top = 0;
    }
  void push(int element){
    if(this.top < this.size){
        this.st[this.top] = element;
        this.top++;
    }else{
        System.out.println("Stack overflow");
        System.exit(0);
    }
   }
    void pop(){
        if(top < 0){
            System.out.println("Stack underflow");
            System.exit(0);
        }else{
         top--;
        }
    }
    void peek(){

        if(this.top >= 0){
            System.err.println("Stack contains------------");
            for(int i = 0 ; i < this.top; i++){
                System.err.println(st[i]);
                

            }
        }else{
            System.out.println("Stack empty");
        }
    }
}