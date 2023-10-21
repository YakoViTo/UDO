import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class AgregarVentana 
{
	public static void createFrame(Agenda d, JButton bBus, JButton bEdi, JButton bEli)
	{
		JLabel lTitulo = new JLabel("Que desea agrega?");
		
		JRadioButton rbFamiliar, rbAmigo, rbNegocio;
		rbFamiliar = new JRadioButton("Familiar");
		rbAmigo = new JRadioButton("Amigo");
		rbNegocio = new JRadioButton("Negocio");
		
		JFrame frame = new JFrame("Agregar persona");
		
		EventQueue.invokeLater(new Runnable()
		{
			public void run()
			{
				frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
				
				frame.setLayout(null);
				frame.setLocationRelativeTo(null);
				frame.setSize(400, 250);
				
				lTitulo.setBounds(140, 10, 120, 30);
				rbFamiliar.setBounds(80, 70, 100, 30);
				rbAmigo.setBounds(225, 70, 100, 30);
				rbNegocio.setBounds(155, 120, 100, 30);
				
				ButtonGroup bg = new ButtonGroup();
				
				bg.add(rbFamiliar);
				bg.add(rbAmigo);
				bg.add(rbNegocio);
				
				frame.add(lTitulo);
				frame.add(rbFamiliar);
				frame.add(rbAmigo);
				frame.add(rbNegocio);
				
				rbFamiliar.addActionListener(new AgregarFamBoton());
				rbAmigo.addActionListener(new AgregarAmBoton());
				rbNegocio.addActionListener(new AgregarNegBoton());
				
				frame.setVisible(true);
			}
			
			class AgregarFamBoton implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					String n, a, dt, c, to, tc, dr, tca, fc, p;
					n = a = dt = c = to = tc = dr = tca = fc = p = "";
					Persona x = new Familiares(n, a, dt, c, to, tc, dr, tca, fc, p);
					boolean sw = true;
					AgregarFam.createFrame(d, bBus, bEdi, bEli, frame, sw, x);
				}
			}
			
			class AgregarAmBoton implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					String n, a, dt, c, to, tc, dr, tca, fc, p;
					n = a = dt = c = to = tc = dr = tca = fc = p = "";
					Persona x = new Amigos(n, a, dt, c, to, tc, dr, tca, fc, p);
					boolean sw = true;
					AgregarAm.createFrame(d, bBus, bEdi, bEli, frame, sw, x);
				}
			}
			
			class AgregarNegBoton implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					String n, a, dt, c, to, tc, dr, tca;
					n = a = dt = c = to = tc = dr = tca = "";
					Persona x = new Negocios(n, a, dt, c, to, tc, dr, tca);
					boolean sw = true;
					AgregarEm.createFrame(d, bBus, bEdi, bEli, frame, sw, x);
				}
			}
		});
	}
}