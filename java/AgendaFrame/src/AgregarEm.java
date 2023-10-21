import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class AgregarEm 
{
	public static void createFrame(Agenda d, JButton bBus, JButton bEdi, JButton bEli, JFrame aux, boolean sw, Persona x)
	{
		JLabel lNombre, lApellido, lDirTra, lCorreo, lTelOfi, lTelCel, lCargo, lEmpresa;
		lNombre = new JLabel("Nombre: ");
		lApellido = new JLabel("Apellido: ");
		lDirTra = new JLabel("Dir. de trabajo: ");
		lCorreo = new JLabel("E-mail: ");
		lTelOfi = new JLabel("Tel. de oficina: ");
		lTelCel = new JLabel("Tel. de celular: ");
		lCargo = new JLabel("Cargo: ");
		lEmpresa = new JLabel("Nombre de empresa: ");
		
		JTextField tNombre, tApellido, tDirTra, tCorreo, tTelOfi, tTelCel, tCargo, tEmpresa;
		tNombre = new JTextField(10);
		tApellido = new JTextField(10);
		tDirTra = new JTextField(15);
		tCorreo = new JTextField(12);
		tTelOfi = new JTextField(8);
		tTelCel = new JTextField(8);
		tCargo = new JTextField(8);
		tEmpresa = new JTextField(8);
		
		JButton bAceptar, bCancelar, bLimpiar;
		bAceptar = new JButton("Aceptar");
		bCancelar = new JButton("Cancelar");
		bLimpiar = new JButton("Limpiar");
		
		JFrame frame = new JFrame("Empresa");
		
		EventQueue.invokeLater(new Runnable()
		{
			public void run()
			{
				frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
				
				frame.setLayout(null);
				frame.setLocationRelativeTo(null);
				frame.setSize(350, 600);
				
				lNombre.setBounds(10, 5, 100, 30); tNombre.setBounds(80, 5, 100, 30);
				lApellido.setBounds(10, 65, 100, 30); tApellido.setBounds(80, 65, 100, 30);
				lDirTra.setBounds(10, 130, 100, 30); tDirTra.setBounds(110, 130, 100, 30);
				lCorreo.setBounds(10, 190, 100, 30); tCorreo.setBounds(60, 190, 100, 30);
				lTelOfi.setBounds(10, 250, 100, 30); tTelOfi.setBounds(110, 250, 100, 30);
				lTelCel.setBounds(10, 310, 100, 30); tTelCel.setBounds(110, 310, 100, 30);
				lCargo.setBounds(10, 370, 100, 30); tCargo.setBounds(60, 370, 100, 30);
				lEmpresa.setBounds(10, 430, 125, 30); tEmpresa.setBounds(135, 430, 100, 30);
				bAceptar.setBounds(15, 500, 100, 30);
				bCancelar.setBounds(120, 500, 100, 30);
				bLimpiar.setBounds(225, 500, 100, 30);
				
				frame.add(lNombre); frame.add(tNombre);
				frame.add(lApellido); frame.add(tApellido);
				frame.add(lDirTra); frame.add(tDirTra);
				frame.add(lCorreo); frame.add(tCorreo);
				frame.add(lTelOfi); frame.add(tTelOfi);
				frame.add(lTelCel); frame.add(tTelCel);
				frame.add(lCargo); frame.add(tCargo);
				frame.add(lEmpresa); frame.add(tEmpresa);
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
					String n, a, dt, c, to, tc, cargo, empresa;
					n = tNombre.getText();
					a = tApellido.getText();
					dt = tDirTra.getText();
					c = tCorreo.getText();
					to = tTelOfi.getText();
					tc = tTelCel.getText();
					cargo = tCargo.getText();
					empresa = tEmpresa.getText();
					if (!n.isEmpty() && !a.isEmpty() && !dt.isEmpty() && !c.isEmpty() && !to.isEmpty() && !tc.isEmpty() && !cargo.isEmpty() && !empresa.isEmpty())
					{
						p = new Negocios(n, a, dt, c, to, tc, cargo, empresa);
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
						tCargo.setText("");
						tEmpresa.setText("");
						JOptionPane.showMessageDialog(frame, "Ha ocurrido un error en los datos. Ingreselos de nuevo");
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
					tCargo.setText("");
					tEmpresa.setText("");
				}
			}
		});
	}
}