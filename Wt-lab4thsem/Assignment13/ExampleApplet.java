import java.applet.Applet;
import java.awt.*;
import java.awt.event.MouseEvent;

/*<applet code="ExampleApplet.class" width="400" height="300"></applet>
*/
import java.applet.Applet;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

public class ExampleApplet extends Applet implements MouseListener {
    private int x, y;

    public void init() {
        x = 50;
        y = 50;
        addMouseListener(this); // register this applet as a listener for mouse events
    }

    public void paint(Graphics g) {
        g.drawString("Hello, world!", x, y);
    }

    public void update(Graphics g) {
        Color color = new Color(20, 30, 40, 50);
        g.setColor(color);
        g.fillRect(0, 0, getWidth(), getHeight());
        g.setColor(getForeground());
        paint(g);
    }

    public void mousePressed(MouseEvent e) {
        x = e.getX();
        y = e.getY();
        repaint();
    }

    // other MouseListener methods that need to be implemented
    public void mouseClicked(MouseEvent e) {}
    public void mouseEntered(MouseEvent e) {}
    public void mouseExited(MouseEvent e) {}
    public void mouseReleased(MouseEvent e) {}
}
