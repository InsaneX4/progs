package commontools;
/*Problem 2: A phone can make voice call and send messages. A camera clicks and records
picture. A music player can play, pause and stop playing songs. A smarphone on the other hand
is a phone that has the features of both camera and music player. Keeping in mind the above
basic scenarios implement the following. Define a package commontools and a pair of
subpackages of it: cameratools and musictools. Define public interface Camera under
cameratools and another public interface MusicPlayer under musictools. Also define public
class BasicPhone under the package commontools. Finally, define another package factory and
implement a concrete class SmartPhone under it which extends BasicPhone class and
implements both Camera and MusicPlayer interfaces. Write suitable Driver class to create
objects of BasicPhone and Smartphone classes. */


public class BasicPhone {
    int phone_id;
    protected String phone_name;
    String phone_type;

    protected BasicPhone (int phone_id, String phone_name, String phone_type){
        this.phone_id = phone_id;
        this.phone_name = phone_name;
        this.phone_type = phone_type;
    }

}
