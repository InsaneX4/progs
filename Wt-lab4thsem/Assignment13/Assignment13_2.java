import java.applet.*;
import java.awt.*;

public class Assignment13_2 extends Applet
{
	public void paint (Graphics g)
	{
		g.setColor(Color.red);
		
        g.fillOval(100, 100, 400, 400);
        g.setColor(Color.yellow);
        g.fillOval(200, 200, 50, 50);
        g.fillOval(350, 200, 50, 50);


        g.drawArc(175, 200, 250, 250, 180, 180);
        
        g.drawArc(175, 250, 250, 150, 180, 180);
	}
}
