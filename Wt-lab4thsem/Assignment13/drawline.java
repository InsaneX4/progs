import java.applet.Applet;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
/*<applet code="drawline.class" height="500" width="500"></applet> */


public class drawline extends Applet {
    private TextField nameField, emailField;
    private TextArea messageArea;
    private Button submitButton;

    public void init() {
        // Create form components
        nameField = new TextField(20);
        emailField = new TextField(20);
        messageArea = new TextArea(5, 20);
        submitButton = new Button("Submit");

        // Add form components to the applet
        add(new Label("Name: "));
        add(nameField);
        add(new Label("Email: "));
        add(emailField);
        add(new Label("Message: "));
        add(messageArea);
        add(submitButton);
    }

    public void paint(Graphics g) {
        // Set the font and color for the heading
        g.setFont(new Font("Arial", Font.BOLD, 18));
        g.setColor(Color.blue);

        // Draw the heading
        g.drawString("Contact Form", 10, 30);
    }
}
