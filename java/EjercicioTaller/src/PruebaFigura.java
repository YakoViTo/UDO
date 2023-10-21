import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class PruebaFigura 
{
	public static Arreglo a;
	public static int Cantidad;
	
	JLabel lTitulo = new JLabel("¿Qué desea hacer?");
	
	JButton bAgregar, bMostrar;
	
	JFrame frame = new JFrame("Programa");
	
	public void Test()
	{
		boolean sw;
		do
		{
			sw = false;
			String aux = JOptionPane.showInputDialog(frame, "Ingrese cantidad de figuras");
			
			if (!aux.isEmpty())
			{
				try
				{
					Cantidad = Integer.parseInt(aux);
				}
				
				catch (Exception e)
				{
					JOptionPane.showMessageDialog(frame, "Ha ocurrido un error");
				}
				
				a = new Arreglo(Cantidad);
			}
		} while (sw);
		
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		frame.setSize(350, 300);
		frame.setLayout(null);
		frame.setLocationRelativeTo(null);
		
		bAgregar = new JButton("Agregar");
		bMostrar = new JButton("Mostrar");
		
		lTitulo.setBounds(110, 10, 120, 30);
		bAgregar.setBounds(25, 200, 100, 30);
		bMostrar.setBounds(200, 200, 100, 30);
		bMostrar.setEnabled(false);
		
		frame.add(lTitulo);
		frame.add(bAgregar);
		frame.add(bMostrar);
		
		bAgregar.addActionListener(new AgregarBoton());
		bMostrar.addActionListener(new MostrarBoton());
		
		frame.setVisible(true);
	}
	
	class AgregarBoton implements ActionListener
	{
		public void actionPerformed(ActionEvent ae)
		{
			if (a.getContador() < Cantidad)
				AgregarVentana.createFrame(a, bMostrar);
			
			else
			{
				JOptionPane.showMessageDialog(frame, "No se puede agregar más figuras");
				bAgregar.setEnabled(true);
			}
		}
	}
	
	class MostrarBoton implements ActionListener
	{
		public void actionPerformed(ActionEvent ae)
		{
			MostrarVentana.createFrame(a, a.getContador());
		}
	}
	
	public static void main(String [] args)
	{
		PruebaFigura pf = new PruebaFigura();
		javax.swing.SwingUtilities.invokeLater(new Runnable()
		{
			public void run()
			{
				pf.Test();
			}
		});
	}
}