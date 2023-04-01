package General;

import java.util.Random;


/*Define two packages: general and marketing. In general package define a public
class Employee having data members empid (protected) and empname (private), and a public
method earnings() which calculate total earnings of an employing using the following rule:
Total Earnings = Basic Pay + DA (80% of Basic Pay) + HRA (15% of Basic Pay) */
public class Employee {
    protected int empid;
    private String ename;
    public double earningss;
    public Employee() {
        Random rand = new Random();
        this.empid = rand.nextInt(500);
    
    }

    public void  earnings(String name,int Basic){
        this.ename = name;
        double total_earnings = Basic + 0.8*Basic + 0.15*Basic;

          earningss = total_earnings;
    }
    public String getEname() {
        return ename;
    }
}

