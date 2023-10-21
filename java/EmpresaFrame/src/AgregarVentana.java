import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class AgregarVentana 
{
	public static void createFrame(Empresa e, JButton bRe, JButton bMos)
	{
		JLabel lTitulo = new JLabel("¿Que desea agregar?");
		
		JRadioButton rbObrero, rbSupervisor, rbGerente;
		rbObrero = new JRadioButton("Obrero");
		rbSupervisor = new JRadioButton("Supervisor");
		rbGerente = new JRadioButton("Gerente");
		
		JFrame frame = new JFrame("Agregar");
		
		EventQueue.invokeLater(new Runnable()
		{
			public void run()
			{
				frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
				
				frame.setLayout(new FlowLayout());
				frame.setLocationRelativeTo(null);
				frame.setSize(350, 250);
				
				//lTitulo.setBounds(110, 5, 140, 30);
				//rbObrero.setBounds(50, 100, 100, 30);
				//rbSupervisor.setBounds(200, 100, 100, 30);
				//rbGerente.setBounds(125, 150, 100, 30);
				
				ButtonGroup bg = new ButtonGroup();
				
				bg.add(rbObrero);;
				bg.add(rbSupervisor);;
				bg.add(rbGerente);;
				
				frame.add(lTitulo);
				frame.add(rbObrero);
				frame.add(rbSupervisor);
				frame.add(rbGerente);
				
				rbObrero.addActionListener(new ObreroBoton());
				rbSupervisor.addActionListener(new SupervisorBoton());
				rbGerente.addActionListener(new GerenteBoton());
				
				frame.setVisible(true);
			}
			
			class ObreroBoton implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					AgregarO.createFrame(e, bRe, bMos, frame);
				}
			}
			
			class SupervisorBoton implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					AgregarS.createFrame(e, bRe, bMos, frame);
				}
			}
			
			class GerenteBoton implements ActionListener
			{
				public void actionPerformed(ActionEvent ar)
				{
					AgregarG.createFrame(e, bRe, bMos, frame);
				}
			}
		});
	}
}