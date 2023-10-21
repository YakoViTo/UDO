import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class AgregarCir 
{
	public static void createFrame(Arreglo d, JButton bAg, JButton bMos, JFrame aux) /*Le mando un objeto de tipo "Arreglo" (Qué es en donde está el arreglo de figuras) 
																					dos tipo JButton (Para que cuando se agregue una figura, se activen esos botones. Es así para que quede mas bonito pues)
																					y un JFrame, que eso va a cerrar la ventana "AgregarVentana". Es mas que todo para tener mas control con las cosas.*/
	{
		JLabel lRadio = new JLabel("Ingrese radio: ");
		
		JTextField tRadio = new JTextField(3);
		
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
				
				lRadio.setBounds(5, 5, 100, 30);
				tRadio.setBounds(100, 5, 100, 30);
				bAceptar.setBounds(10, 100, 100, 30);
				bCancelar.setBounds(150, 100, 100, 30);
				
				frame.add(lRadio); frame.add(tRadio);
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
					int r = 0;
					String Met = tRadio.getText();
					if (!Met.isEmpty())
					{
						try
						{
							r = Integer.parseInt(Met);
						}
						
						catch (Exception e)
						{
							JOptionPane.showMessageDialog(frame, "Ha ocurrido un error con los datos");
						}
						
						f = new Circulo(r);
						bAg.setEnabled(true);
						bMos.setEnabled(true);
						JOptionPane.showMessageDialog(frame, d.Agregar(f));
						aux.dispatchEvent(new WindowEvent (frame, WindowEvent.WINDOW_CLOSING));
						frame.dispatchEvent(new WindowEvent (frame, WindowEvent.WINDOW_CLOSING));
					}
					
					else
						JOptionPane.showMessageDialog(frame, "Debe haber al menos un valor");
				}
			}
			
			class CancelarBoton implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					frame.dispatchEvent(new WindowEvent(frame, WindowEvent.WINDOW_CLOSING));
				}
			}
		});
	}
}