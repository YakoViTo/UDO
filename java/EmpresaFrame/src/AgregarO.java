import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class AgregarO 
{
	public static void createFrame(Empresa e, JButton bRe, JButton bMos, JFrame aux)
	{
		JLabel lNombre, lApellido, lNCI, lSueldo, lHoras;
		lNombre = new JLabel("Ingrese nombre: ");
		lApellido = new JLabel("Ingrese apellido: ");
		lNCI = new JLabel("Ingrese cedula: ");
		lSueldo = new JLabel("Ingrese sueldo: ");
		lHoras = new JLabel("¿Trabajo horas extras?");
		
		JTextField tNombre, tApellido, tNCI, tSueldo;
		tNombre = new JTextField(10);
		tApellido = new JTextField(10);
		tNCI = new JTextField(10);
		tSueldo = new JTextField(8);
		
		JRadioButton rbSi, rbNo;
		rbSi = new JRadioButton("Sí");
		rbNo = new JRadioButton("No");
		
		JButton bAceptar, bCancelar, bLimpiar;
		bAceptar = new JButton("Aceptar");
		bCancelar = new JButton("Cancelar");
		bLimpiar = new JButton("Limpiar");
		
		ButtonGroup bg = new ButtonGroup();
		
		JFrame frame = new JFrame("Agregar obrero");
		
		EventQueue.invokeLater(new Runnable()
		{
			public void run()
			{
				frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
				
				frame.setLayout(new FlowLayout());
				frame.setLocationRelativeTo(null);
				frame.setSize(380, 585);
				
				//lNombre.setBounds(5, 10, 120, 30); tNombre.setBounds(110, 10, 100, 30);
				//lApellido.setBounds(5, 70, 120, 30); tApellido.setBounds(110, 70, 100, 30);
				//lNCI.setBounds(5, 130, 120, 30); tNCI.setBounds(110, 130, 100, 30);
				//lSueldo.setBounds(5, 190, 120, 30); tSueldo.setBounds(110, 190, 100, 30);
				//lHoras.setBounds(5, 250, 140, 30); rbSi.setBounds(5, 310, 100, 30); rbNo.setBounds(5, 370, 100, 30);
				//bAceptar.setBounds(25, 475, 100, 30);
				//bCancelar.setBounds(130, 475, 100, 30);
				//bLimpiar.setBounds(235, 475, 100, 30);
				
				bg.add(rbSi);
				bg.add(rbNo);
				
				frame.add(lNombre); frame.add(tNombre);
				frame.add(lApellido); frame.add(tApellido);
				frame.add(lNCI); frame.add(tNCI);
				frame.add(lSueldo); frame.add(tSueldo);
				frame.add(lHoras); frame.add(rbSi); frame.add(rbNo);
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
					Empleado em;
					int su = 0;
					String n, a, nci, s;
					n = a = nci = s = "";
					boolean comp = false;
					n = tNombre.getText();
					a = tApellido.getText();
					nci = tNCI.getText();
					s = tSueldo.getText();
					
					if (!n.isEmpty() && !a.isEmpty() && !nci.isEmpty() && !s.isEmpty() && (rbSi.isSelected() || rbNo.isSelected()))
					{
						try
						{
							su = Integer.parseInt(s);
						}
						
						catch (Exception dk)
						{
							JOptionPane.showMessageDialog(frame, "Ha ocurrido un error");
						}
						
						if (rbSi.isSelected())
							comp = true;
						
						else
							comp = false;
						
						em = new Obrero(n, a, nci, su, comp);
						JOptionPane.showMessageDialog(frame, e.Agregar(em));
						bRe.setEnabled(true);
						bMos.setEnabled(true);
						aux.dispatchEvent(new WindowEvent (frame, WindowEvent.WINDOW_CLOSING));
						frame.dispatchEvent(new WindowEvent (frame, WindowEvent.WINDOW_CLOSING));
					}
					
					else
					{
						JOptionPane.showMessageDialog(frame, "Ingrese todos los datos primero");
						tNombre.setText("");
						tApellido.setText("");
						tNCI.setText("");
						tSueldo.setText("");
						bg.clearSelection();
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
					tNCI.setText("");
					tSueldo.setText("");
					bg.clearSelection();
				}
			}
		});
	}
}