import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class AgregarS 
{
	public static void createFrame(Empresa e, JButton bRe, JButton bMos, JFrame aux)
	{
		JLabel lNombre, lApellido, lNCI, lSueldo, lHoras, lComp;
		lNombre = new JLabel("Ingrese nombre: ");
		lApellido = new JLabel("Ingrese apellido: ");
		lNCI = new JLabel("Ingrese cedula: ");
		lSueldo = new JLabel("Ingrese sueldo: ");
		lHoras = new JLabel("¿Trabajo horas extras?");
		lComp = new JLabel("¿Trabajo las horas completas?");
		
		JTextField tNombre, tApellido, tNCI, tSueldo;
		tNombre = new JTextField(10);
		tApellido = new JTextField(10);
		tNCI = new JTextField(10);
		tSueldo = new JTextField(8);
		
		JRadioButton rbSi, rbNo, rbSi2, rbNo2;
		rbSi = new JRadioButton("Sí");
		rbNo = new JRadioButton("No");
		rbSi2 = new JRadioButton("Sí");
		rbNo2 = new JRadioButton("No");
		
		JButton bAceptar, bCancelar, bLimpiar;
		bAceptar = new JButton("Aceptar");
		bCancelar = new JButton("Cancelar");
		bLimpiar = new JButton("Limpiar");
		
		ButtonGroup bg, bg2;
		bg = new ButtonGroup();
		bg2 = new ButtonGroup();
		
		JFrame frame = new JFrame("Agregar supervisor");
		
		EventQueue.invokeLater(new Runnable()
		{
			public void run()
			{
				frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
				
				frame.setLayout(new FlowLayout());
				frame.setLocationRelativeTo(null);
				frame.setSize(380, 750);
				
				//lNombre.setBounds(5, 10, 120, 30); tNombre.setBounds(110, 10, 100, 30);
				//lApellido.setBounds(5, 70, 120, 30); tApellido.setBounds(110, 70, 100, 30);
				//lNCI.setBounds(5, 130, 120, 30); tNCI.setBounds(110, 130, 100, 30);
				//lSueldo.setBounds(5, 190, 120, 30); tSueldo.setBounds(110, 190, 100, 30);
				//lHoras.setBounds(5, 250, 160, 30); rbSi.setBounds(5, 310, 100, 30); rbNo.setBounds(5, 370, 100, 30);
				//lComp.setBounds(5, 430, 180, 30); rbSi2.setBounds(5, 490, 100, 30); rbNo2.setBounds(5, 550, 100, 30);
				//bAceptar.setBounds(25, 655, 100, 30);
				//bCancelar.setBounds(130, 655, 100, 30);
				//bLimpiar.setBounds(235, 655, 100, 30);
				
				bg.add(rbSi);
				bg.add(rbNo);
				
				bg2.add(rbSi2);
				bg2.add(rbNo2);
				
				frame.add(lNombre); frame.add(tNombre);
				frame.add(lApellido); frame.add(tApellido);
				frame.add(lNCI); frame.add(tNCI);
				frame.add(lSueldo); frame.add(tSueldo);
				frame.add(lHoras); frame.add(rbSi); frame.add(rbNo);
				frame.add(lComp); frame.add(rbSi2); frame.add(rbNo2);
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
					boolean comp, compti;
					comp = compti = false;
					n = tNombre.getText();
					a = tApellido.getText();
					nci = tNCI.getText();
					s = tSueldo.getText();
					
					if (!n.isEmpty() && !a.isEmpty() && !nci.isEmpty() && !s.isEmpty() && (rbSi.isSelected() || rbNo.isSelected()) && (rbSi2.isSelected() || rbNo2.isSelected()))
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
						
						if (rbSi2.isSelected())
							compti = true;
						
						else
							compti = false;
						
						em = new Supervisor(n, a, nci, su, comp, compti);
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
						bg2.clearSelection();
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
					bg2.clearSelection();
				}
			}
		});
	}
}