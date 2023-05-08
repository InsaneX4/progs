import java.awt.*;
import java.applet.*;
/*<applet code="CircleApplet.class" width="1000" height="1000">
  Your browser does not support Java applets.
   <param name="java_arguments" value="-Djnlp.packEnabled=true" />
  <param name="separate_jvm" value="true" />
</applet>
 */

public class CircleApplet extends Applet {
   int width;
   int height;
   public void init(){
      width = Integer.parseInt(getParameter("width"));
      height = Integer.parseInt(getParameter("height")); 
   }

    public void paint(Graphics g) {
       width = getWidth();
      height = getHeight();

      // Display the width and height on the screen
      g.drawString("Width: " + width, 10, 20);
      g.drawString("Height: " + height, 10, 40);

        // Set the diameter of the circle to 100 pixels
        int diameter = 100;
        // Calculate the top-left corner of the bounding box for the circle
      
        int x = (getWidth() - diameter) / 2;
        int y = (getHeight() - diameter) / 2;

        // Draw the circle with a black outline
        g.drawOval(x, y, diameter, diameter);

        // Divide the circle into four quarters and fill each quarter with a different color
        g.setColor(Color.RED);
        g.fillArc(x, y, diameter, diameter, 0, 90);
        g.setColor(Color.GREEN);
        g.fillArc(x, y, diameter, diameter, 90, 90);
        g.setColor(Color.BLUE);
        g.fillArc(x, y, diameter, diameter, 180, 90);
        g.setColor(Color.YELLOW);
        g.fillArc(x, y, diameter, diameter, 270, 90);
    }
}

