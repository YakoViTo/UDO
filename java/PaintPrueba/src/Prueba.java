import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.awt.Dimension;
import javax.swing.BorderFactory;
import javax.swing.JPanel;
import java.awt.Graphics;

public class Prueba extends Container
{
	Color d;

	JLabel lX1, lY1, lX2, lY2, lX3, lY3;

	JTextField tX1, tY1, tX2, tY2, tX3, tY3;

	JRadioButton rbRojo, rbVerde, rbAzul;

	JButton bAceptar, bLimpiar;
	
	ButtonGroup bg = new ButtonGroup();

	public static JFrame frame = new JFrame("Programa");

	public void Test()
	{
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setLayout(null);
		frame.setLocationRelativeTo(null);
		frame.setSize(650, 500);
		
		bLimpiar = new JButton("Limpiar");
		bAceptar = new JButton("Aceptar");
		lX1 = new JLabel("X1: ");
		lY1 = new JLabel("Y1: ");
		lX2 = new JLabel("X2: ");
		lY2 = new JLabel("Y2: ");
		lX3 = new JLabel("X3: ");
		lY3 = new JLabel("Y3: ");

		tX1 = new JTextField("");
		tY1 = new JTextField("");
		tX2 = new JTextField("");
		tY2 = new JTextField("");
		tX3 = new JTextField("");
		tY3 = new JTextField("");

		rbRojo = new JRadioButton("Rojo");
		rbVerde = new JRadioButton("Verde");
		rbAzul = new JRadioButton("Azul");

		lX1.setBounds(5, 10, 50, 30); tX1.setBounds(30, 10, 50, 30);
		lY1.setBounds(90, 10, 50, 30); tY1.setBounds(115, 10, 50, 30);
		lX2.setBounds(175, 10, 50, 30); tX2.setBounds(200, 10, 50, 30);
		lY2.setBounds(260, 10, 50, 30); tY2.setBounds(285, 10, 50, 30);
		lX3.setBounds(345, 10, 50, 30); tX3.setBounds(370, 10, 50, 30);
		lY3.setBounds(430, 10, 50, 30); tY3.setBounds(455, 10, 50, 30);
		rbRojo.setBounds(60, 65, 50, 30);
		rbVerde.setBounds(165, 65, 90, 30);
		rbAzul.setBounds(270, 65, 50, 30);
		bAceptar.setBounds(370, 65, 100, 30);
		bLimpiar.setBounds(490, 65, 100, 30);

		bg.add(rbRojo);
		bg.add(rbVerde);
		bg.add(rbAzul);
		
		frame.add(lX1); frame.add(tX1);
		frame.add(lY1); frame.add(tY1);
		frame.add(lX2); frame.add(tX2);
		frame.add(lY2); frame.add(tY2);
		frame.add(lX3); frame.add(tX3);
		frame.add(lY3); frame.add(tY3);
		frame.add(rbRojo); frame.add(rbVerde); frame.add(rbAzul);
		frame.add(bAceptar);
		frame.add(bLimpiar);

		rbRojo.addItemListener(new rbBotones());
		rbVerde.addItemListener(new rbBotones());
		rbAzul.addItemListener(new rbBotones());
		bAceptar.addActionListener(new AceptarBoton());
		bLimpiar.addActionListener(new LimpiarBoton());
		
		frame.setVisible(true);
		frame.repaint();
	}
	
	class rbBotones implements ItemListener
	{
		public void itemStateChanged(ItemEvent ie)
		{
			if (rbRojo.isSelected())
			{
				d = Color.RED;
			}

			else if (rbVerde.isSelected())
			{
				d = Color.GREEN;
			}

			else if (rbAzul.isSelected())
			{
				d = Color.BLUE;
			}
		}
	}
	
	/*public void paint(Graphics g)
	{
		super.paint(g);
		String x1, y1, x2, y2, x3, y3;
		x1 = tX1.getText();
		x2 = tX2.getText();
		x3 = tX3.getText();
		y1 = tY1.getText();
		y2 = tY2.getText();
		y3 = tY3.getText();
		
		g.setColor(d);
		int X1, Y1, X2, Y2, X3, Y3;
		X1 = Y1 = X2 = Y2 = X3 = Y3 = 0;
		
		if (!x1.isEmpty() && !y1.isEmpty() && !x2.isEmpty() && !y2.isEmpty() && !x3.isEmpty() && !y3.isEmpty() && (rbRojo.isSelected() || rbVerde.isSelected() || rbAzul.isSelected()))
		{
			
			try
			{
				X1 = Integer.parseInt(x1);
				X2 = Integer.parseInt(x2);
				X3 = Integer.parseInt(x3);
				Y1 = Integer.parseInt(y1);
				Y2 = Integer.parseInt(y2);
				Y3 = Integer.parseInt(y3);
			}
			
			catch (Exception e)
			{
				JOptionPane.showMessageDialog(frame, "Ha ocurrido un error");
			}
			
		}
		
		g.drawLine(X1, Y1, X2, Y2);
		g.drawLine(X2, Y2, X3, Y3);
		g.drawLine(X3, Y3, X1, Y1);
		
	}*/
	
	class AceptarBoton implements ActionListener
	{
		public void actionPerformed(ActionEvent ae)
		{
			String x1, y1, x2, y2, x3, y3;
			int X1, X2, X3, X4, X5, X6;
			X1 = X2 = X3 = X4 = X5 = X6 = 0;
			x1 = tX1.getText();
			y1 = tY1.getText();
			x2 = tX2.getText();
			y2 = tY2.getText();
			x3 = tX3.getText();
			y3 = tY3.getText();
			
			if (!x1.isEmpty() && !y1.isEmpty() && !x2.isEmpty() && !y2.isEmpty() && !x3.isEmpty() && !y3.isEmpty() && (rbRojo.isSelected() || rbVerde.isSelected() || rbAzul.isSelected()))
			{
				try
				{
					X1 = Integer.parseInt(x1);
					X2 = Integer.parseInt(y1);
					X3 = Integer.parseInt(x2);
					X4 = Integer.parseInt(y2);
					X5 = Integer.parseInt(x3);
					X6 = Integer.parseInt(y3);
				}
				
				catch (Exception e)
				{
					JOptionPane.showMessageDialog(frame, "Ha ocurrido un error");
				}
				PanelDib.createFrame(X1, X2, X3, X4, X5, X6, d);
			}
			
			else
				JOptionPane.showMessageDialog(frame, "Debe ingresar todos los datos");
		}
	}

	class LimpiarBoton implements ActionListener
	{
		public void actionPerformed(ActionEvent ae)
		{
			bg.clearSelection();
			tX1.setText("");
			tX2.setText("");
			tX3.setText("");
			tY1.setText("");
			tY2.setText("");
			tY3.setText("");
		}
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
