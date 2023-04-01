import java.util.*;
class assigntment5_5 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int total_balance = 1000;
        while(true){
            System.out.println("1.Withdraw");
            System.out.println("2.Deposit");
            System.out.println("3.Balance");
            System.out.println("4.Exit");
            int choice = s.nextInt();
            switch(choice){
                case 1:{
                    total_balance =  withdraw(total_balance);
                    break;
                }
                case 2:{
                    total_balance = deposit(total_balance);
                    break;
                }
                case 3:{
                    balance(total_balance);
                    break;
                }
                case 4:{
                    System.out.println("Thankyou for visiting");
                    System.exit(0);
                    break;
                }
                default:{
                    System.out.println("Not in the options!");
                    System.out.println("Please select a valid option");
                    break;
                }
            }
        }

    }
    public static int withdraw(int total_balance){
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the amount you want to withdraw");
        int amount = s.nextInt();
        if(total_balance>amount){
        total_balance = total_balance-amount;
        System.out.println("Amount withdrawed: "+ amount);
        System.out.println("balance remaining:"+total_balance);
        }else{
            System.out.println("Insufficient balance!");
        }
        return total_balance;

    }
    public static int deposit(int total_balance){
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the amount you want to deposit");
        total_balance += s.nextInt();
        System.out.println("Account balance updated: "+total_balance);
        return total_balance;
    }
    public static void balance(int total_balance){
        System.out.println("Account Balance: "+total_balance);
    }
}
