import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class AgregarTri 
{
	public static void createFrame(Arreglo d, JButton bAg, JButton bMos, JFrame aux)
	{
		JLabel lBase, lAltura;
		lBase = new JLabel("Ingrese base: ");
		lAltura = new JLabel("Ingrese altura: ");
		
		JTextField tBase, tAltura;
		tBase = new JTextField(3);
		tAltura = new JTextField(3);
		
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
				
				lBase.setBounds(5, 5, 100, 30); tBase.setBounds(100, 5, 100, 30);
				lAltura.setBounds(5, 55, 100, 30); tAltura.setBounds(100, 55, 100, 30);
				bAceptar.setBounds(25, 100, 100, 30);
				bCancelar.setBounds(160, 100, 100, 30);
				
				frame.add(lBase); frame.add(tBase);
				frame.add(lAltura); frame.add(tAltura);
				frame.add(bAceptar);
				frame.add(bCancelar);
				
				bAceptar.addActionListener(new Aceptar());
				bCancelar.addActionListener(new CancelarBoton());
				
				frame.setVisible(true);
			}
			
			class Aceptar implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					Figura f;
					int b, a;
					b = a = 0;
					String Met1, Met2;
					Met1 = tBase.getText();
					Met2 = tAltura.getText();
					if (!Met1.isEmpty() && !Met2.isEmpty())
					{
						try
						{
							b = Integer.parseInt(tBase.getText());
							a = Integer.parseInt(tAltura.getText());
						}
						
						catch (Exception e)
						{
							JOptionPane.showMessageDialog(frame, "Ha ocurrido un error con los datos");
						}
						
						f = new Triangulo(b, a);
						bAg.setEnabled(true);
						bMos.setEnabled(true);
						JOptionPane.showMessageDialog(frame, d.Agregar(f));
						aux.dispatchEvent(new WindowEvent (frame, WindowEvent.WINDOW_CLOSING));
						frame.dispatchEvent(new WindowEvent (frame, WindowEvent.WINDOW_CLOSING));
					}
					
					else
					{
						tBase.setText("");
						tAltura.setText("");
						JOptionPane.showMessageDialog(frame, "Ingrese valores primero");
					}
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