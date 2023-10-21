import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class AgendaFrame 
{
	public static Agenda age = new Agenda(10);
	
	JLabel lTitulo = new JLabel("Que desea hacer?");
	
	JButton bAgregar, bBuscar, bEditar, bEliminar;
	
	JFrame frame = new JFrame("Agenda");
	
	public void Test()
	{
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		bAgregar = new JButton("Agregar");
		bBuscar = new JButton("Buscar");
		bBuscar.setEnabled(false);
		bEditar = new JButton("Editar");
		bEditar.setEnabled(false);
		bEliminar = new JButton("Eliminar");
		bEliminar.setEnabled(false);
		
		frame.setLayout(null);
		frame.setLocationRelativeTo(null);
		frame.setSize(400, 250);
		
		lTitulo.setBounds(150, 10, 120, 30);
		bAgregar.setBounds(40, 70, 100, 30);
		bBuscar.setBounds(150, 70, 100, 30);
		bEditar.setBounds(260, 70, 100, 30);
		bEliminar.setBounds(150, 120, 100, 30);
		
		frame.add(lTitulo);
		frame.add(bAgregar);
		frame.add(bBuscar);
		frame.add(bEditar);
		frame.add(bEliminar);
		
		bAgregar.addActionListener(new AgregarBoton());
		bBuscar.addActionListener(new BuscarBoton());
		bEditar.addActionListener(new EditarBoton());
		bEliminar.addActionListener(new EliminarBoton());
		
		frame.setVisible(true);
	}
	
	class AgregarBoton implements ActionListener
	{
		public void actionPerformed(ActionEvent ae)
		{
			if (age.getContador() < 10)
				AgregarVentana.createFrame(age, bBuscar, bEditar, bEliminar);
			
			else
			{
				JOptionPane.showMessageDialog(frame, "No se puede agrega mas personas", "Error", JOptionPane.ERROR_MESSAGE);
				bAgregar.setEnabled(false);
			}
		}
	}
	
	class BuscarBoton implements ActionListener
	{
		public void actionPerformed(ActionEvent ae)
		{
			Buscar.createFrame(age);
		}
	}
	
	class EditarBoton implements ActionListener
	{
		public void actionPerformed(ActionEvent ae)
		{
			Editar.createFrame(age);
		}
	}
	
	class EliminarBoton implements ActionListener
	{
		public void actionPerformed(ActionEvent ae)
		{
			Eliminar.createFrame(age);
		}
	}
	
	public static void main(String [] args)
	{
		AgendaFrame af = new AgendaFrame();
		javax.swing.SwingUtilities.invokeLater(new Runnable()
		{
			public void run()
			{
				af.Test();
			}
		});
	}
}