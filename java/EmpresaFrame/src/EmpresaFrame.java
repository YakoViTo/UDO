import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class EmpresaFrame 
{
	public static Empresa e;
	
	public static int Cantidad = 0;
	
	JLabel lTitulo = new JLabel("¿Que desea hacer?");
	
	JButton bAgregar, bRetirar, bMostrar;
	
	JFrame frame = new JFrame("Empresa");
	
	public void Test()
	{
		boolean sw;
		String aux = "";
		do
		{
			aux = JOptionPane.showInputDialog(frame, "Ingrese cantidad de empleados: ");
			sw = false;
			try
			{
				Cantidad = Integer.parseInt(aux);
			}
			
			catch (Exception dk)
			{
				JOptionPane.showMessageDialog(frame, "Ha ocurrido un error");
				sw = true;
			}
			
		} while(sw);
		
		e = new Empresa(Cantidad);
		
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		bAgregar = new JButton("Agregar");
		bRetirar = new JButton("Retirar");
		bRetirar.setEnabled(false);
		bMostrar = new JButton("Mostrar");
		bMostrar.setEnabled(false);
		
		frame.setLayout(new FlowLayout());
		frame.setLocationRelativeTo(null);
		frame.setSize(360, 250);
		
		
		
		//lTitulo.setBounds(120, 10, 120, 30);
		//bAgregar.setBounds(15, 120, 100, 30);
		//bRetirar.setBounds(120, 120, 100, 30);
		//bMostrar.setBounds(225, 120, 100, 30);
		
		frame.add(lTitulo);
		frame.add(bAgregar);
		frame.add(bMostrar);
		frame.add(bRetirar);
		
		bAgregar.addActionListener(new AgregarBoton());
		bRetirar.addActionListener(new RetirarBoton());
		bMostrar.addActionListener(new MostrarBoton());
		
		frame.setVisible(true);
	}
	
	class AgregarBoton implements ActionListener
	{
		public void actionPerformed(ActionEvent ae)
		{
			if (e.getContador() < Cantidad)
				AgregarVentana.createFrame(e, bRetirar, bMostrar);
			
			else
			{
				JOptionPane.showMessageDialog(frame, "No se puede agregar mas empleados", "Exceso de empleados", JOptionPane.ERROR_MESSAGE);
				bAgregar.setEnabled(false);
			}
		}
	}
	
	class RetirarBoton implements ActionListener
	{
		public void actionPerformed(ActionEvent ar)
		{
			Retirar.createFrame(e);
		}
	}
	
	class MostrarBoton implements ActionListener
	{
		public void actionPerformed(ActionEvent ae)
		{
			JOptionPane.showMessageDialog(frame, e.Listar());
		}
	}
	
	public static void main(String [] args)
	{
		EmpresaFrame ef = new EmpresaFrame();
		javax.swing.SwingUtilities.invokeLater(new Runnable()
		{
			public void run()
			{
				ef.Test();
			}
		});
	}
}