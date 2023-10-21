import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Editar 
{
	public static void createFrame(Agenda d)
	{
		JLabel lNombre, lApellido;
		lNombre = new JLabel("Nombre: ");
		lApellido = new JLabel("Apellido: ");
		
		JTextField tNombre, tApellido;
		tNombre = new JTextField(10);
		tApellido = new JTextField(10);
		
		JButton bAceptar, bCancelar, bLimpiar;
		bAceptar = new JButton("Aceptar");
		bCancelar = new JButton("Cancelar");
		bLimpiar = new JButton("Limpiar");
		
		JFrame frame = new JFrame("Editar");
		
		EventQueue.invokeLater(new Runnable()
		{
			public void run()
			{
				frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
				
				frame.setLayout(null);
				frame.setLocationRelativeTo(null);
				frame.setSize(400, 300);
				
				lNombre.setBounds(10, 5, 100, 30); tNombre.setBounds(80, 5, 100, 30);
				lApellido.setBounds(10, 65, 100, 30); tApellido.setBounds(80, 65, 100, 30);
				bAceptar.setBounds(15, 200, 100, 30);
				bCancelar.setBounds(120, 200, 100, 30);
				bLimpiar.setBounds(225, 200, 100, 30);
				
				frame.add(lNombre); frame.add(tNombre);
				frame.add(lApellido); frame.add(tApellido);
				frame.add(bAceptar);
				frame.add(bCancelar);
				frame.add(bLimpiar);
				
				bAceptar.addActionListener(new AceptarBoton());
				bCancelar.addActionListener(new CancelarBoton());
				bLimpiar.addActionListener(new LimpiarBoton());
				
				frame.setVisible(true);
			}
			
			class AceptarBoton implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					boolean sw = false;
					JButton b1, b2, b3;
					b1 = new JButton();
					b2 = new JButton();
					b3 = new JButton();
					Persona aux;
					String n, a;
					n = tNombre.getText();
					a = tApellido.getText();
					if (!n.isEmpty() && !a.isEmpty())
					{
						aux = d.Devolver(n, a);
						if (aux.getClass().getSimpleName().equalsIgnoreCase("Familiares"))
						{
							AgregarFam.createFrame(d, b1, b2, b3, frame, sw, aux);
						}
						
						else if (aux.getClass().getSimpleName().equalsIgnoreCase("Amigo"))
						{
							AgregarAm.createFrame(d, b1, b2, b3, frame, sw, aux);
						}
						
						else
						{
							AgregarEm.createFrame(d, b1, b2, b3, frame, sw, aux);
						}
							
					}
					
					else
					{
						tNombre.setText("");
						tApellido.setText("");
						JOptionPane.showMessageDialog(frame, "Ingrese datos");
					}
				}
			}
			
			class CancelarBoton implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					frame.dispatchEvent(new WindowEvent (frame, WindowEvent.WINDOW_CLOSING));
				}
			}
			
			class LimpiarBoton implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					tNombre.setText("");
					tApellido.setText("");
				}
			}
		});
	}
}
