import java.applet.Applet;
import java.awt.Button;
import java.awt.Label;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
/*Write a java applet program that simulates a traffic light. The program lets the user to
click one of three light buttons: Red, Yellow, or Green. On clicking a button, an
appropriate message "Stop" or "Ready" or "Go" should appear in the space below
the buttons in the selected color. Initially there is no message shown on the display area.
Also, suitable message should be displayed on the the status bar, too.*/

/* <applet code="question2" width=500 height=600></applet> */
public class question2 extends Applet implements ActionListener{
    Label l;
    Button r;
    Button gr;
    Button y;
   public void init(){
    l=new Label("");  
    add(l);
    r=new Button("red");
    r.addActionListener(this);
    gr = new Button("green");
    gr.addActionListener(this);
    y = new Button("yellow");
    y.addActionListener(this);
    add(r);
    add(y);
    add(gr);
    }
    
    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource()==r){
            l.setText("Stop");
            showStatus("Chnageed to Red");
            
        }else if(e.getSource()==y){
            l.setText("Ready");
            showStatus("Chnageed to Green");
        }else if(e.getSource()==gr){
            l.setText("Go");
            showStatus("Chnageed to Yellow");
        }
        
        
    }
    
}
