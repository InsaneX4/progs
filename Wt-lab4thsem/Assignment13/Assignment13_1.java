import java.applet.*;
import java.awt.*;

public class Assignment13_1 extends Applet
{
	public void paint (Graphics g)
	{
		String nm=getParameter("nm");
		String rollno = getParameter("rollno");
		String branch = getParameter("branch");
		String section = getParameter("section");
		g.setColor(Color.red);
		Font f=new Font("Calibri", Font.BOLD | Font.ITALIC,28);
		g.setFont(f);
		g.drawString("NAME IS: "+nm,70,50);
		g.drawString("Roll no: "+rollno,70,100); 
		g.drawString("Branch: "+branch,70,150); 
		g.drawString("Section: "+section,70,200); 
	}
}
