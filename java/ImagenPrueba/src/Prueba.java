import java.awt.*;
import javax.swing.*;

public class Prueba 
{
	JFrame frame = new JFrame ("");
	
	private void Test()
	{
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JButton Boton = new JButton("");
		Boton.setIcon(new ImageIcon("SoulEater.jpg"));
		
		frame.add(Boton);
		
		frame.setSize(500, 250);
		
		frame.setLayout(null);
		
		frame.setVisible(true);
	}
	
	public static void main(String [] args)
	{
		Prueba p = new Prueba();
		javax.swing.SwingUtilities.invokeLater(new Runnable()
		{
			public void run()
			{
				p.Test();
			}
		});
	}
}