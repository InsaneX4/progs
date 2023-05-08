
import java.awt.*;
import java.applet.*;
/*<applet code="Q5.class" width="300" height="200">
	<param name="rollNumber" value="123">
	<param name="name" value="John Doe">
	<param name="cgpa" value="3.75">
</applet>*/

public class Q5 extends Applet {
    private String rollNumber, name;
    private double cgpa;
    
    public void init() {
        rollNumber = getParameter("rollNumber");
        name = getParameter("name");
        cgpa = Double.parseDouble(getParameter("cgpa"));
    }
    
    public void paint(Graphics g) {
        Font rollFont = new Font("Serif", Font.BOLD, 18);
        Font nameFont = new Font("SansSerif", Font.ITALIC, 24);
        Font cgpaFont = new Font("Monospaced", Font.PLAIN, 20);
        
        Color rollColor = new Color(255, 0, 0); // Red
        Color nameColor = new Color(0, 128, 0); // Green
        Color cgpaColor = new Color(0, 0, 255); // Blue
        
        g.setFont(rollFont);
        g.setColor(rollColor);
        g.drawString("Roll Number: " + rollNumber, 50, 50);
        
        g.setFont(nameFont);
        g.setColor(nameColor);
        g.drawString("Name: " + name, 50, 100);
        
        g.setFont(cgpaFont);
        g.setColor(cgpaColor);
        g.drawString("CGPA: " + cgpa, 50, 150);
    }
}


