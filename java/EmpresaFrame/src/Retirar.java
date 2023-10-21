import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Retirar 
{
	public static void createFrame(Empresa em)
	{
		JLabel lNCI = new JLabel("Ingrese cedula: ");
		
		JTextField tNCI = new JTextField(10);
		
		JButton bAceptar, bCancelar;
		bAceptar = new JButton("Aceptar");
		bCancelar = new JButton("Cancelar");
		
		JFrame frame = new JFrame("Retirar");
		
		EventQueue.invokeLater(new Runnable()
		{
			public void run()
			{
				frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
				
				frame.setLayout(new FlowLayout());
				frame.setLocationRelativeTo(null);
				frame.setSize(300, 170);
				
				//lNCI.setBounds(5, 10, 120, 30); tNCI.setBounds(110, 10, 100, 30);
				//bAceptar.setBounds(25, 70, 100, 30);
				//bCancelar.setBounds(130, 70, 100, 30);
				
				frame.add(lNCI); frame.add(tNCI);
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
					String nci = tNCI.getText();
					
					if (!nci.isEmpty())
					{
						JOptionPane.showMessageDialog(frame, em.Retirar(nci));
						frame.dispatchEvent(new WindowEvent (frame, WindowEvent.WINDOW_CLOSING));
					}
					
					else
					{
						JOptionPane.showMessageDialog(frame, "Ingrese la cedula primero");
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
		});
	}
}