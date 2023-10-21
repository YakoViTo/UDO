import java.awt.*;
import javax.swing.*;

public class PanelDib extends Container
{
	public static JFrame frame = new JFrame("Programa");
	public static int x1, x2, x3, x4, x5, x6;
	public static Color co;
	
	public static void createFrame(int tx1, int tx2, int tx3, int tx4, int tx5, int tx6, Color c)
	{
		EventQueue.invokeLater(new Runnable()
		{
			public void run()
			{
				frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
				frame.setSize(1000, 1000);
				frame.setLocationRelativeTo(null);
				frame.setVisible(true);
				x1 = tx1;
				x2 = tx2;
				x3 = tx3;
				x4 = tx4;
				x5 = tx5;
				x6 = tx6;
				co = c;
				frame.add(new Pane(x1, x2, x3, x4, x5, x6, co));
			}
		});
	}
	
	
}

class Pane extends JPanel
{
	private int aux1, aux2, aux3, aux4, aux5, aux6;
	private Color Co;
	
	public Pane(int a, int b, int c, int d, int e, int f, Color aux)
	{
		aux1 = a;
		aux2 = b;
		aux3 = c;
		aux4 = d;
		aux5 = e;
		aux6 = f;
		Co = aux;
	}
	
	public void paint(Graphics g)
	{
		super.paint(g);
		
		/*int X1, X2, X3, X4, X5, X6;
		X1 = 250;
		X2 = 100;
		X3 = 150;
		X4 = 406;
		X5 = 350;
		X6 = 406;*/
		
		g.setColor(Co);
		
		g.drawLine(aux1, aux2, aux3, aux4);
		g.drawLine(aux3, aux4, aux5, aux6);
		g.drawLine(aux5, aux6, aux1, aux2);
	}
}