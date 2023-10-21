import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class AgregarFam 
{
	public static void createFrame(Agenda d, JButton bBus, JButton bEdi, JButton bEli, JFrame aux, boolean sw, Persona x)
	{
		JLabel lNombre, lApellido, lDirTra, lCorreo, lTelOfi, lTelCel, lDirCasa, lTelCasa, lFechaCumple, lPar;
		lNombre = new JLabel("Nombre: ");
		lApellido = new JLabel("Apellido: ");
		lDirTra = new JLabel("Dir. de trabajo: ");
		lCorreo = new JLabel("E-mail: ");
		lTelOfi = new JLabel("Tel. de oficina: ");
		lTelCel = new JLabel("Tel. de celular: ");
		lDirCasa = new JLabel("Dir. de casa: ");
		lTelCasa = new JLabel("Tel. fijo: ");
		lFechaCumple = new JLabel("Fecha de cumple: ");
		lPar = new JLabel("Parentesco: ");
		
		JTextField tNombre, tApellido, tDirTra, tCorreo, tTelOfi, tTelCel, tDirCasa, tTelCasa, tFechaCumple, tPar;
		tNombre = new JTextField(10);
		tApellido = new JTextField(10);
		tDirTra = new JTextField(15);
		tCorreo = new JTextField(12);
		tTelOfi = new JTextField(8);
		tTelCel = new JTextField(8);
		tDirCasa = new JTextField(15);
		tTelCasa = new JTextField(8);
		tFechaCumple = new JTextField(10);
		tPar = new JTextField(10);
		
		JButton bAceptar, bCancelar, bLimpiar;
		bAceptar = new JButton("Aceptar");
		bCancelar = new JButton("Cancelar");
		bLimpiar = new JButton("Limpiar");
		
		JFrame frame = new JFrame("Familiar");
		
		EventQueue.invokeLater(new Runnable()
		{
			public void run()
			{
				frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
				
				frame.setLayout(null);
				frame.setLocationRelativeTo(null);
				frame.setSize(350, 700);
				
				lNombre.setBounds(10, 5, 100, 30); tNombre.setBounds(80, 5, 100, 30);
				lApellido.setBounds(10, 65, 100, 30); tApellido.setBounds(80, 65, 100, 30);
				lDirTra.setBounds(10, 130, 100, 30); tDirTra.setBounds(110, 130, 100, 30);
				lCorreo.setBounds(10, 190, 100, 30); tCorreo.setBounds(60, 190, 100, 30);
				lTelOfi.setBounds(10, 250, 100, 30); tTelOfi.setBounds(110, 250, 100, 30);
				lTelCel.setBounds(10, 310, 100, 30); tTelCel.setBounds(110, 310, 100, 30);
				lDirCasa.setBounds(10, 370, 100, 30); tDirCasa.setBounds(90, 370, 100, 30);
				lTelCasa.setBounds(10, 430, 100, 30); tTelCasa.setBounds(80, 430, 100, 30);
				lFechaCumple.setBounds(10, 490, 120, 30); tFechaCumple.setBounds(125, 490, 100, 30);
				lPar.setBounds(10, 550, 100, 30); tPar.setBounds(90, 550, 100, 30);
				bAceptar.setBounds(15, 600, 100, 30);
				bCancelar.setBounds(120, 600, 100, 30);
				bLimpiar.setBounds(225, 600, 100, 30);
				
				frame.add(lNombre); frame.add(tNombre);
				frame.add(lApellido); frame.add(tApellido);
				frame.add(lDirTra); frame.add(tDirTra);
				frame.add(lCorreo); frame.add(tCorreo);
				frame.add(lTelOfi); frame.add(tTelOfi);
				frame.add(lTelCel); frame.add(tTelCel);
				frame.add(lDirCasa); frame.add(tDirCasa);
				frame.add(lTelCasa); frame.add(tTelCasa);
				frame.add(lFechaCumple); frame.add(tFechaCumple);
				frame.add(lPar); frame.add(tPar);
				frame.add(bAceptar);
				frame.add(bCancelar);
				frame.add(bLimpiar);
				
				if (sw)
				{
					bAceptar.addActionListener(new AceptarBoton());
					bCancelar.addActionListener(new CancelarBoton());
					bLimpiar.addActionListener(new LimpiarBoton());
				}
				
				else
				{
					bAceptar.addActionListener(new EditarBoton());
					bCancelar.addActionListener(new CancelarBoton());
					bLimpiar.addActionListener(new LimpiarBoton());
				}
				
				frame.setVisible(true);
			}
			
			class AceptarBoton implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					Persona p;
					String n, a, dt, c, to, tc, dc, tcasa, fc, par;
					n = tNombre.getText();
					a = tApellido.getText();
					dt = tDirTra.getText();
					c = tCorreo.getText();
					to = tTelOfi.getText();
					tc = tTelCel.getText();
					dc = tDirCasa.getText();
					tcasa = tDirCasa.getText();
					fc = tFechaCumple.getText();
					par = tPar.getText();
					if (!n.isEmpty() && !a.isEmpty() && !dt.isEmpty() && !c.isEmpty() && !to.isEmpty() && !tc.isEmpty() && !dc.isEmpty() && !tcasa.isEmpty() && !fc.isEmpty() && ! par.isEmpty())
					{
						p = new Familiares(n, a, dt, c, to, tc, dc, tcasa, fc, par);
						JOptionPane.showMessageDialog(frame, d.Agregar(p));
						bBus.setEnabled(true);
						bEdi.setEnabled(true);
						bEli.setEnabled(true);
						aux.dispatchEvent(new WindowEvent (frame, WindowEvent.WINDOW_CLOSING));
						frame.dispatchEvent(new WindowEvent (frame, WindowEvent.WINDOW_CLOSING));
					}
					
					else
					{
						tNombre.setText("");
						tApellido.setText("");
						tDirTra.setText("");
						tCorreo.setText("");
						tTelOfi.setText("");
						tTelCel.setText("");
						tDirCasa.setText("");
						tTelCasa.setText("");
						tFechaCumple.setText("");
						tPar.setText("");
						JOptionPane.showMessageDialog(frame, "Ha ocurrido un error en los datos. Ingrese de nuevo");
					}
				}
			}
			
			class EditarBoton implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					String n, a;
					n = tNombre.getText();
					a = tApellido.getText();
					JOptionPane.showMessageDialog(frame, d.EditarValor(x, n, a));
				}
			}
			
			class CancelarBoton implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					frame.dispatchEvent(new WindowEvent(frame, WindowEvent.WINDOW_CLOSING));
				}
			}
			
			class LimpiarBoton implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					tNombre.setText("");
					tApellido.setText("");
					tDirTra.setText("");
					tCorreo.setText("");
					tTelOfi.setText("");
					tTelCel.setText("");
					tDirCasa.setText("");
					tTelCasa.setText("");
					tFechaCumple.setText("");
					tPar.setText("");
				}
			}
		});
	}
}