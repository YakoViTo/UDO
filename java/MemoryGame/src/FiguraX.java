import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Component;
import java.awt.Graphics;
import java.awt.Graphics2D;
import javax.swing.Icon;

public class FiguraX implements Icon 
{
	private int Ancho, Altura;
	private BasicStroke stroke;
	private Color color;
	
	public FiguraX (int Al, int An, float stroke, int r, int g, int b) 
	{	
		this.Altura = Al;
		this.Ancho = An;
		this.stroke = new BasicStroke(stroke);
		color = new Color (r, g, b);
	}

	public void paintIcon(Component c, Graphics g, int x, int y) 
	{
		Graphics2D g2d = (Graphics2D) g.create();
		
		g2d.setColor(color);
		
		g2d.setStroke(stroke);
		g2d.drawLine(x +10, y + 10, x + Ancho -10, y + Altura -10);
		g2d.drawLine(x +10, y + Altura -10, x + Ancho -10, y + 10);

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