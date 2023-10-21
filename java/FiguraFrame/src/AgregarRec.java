import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class AgregarRec 
{
	public static void createFrame(Arreglo k, JButton bAg, JButton bMos, JFrame aux)
	{	
		JLabel lBase, lAltura;
		lBase = new JLabel("Ingrese base: ");
		lAltura = new JLabel("Ingrese altura: ");
		
		JTextField tBase, tAltura;
		tBase = new JTextField(3);
		tAltura = new JTextField(3);
		
		JFrame frame = new JFrame("Ingrese valores");
		
		JButton bAceptar, bCancelar;
		bAceptar = new JButton("Aceptar");
		bCancelar = new JButton("Cancelar");
		
		EventQueue.invokeLater(new Runnable()
		{	
			public void run()
			{	
				frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
				
				frame.setLayout(null);
				frame.setLocationRelativeTo(null);
				frame.setSize(350, 200);
				
				lBase.setBounds(5, 5, 100, 30); tBase.setBounds(100, 5, 100, 30);
				lAltura.setBounds(5, 55, 100, 30); tAltura.setBounds(100, 55, 100, 30);
				bAceptar.setBounds(25, 100, 100, 30);
				bCancelar.setBounds(200, 100, 100, 30);
				
				frame.add(lBase); frame.add(tBase);
				frame.add(lAltura); frame.add(tAltura);
				frame.add(bAceptar);
				frame.add(bCancelar);
				
				bAceptar.addActionListener(new Accept());
				bCancelar.addActionListener(new Cancel());
				
				frame.setVisible(true);
			}
			
			class Cancel implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					frame.dispatchEvent(new WindowEvent(frame, WindowEvent.WINDOW_CLOSING));
				}
			}
			
			class Accept implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					Figura f;
					int b, a;
					b = a = 0;
					String Met1, Met2;
					Met1 = tBase.getText();
					Met2 = tAltura.getText();
					if (!Met1.isEmpty() && !Met2.isEmpty()) //Este metodo es para que compruebe si los JTextField estan vacios o no.
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
						
						f = new Rectangulo(b, a);
						bAg.setEnabled(true);
						bMos.setEnabled(true);
						JOptionPane.showMessageDialog(frame, k.Agregar(f));
						aux.dispatchEvent(new WindowEvent (frame, WindowEvent.WINDOW_CLOSING));
						frame.dispatchEvent(new WindowEvent (frame, WindowEvent.WINDOW_CLOSING));
					}
					
					else
					{
						tBase.setText("");									//Esto para que si al menos uno está vacio, entonces los limpia.
						tAltura.setText("");
						JOptionPane.showMessageDialog(frame, "Ingrese valores primero");
					}
				}
			}
		});
	}
}