/*Problem 3: Create an abstract class MobilePhone having a concrete method voiceCall() and
two abstract methods: displayCamera() and displayTouchscreen(). Further implement three
concrete classes RedmiPhone, SamsungPhone and NokiaPhone, all extend MobilePhone and
have the following additional features: RedmiPhone and SamsungPhone have common
additional method fingerPrint(); and RedmiPhone has a unique method turboCharge(). On
implementation of all the classes, demonstrate runtime polymorphism in Java. For implementing
a method, write meaningful print statement in its body.*/

abstract class MobilePhone {

    String PhoneName;

    MobilePhone(String name){
        this.PhoneName = name;
    }

    void voiceCall(){
        System.out.println("Calling.......");
    }
    abstract void displayCamera();
    abstract void displayTouchscreen();
}
interface additional{
    
    void fingerPrint();
}
class RedmiPhone extends MobilePhone implements additional{

        RedmiPhone(String name) {
        super(name);
        //TODO Auto-generated constructor stub
    }
        
        public void fingerPrint(){
            System.out.println("Taking finger print....");
        }
        void turboCharge(){
            System.out.println("Turbo charging activated....");
        }
        @Override
        void displayCamera() {
            // TODO Auto-generated method stub
                System.out.println(PhoneName+"Display is On....");
        }
        @Override
        void displayTouchscreen() {
            // TODO Auto-generated method stub
            System.out.println(PhoneName+"Tap on the screen to turn on...");
        }
}

class SamsungPhone extends MobilePhone implements additional{
    SamsungPhone(String name) {
        super(name);
        //TODO Auto-generated constructor stub
    }

    @Override
    void displayCamera() {
        // TODO Auto-generated method stub
        System.out.println(PhoneName+"Display is On....");
    }

    @Override
    void displayTouchscreen() {
        // TODO Auto-generated method stub
        System.out.println(PhoneName+"Tap on the screen to turn on...");
    }

    @Override
    public void fingerPrint() {
        // TODO Auto-generated method stub
        System.out.println("Taking finger print....");
    }
}

class NokiaPhone extends MobilePhone {

    NokiaPhone(String name) {
        super(name);
        
    }

    @Override
    void displayCamera() {
        
        System.out.println(PhoneName+"Display is On....");
        
    }

    @Override
    void displayTouchscreen() {
        
        System.out.println(PhoneName+"Tap on the screen to turn on...");
        
    }}

    class Main{
        public static void main(String[] args) {
            RedmiPhone ph1 = new RedmiPhone("Redmi");
        
            ph1.displayCamera();
            ph1.displayTouchscreen();
            ph1.fingerPrint();
            ph1.voiceCall();

            SamsungPhone ph2 = new SamsungPhone("Samsung");
            ph2.displayCamera();
            ph2.displayTouchscreen();
            ph2.fingerPrint();
            ph2.voiceCall();

            NokiaPhone ph3 = new NokiaPhone("Nokia");
            ph3.displayCamera();
            ph3.displayTouchscreen();
            ph3.voiceCall();
        }
    }

