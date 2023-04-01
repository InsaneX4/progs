/*  A phone can make voice call and send messages. A camera clicks and records
picture. A music player can play, pause and stop playing songs. A smarphone on the other hand
is a phone that has the features of both camera and music player. Implement a concrete class
Phone having suitable concrete methods and two interfaces Camera and MusicPlayer with
suitable abstract methods. Further implement an concrete class SmartPhone that extends Phone
and implements both Camera and MusicPlayer. Write suitable Driver class to create objects of
Phone and Smartphone classes and demonstrate runtime polymorphism thereof. */
public class assignment9_6 {
    public static void main(String[] args) {
        Phone phone = new Phone();
        phone.click();
        phone.record();
        phone.play();
        phone.pause();
        phone.stop();
        
        Phone redmi;
        redmi = new SmartPhone("Redmi");
        redmi.click();
        redmi.record();
        redmi.play();
        redmi.pause();
        redmi.stop();
        

    }
}

interface MusicPlayer{
    void play();
    void pause();
    void stop();
}
interface Camera{
    void click();
    void record();
}

class Phone implements Camera, MusicPlayer{
    @Override
    public void click() {
        System.out.println("Clicking....");
    }
    @Override
    public void record() {
        System.out.println("Recording....");
    }

    @Override
    public void play() {
        System.out.println("Playing....");
    }

    @Override
    public void pause() {
        System.out.println("Pause");
    }

    @Override
    public void stop() {
        System.out.println("Stop");
    }

}

class SmartPhone extends Phone{
     String phone;

     public SmartPhone(String phone) {
        this.phone = phone;
    }

    @Override
    public void click() {
        System.out.println(phone+" Clicking....");
    }
    @Override 
    public void record() {
        System.out.println(phone+" Recording....");
    }
    @Override
    public void play() {
        System.out.println(phone+" Playing....");
    }
    @Override
    public void pause() {
        System.out.println(phone+" Pause");
    }
    @Override
    public void stop() {
        System.out.println(phone+" Stop");
    }
    

  
}