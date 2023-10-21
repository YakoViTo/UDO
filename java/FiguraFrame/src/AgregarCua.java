import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class AgregarCua 
{
	public static void createFrame(Arreglo k, JButton bAg, JButton bMos, JFrame aux)
	{
		JLabel lLado = new JLabel("Ingrese lado: ");
		
		JTextField tLado = new JTextField(3);
		
		JButton bAceptar, bCancelar;
		bAceptar = new JButton("Aceptar");
		bCancelar = new JButton("Cancelar");
		
		JFrame frame = new JFrame("Ingrese valores");
		
		EventQueue.invokeLater(new Runnable()
		{
			public void run()
			{
				frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
				
				frame.setLayout(null);
				frame.setLocationRelativeTo(null);
				frame.setSize(300, 200);
				
				lLado.setBounds(5, 5, 100, 30);
				tLado.setBounds(100, 5, 100, 30);
				bAceptar.setBounds(10, 100, 100, 30);
				bCancelar.setBounds(150, 100, 100, 30);
				
				frame.add(lLado); frame.add(tLado);
				frame.add(bAceptar);
				frame.add(bCancelar);
				
				bAceptar.addActionListener(new AceptarBoton());
				bCancelar.addActionListener(new CancelarBoton());
				
				frame.setVisible(true);
			}
			
			class AceptarBoton implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					Figura f;
					String Met = tLado.getText();
					int l = 0;
					if (!Met.isEmpty())
					{
						try
						{
							l = Integer.parseInt(tLado.getText());
						}
						
						catch (Exception e)
						{
							JOptionPane.showMessageDialog(frame, "Ha ocurrido un error con los datos");
						}
						
						f = new Cuadrado(l);
						bAg.setEnabled(true);
						bMos.setEnabled(true);
						JOptionPane.showMessageDialog(frame, k.Agregar(f));
						aux.dispatchEvent(new WindowEvent (frame, WindowEvent.WINDOW_CLOSING)); //Aquí es donde se cierra la ventana "AgregarVentana", que la llevo mandando desde el principio.
						frame.dispatchEvent(new WindowEvent (frame, WindowEvent.WINDOW_CLOSING)); //Este es para que se cierre esta ventana.
					}
					
					else
						JOptionPane.showMessageDialog(frame, "Debe haber al menos un valor");
				}
			}
			
			class CancelarBoton implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					frame.dispatchEvent(new WindowEvent (frame, WindowEvent.WINDOW_CLOSING));
				}
			}
		});
	}
}