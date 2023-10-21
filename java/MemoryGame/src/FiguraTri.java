import java.awt.Color;
import java.awt.Component;
import java.awt.Graphics;
import java.awt.Graphics2D;
import javax.swing.Icon;

public class FiguraTri implements Icon 
{
	private int Ancho, Altura;
	private Color color;
	
	public FiguraTri (int Al, int An, int r, int g, int b) 
	{
		Altura = Al;
		Ancho = An;
		color = new Color (r, g, b);
	}

	public void paintIcon(Component c, Graphics g, int x, int y) 
	{
		Graphics2D g2d = (Graphics2D) g.create();
		
		int xpoints2[] = {x + 4, x + 66, x + 33};
		int ypoints2[] = {y + 58, y + 58, y + 3};
		int npoints2 = 3;
		
		g2d.setColor(color);
		
		g2d.fillPolygon(xpoints2, ypoints2, npoints2);
		
		g2d.dispose();
	}

	public int getIconWidth() 
	{
		return Ancho;
	}

	public int getIconHeight() 
	{
		return Altura;
	}
}