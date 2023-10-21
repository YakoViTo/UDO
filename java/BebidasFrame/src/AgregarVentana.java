import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class AgregarVentana 
{
	public static JLabel lTitulo;
	public static JFrame frame;
	
	public static void createFrame(Tienda t, JButton bVen, JButton bMos, JButton bMon, boolean sw)
	{
		JRadioButton rbNoAl, rbAl;
		rbNoAl = new JRadioButton("No alcoholica");
		rbAl = new JRadioButton("Alcoholica");
		
		EventQueue.invokeLater(new Runnable()
		{
			public void run()
			{
				if (sw)
				{
					lTitulo = new JLabel("Que desea comprar?");
					frame = new JFrame("Comprar");
				}
				
				else
				{
					lTitulo = new JLabel("Que desea vender?");
					frame = new JFrame("Vender");
				}
				
				frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
				
				frame.setLayout(null);
				frame.setLocationRelativeTo(null);
				frame.setSize(300, 250);
				
				lTitulo.setBounds(90, 20, 120, 30);
				rbNoAl.setBounds(30, 90, 120, 30);
				rbAl.setBounds(165, 90, 100, 30);
				
				frame.add(lTitulo);
				frame.add(rbNoAl);
				frame.add(rbAl);
				
				rbNoAl.addActionListener(new NoAl());
				rbAl.addActionListener(new Al());
				
				frame.setVisible(true);
			}
			
			class NoAl implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					CVNoAl.createFrame(t, bVen, bMos, bMon, sw, frame);
				}
			}
			
			class Al implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					CVAl.createFrame(t, bVen, bMos, bMon, sw, frame);
				}
			}
		});
	}
}