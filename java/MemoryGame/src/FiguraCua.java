import java.awt.Color;
import java.awt.Component;
import java.awt.Graphics;
import java.awt.Graphics2D;
import javax.swing.Icon;

public class FiguraCua implements Icon 
{
	
	private int width, height;
	private Color color;
	
	public FiguraCua (int h, int w, int r, int g, int b) 
	{
		height = h;
		width = w;
		color = new Color (r, g, b);
	}

	public void paintIcon(Component c, Graphics g, int x, int y) 
	{
		Graphics2D g2d = (Graphics2D) g.create();
		
		g2d.setColor(color);
		
		g2d.fillRect(x + 5, y + 5, width - 8, height - 9);
		
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