package factory;

import commontools.*;
import commontools.cameratools.camera;
import commontools.musictools.MusicPlayer;


class SmartPhone extends BasicPhone implements camera,MusicPlayer{

    String modelname;

    SmartPhone(int phone_id, String phone_name, String phone_type,String modelname) {
		super(phone_id, phone_name, phone_type);
		this.modelname = modelname;
	}

	@Override
    public void play(String song_name) { 
        System.out.println(
            phone_name +" "+ modelname + " is playing " + song_name +"....."
        );
        
    }

    @Override
    public void pause() {
        System.out.println(
            phone_name+" " + modelname + " is paused");
        
    }

    @Override
    public void takePicture() {
        System.out.println(
            phone_name+" " + modelname + " is taking picture");
        
    }
    
    }
    


public class assignment10_2{
    public static void main(String[] args){
        SmartPhone smartphone1 = new SmartPhone(1, "Samsung", "Smartphone", "Galaxy S2");
        SmartPhone smartphone2 = new SmartPhone(2, "Apple", "Smartphone", "iPhone 6");

        smartphone1.play("Bhiigen Hooth tere");
        smartphone1.pause();
        smartphone1.takePicture();

        smartphone2.play("Perfect");
        smartphone2.pause();
        smartphone2.takePicture();
        
    }
}