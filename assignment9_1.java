

abstract class Student{
    String name;
    int rollno;
    int regno;

    Student(String name, int rollno, int regno){
        this.name = name;
        this.rollno = rollno;
        this.regno = regno;

    }

    abstract void course();
    abstract void academics();

}

class Kiitians extends Student{

    Kiitians(String name, int rollno, int regno){
        super(name, rollno, regno);
    }
    public static void main(String[] args) {
        Kiitians stud1 = new Kiitians("Dibyansu",22057029,1234);
        stud1.course();
        stud1.academics();
    }

    @Override
    void course() {
        // TODO Auto-generated method stub
        System.out.println(name);
        System.out.println(rollno);
        System.out.println(regno);
       
        System.out.println("Course: Cse");
        //throw new UnsupportedOperationException("Unimplemented method 'course'");
    }

    @Override
    void academics() {
        // TODO Auto-generated method stub
        System.out.println("Academics:");
        System.out.println("OS");
        System.out.println("Dsa");
        System.out.println("DBMS");
       // throw new UnsupportedOperationException("Unimplemented method 'academics'");
    }
    
}

