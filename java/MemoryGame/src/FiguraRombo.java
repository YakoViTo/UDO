import java.awt.Color;
import java.awt.Component;
import java.awt.Graphics;
import java.awt.Graphics2D;
import javax.swing.Icon;

public class FiguraRombo implements Icon 
{
	private int width, height;
	private Color color;
	
	public FiguraRombo (int h, int w, int r, int g, int b) 
	{
		height = h;
		width = w;
		color = new Color (r, g, b);
	}

	public void paintIcon(Component c, Graphics g, int x, int y) 
	{
		Graphics2D g2d = (Graphics2D) g.create();
		
		int xpoints2[] = {x + 8, x + 33, x + 59, x + 33};
		int ypoints2[] = {y + 31, y + 5, y + 31, y + 57};
		int npoints2 = 4;
		
		g2d.setColor(color);
		
		g2d.fillPolygon(xpoints2, ypoints2, npoints2);
		
		g2d.dispose();
	}

	public int getIconWidth() 
	{
		return width;
	}

	public int getIconHeight() 
	{
		return height;
	}
	
}