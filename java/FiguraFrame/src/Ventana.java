import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Ventana 
{	
	JLabel lTitulo = new JLabel ("¿Que desea hacer?");
	
	JButton bAgregar, bMostrar, bSalir;
	
	JFrame frame = new JFrame("Ventana principal");
	
	//public static int Cantidad;
	
	public void Test()
	{
		/*boolean sw;						//Queria hacer un método para que el usuario ingresara la cantidad de figuras, pero me estaba lanzado error, entonces lo deje así ._.
		do
		{
			sw = false;
			String x = JOptionPane.showInputDialog(frame, "Ingrese cantidad de figuras: ");
			
			if (x.isEmpty())
			{
				sw = true;
				JOptionPane.showMessageDialog(frame, "Debe ingresar al menos un numero");
			}
			
			else
			{
				try
				{
					Cantidad = Integer.parseInt(x);
				}
				
				catch (Exception e)
				{
					JOptionPane.showMessageDialog(frame, "Ha ocurrido un error en los datos");
					sw = true;
				}
			}
						
		} while (sw);*/
		
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		bAgregar = new JButton ("Agregar");
		bMostrar = new JButton("Mostrar");
		bMostrar.setEnabled(false);
		bSalir = new JButton("Salir");
		
		frame.setLayout(null);
		frame.setLocationRelativeTo(null);
		frame.setSize(350, 250);
		
		lTitulo.setBounds(115, 1, 150, 40);
		bAgregar.setBounds(50, 50, 100, 30);
		bMostrar.setBounds(190, 50, 100, 30);
		bSalir.setBounds(115, 100, 100, 30);
		
		frame.add(lTitulo);
		frame.add(bAgregar);
		frame.add(bMostrar);
		frame.add(bSalir);
		
		bAgregar.addActionListener(new Agregar());
		bMostrar.addActionListener(new Mostrar());
		bSalir.addActionListener(new SalirBoton());
		
		frame.setVisible(true);
		
	}
	
	public static Arreglo a = new Arreglo(10);
	
	class Agregar implements ActionListener
	{
		public void actionPerformed(ActionEvent ae)
		{	
			if (a.getContador() < 10)
				AgregarVentana.createFrame(a, bAgregar, bMostrar);
			
			else
			{
				JOptionPane.showMessageDialog(frame, "No se puede agregar mas figuras", "Error", JOptionPane.ERROR_MESSAGE);
				bAgregar.setEnabled(false);
			}
		}
	}
	
	class Mostrar implements ActionListener
	{
		public void actionPerformed(ActionEvent ae)
		{
			JOptionPane.showMessageDialog(frame, a.Mostrar());
		}
	}
	
	class SalirBoton implements ActionListener
	{
		public void actionPerformed(ActionEvent ae)
		{
			int res = JOptionPane.showConfirmDialog(frame, "¿Desea salir?");
			if (res == JOptionPane.YES_OPTION)
			{
				System.exit(0);
			}
		}
	}
	
	public static void main(String [] args)
	{
		Ventana v = new Ventana();
		javax.swing.SwingUtilities.invokeLater(new Runnable()
		{
			public void run()
			{
				v.Test();
			}
		});
	}
}