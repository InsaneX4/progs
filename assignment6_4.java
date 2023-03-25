public class assignment6_4 {
    String name;
    int roll;
    double cgpa;
    static double lowest;
    public assignment6_4(String name, int roll, double cgpa) {
        this.name = name;
        this.roll = roll;
        this.cgpa = cgpa;
        if(cgpa<lowest || lowest == 0){
            lowest = cgpa;
        }
    }
    void  display(){
        System.out.println("Name: "+name);
        System.out.println("roll: "+roll);
        System.out.println("Cgpa: "+cgpa);
    }
    void displaylowest(){
        System.out.println(lowest);
    }
    public static void main(String[] args) {
        assignment6_4 obj = new assignment6_4("Dibyansu", 233, 9.3);
        assignment6_4 obj1 = new assignment6_4("Auro", 234, 9.7);
        assignment6_4 obj2 = new assignment6_4("Aditya", 235, 8.3);
        obj.display();
        obj1.display();
        obj2.display();
        obj.displaylowest();

    }

    
}
