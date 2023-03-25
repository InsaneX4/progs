public class assignment9_5 {
    public static void main(String[] args) {
        Substaff obj = new Substaff(1000);
        obj.bonus();
        obj.earnings();
        obj.deductions();
    }
}
interface value {
    void earnings();
    void deductions();
    void bonus();
}

abstract class Manager implements value{

    @Override
    public void earnings(){};

    @Override
    public void deductions(){};
        
}
 class Substaff extends Manager{

    int Salary;
    Substaff(int Salary){
        this.Salary = Salary;
    }
    @Override
    public void bonus(){
        double  Bonus_Amount = 0.5*this.Salary;
       System.out.println("Bonus: "+Bonus_Amount);
    }

    @Override
    public void earnings() {
        double Total_Earning = Salary + 0.8*Salary + 0.15*Salary;
        System.out.println("Total Earning: "+Total_Earning);

    }

    @Override
    public void deductions() {

       double  PF_Deduction = 0.12*Salary;
       System.out.println("PF Deduction: "+PF_Deduction);
    }
}