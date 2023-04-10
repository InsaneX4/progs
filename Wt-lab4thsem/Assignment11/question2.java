package Assignment11;
/*Problem 2: Write a Java program to create the following user defined exceptions -- 
HourException, MinuteException and SecondException. Create a class Time that contains
the following data members -- hours, minutes and seconds. In your program, ask users to enter
current time in hh:mm:ss format and throw aforesaid user-defined exceptions in a suitable
manner if user enters hour >24 or <0, minute >60 or <0, and second >60 or <0. */
public class question2 {
    public static void main(String[] args) {
        try {
            new Time(3,30,34);
            new Time(4,20,50);
            new Time(4,20,-1);

        } catch (HourException e) {
            System.out.println("Error: " + e.getMessage());
        } catch (MinuteException e) {
            System.out.println("Error: " + e.getMessage());
        } catch (SecondException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
    
    

}

class HourException extends Exception {
    String msg;
    HourException(String msg) {
        super(msg);
        this.msg=msg;
    }
    
    //overriding with our custom message
    @Override
    public String toString() {
        return msg;
    }
}
class MinuteException extends Exception {
    String msg;
    MinuteException(String msg) {
        super(msg);
        this.msg=msg;
    }
    
    //overriding with our custom message
    @Override
    public String toString() {
        return msg;
    }
}

class SecondException extends Exception {
    String msg;
    SecondException(String msg) {
        super(msg);
        this.msg=msg;
    }
    
    //overriding with our custom message
    @Override
    public String toString() {
        return msg;
    }
}

class Time{
    int hours;
    int minutes;
    int seconds;

    Time(int hours,int minutes,int seconds) throws HourException,MinuteException,SecondException{
       this.hours = gethours(hours);
       this.minutes = getminutes(minutes);
       this.seconds = getseconds(seconds);
        
    }
    //hour >24 or <0, minute >60 or <0, and second >60 or <0. 
    private int getseconds(int seconds2) throws SecondException {
        if(seconds2 > 60 || seconds2 < 0){
            throw new SecondException("this is not a valid seconds value");
        }else{
            return seconds2;
        }
        
    }

    
    private int getminutes(int minutes2) throws MinuteException {
        if(minutes2 > 60 || minutes2 < 0){
            throw new MinuteException("this is not a valid minutes value");
        }else{
            return minutes2;
        }
    }

    private int gethours(int hours2) throws HourException {
        if(hours2 > 60 || hours2 < 0){
            throw new HourException("this is not a valid hours value");
        }else{
            return hours2;
        }
    }


}