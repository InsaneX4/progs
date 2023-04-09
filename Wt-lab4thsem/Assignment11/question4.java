package Assignment11;
/*Problem 4: Write a java program to create a BankAccount class with 5000 rupees minimum
balance. In your bank account, you can deposit money and withdraw money. Your account
should throw LessMinimumBalanceException when you try to withdraw an amount that leave
your account a balance less than the minimum balance amount. It also should throw
InvalidWithdrwalException when you try to withdraw an amount that leave your account a
negative account balance. Both the exceptions should display suitable messages for the account
holder. */

public class question4 {
    public static void main(String[] args) {
        try {
           BankAccount B = new BankAccount();
           B.deposit(1000);
            //B.withdraw(500);
           B.withdraw(2000);

        } catch (LessMinimumBalanceException e) {
            System.out.println("Error: " + e.getMessage());
        } catch (InvalidWithdrwalException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
    
}

class BankAccount {
    int balance = 5000;
    void deposit( int addition){
        this.balance = this.balance+addition;
        System.out.println("New Balance: " + this.balance);
    }
    void withdraw(int amount) throws LessMinimumBalanceException, InvalidWithdrwalException{
        if((this.balance - amount) < 0){
            throw new InvalidWithdrwalException("Invalid amount");
        }else if ((this.balance - amount) < 5000 ) {
            
            this.balance = this.balance - amount;
            System.out.println("New Balance: " + this.balance);
            throw new LessMinimumBalanceException("This balance is less than min balance");
            
        }else{
            this.balance = balance -amount;
        }
    }
}

class LessMinimumBalanceException extends Exception {
    String message;
    LessMinimumBalanceException(String message){
        super(message);
        this.message = message;
    }
    @Override
    public String toString() {
        return message;
    }
}
class InvalidWithdrwalException extends Exception {
    String message;
    InvalidWithdrwalException(String message){
        super(message);
        this.message = message;
    }
    @Override
    public String toString() {
        return message;
    }
}