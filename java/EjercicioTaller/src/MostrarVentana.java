import java.awt.*;
import javax.swing.*;

public class MostrarVentana extends Container
{
	public static void createFrame(Arreglo x, int c)
	{
		JFrame frame = new JFrame("Ventana");
		
		EventQueue.invokeLater(new Runnable()
		{
			public void run()
			{
				frame.setLocationRelativeTo(null);
				frame.setSize(1000, 1000);
				frame.setLocationRelativeTo(null);
				frame.add(new Panel(x, c));
				frame.setVisible(true);
			}
		});
	}
}

class Panel extends JPanel
{
	private Figura f[];
	private int Cant;
	
	public Panel(Arreglo aux, int can)
	{
		f = aux.getAr();
		Cant = can;
	}
	
	public void paint(Graphics g)
	{
		super.paint(g);
		g.setColor(Color.BLACK);
		for (int i = 0; i < Cant; i++)
		{
			if (f[i].getTipo().equalsIgnoreCase("Linea"))
			{
				g.drawLine(f[i].getX(), f[i].getY(), f[i].getAncho(), f[i].getAlto());
			}
			
			else if (f[i].getTipo().equalsIgnoreCase("Rectangulo"))
			{
				g.drawRect(f[i].getX(), f[i].getY(), f[i].getAncho(), f[i].getAlto());
			}
			
			else
			{
				g.drawOval(f[i].getX(), f[i].getY(), f[i].getAncho(), f[i].getAlto());
			}
		}
	}
}