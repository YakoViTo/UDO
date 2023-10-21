import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Component;
import java.awt.Graphics;
import java.awt.Graphics2D;
import javax.swing.Icon;

public class CartaVol implements Icon 
{
	
	private int Altura, Ancho;
	private BasicStroke stroke;
	
	public CartaVol (int Al, int An, float Stroke) 
	{
		this.Altura = Al;
		this.Ancho = An;
		this.stroke = new BasicStroke(Stroke);
	}
	
	@Override
	public void paintIcon(Component c, Graphics g, int x, int y) 
	{
		Graphics2D g2d = (Graphics2D) g.create();

		g2d.setColor(Color.GREEN);

		g2d.setStroke(stroke);
		g2d.drawOval(x + 5, y + 5, Ancho - 10, Altura - 10);

		g2d.dispose();
	}
	
	@Override
	public int getIconHeight() 
	{
		return Altura;
	}

	@Override
	public int getIconWidth() 
	{
		return Ancho;
	}

}