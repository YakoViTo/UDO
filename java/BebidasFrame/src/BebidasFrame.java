import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class BebidasFrame 
{
	public static Tienda ti;
	
	public static int Cantidad = 0;
	
	JLabel lTitulo = new JLabel("Que desea hacer?");
	
	JButton bComprar, bVender, bMostrar, bMonto;
	
	JFrame frame = new JFrame("Tienda");
	
	public void Test()
	{
		boolean sw;
		String x;
		
		do
		{
			sw = false;
			x = JOptionPane.showInputDialog(frame, "Ingrese cantidad de bebidas que se encuentran: ");
			
			if(!x.isEmpty())
			{
				try
				{
					Cantidad = Integer.parseInt(x);
				}
				
				catch (Exception ex)
				{
					JOptionPane.showMessageDialog(frame, "Ha ocurrido un error");
					sw = true;
				}
			}
			
			else
			{
				JOptionPane.showMessageDialog(frame, "Ingrese algun numero primero");
				sw = true;
			}
			
		} while (sw);
		
		ti = new Tienda(Cantidad);
		
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		bComprar = new JButton("Comprar");
		bVender = new JButton("Vender");
		bVender.setEnabled(false);
		bMostrar = new JButton("Mostrar");
		bMostrar.setEnabled(false);
		bMonto = new JButton("Monto total");
		bMonto.setEnabled(false);
		
		frame.setLayout(null);
		frame.setLocationRelativeTo(null);
		frame.setSize(400, 350);
		
		lTitulo.setBounds(145, 20, 120, 30);
		bComprar.setBounds(40, 150, 100, 30);
		bVender.setBounds(145, 150, 100, 30);
		bMostrar.setBounds(250, 150, 100, 30);
		bMonto.setBounds(145, 200, 100, 30);
		
		frame.add(lTitulo);
		frame.add(bComprar);
		frame.add(bVender);
		frame.add(bMostrar);
		frame.add(bMonto);
		
		bComprar.addActionListener(new ComprarBoton());
		bVender.addActionListener(new VenderBoton());
		bMostrar.addActionListener(new MostrarBoton());
		bMonto.addActionListener(new MontoBoton());
		
		frame.setVisible(true);
	}
	
	class ComprarBoton implements ActionListener
	{
		public void actionPerformed(ActionEvent ae)
		{
			boolean sw = true;
			if (ti.getContador() < Cantidad)
				AgregarVentana.createFrame(ti, bVender, bMostrar, bMonto, sw);
			
			else
			{
				JOptionPane.showMessageDialog(frame, "No se puede comprar mas bebidas.");
				bComprar.setEnabled(false);
			}
		}
	}
	
	class VenderBoton implements ActionListener
	{
		public void actionPerformed(ActionEvent ae)
		{
			boolean sw = false;
			AgregarVentana.createFrame(ti, bVender, bMostrar, bMonto, sw);
		}
	}
	
	class MostrarBoton implements ActionListener
	{
		public void actionPerformed(ActionEvent ae)
		{
			JOptionPane.showMessageDialog(frame, ti.Mostrar(), "Todas las bebidas disponibles", JOptionPane.INFORMATION_MESSAGE);
		}
	}
	
	class MontoBoton implements ActionListener
	{
		public void actionPerformed(ActionEvent ae)
		{
			JOptionPane.showMessageDialog(frame, ti.MontoGanado(), "El monto de las compras y las ventas", JOptionPane.INFORMATION_MESSAGE);
		}
	}
	
	public static void main(String [] args)
	{
		BebidasFrame bf = new BebidasFrame();
		javax.swing.SwingUtilities.invokeLater(new Runnable()
		{
			public void run()
			{
				bf.Test();
			}
		});
	}
}