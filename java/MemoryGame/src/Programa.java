import javax.swing.*;
import java.awt.event.*;

public class Programa 
{
	JFrame frame = new JFrame ("Juego de memoria");
	
	JButton bNuevoJ, bSalir;
	
	JLabel lMenu = new JLabel("¿Que desea hacer?");
	
	JRadioButton rbLibre, rbReto;
	
	private void Test()
	{
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		bNuevoJ = new JButton("Nuevo juego");
		bSalir = new JButton("Salir");
		
		ButtonGroup bgGrupo = new ButtonGroup();
		
		rbLibre = new JRadioButton ("Modo libre");
		rbReto = new JRadioButton ("Modo reto");
		
		bgGrupo.add(rbLibre);
		bgGrupo.add(rbReto);
		
		frame.setLayout(null);
		frame.setSize(500, 250);
		frame.setLocationRelativeTo(null);
		
		lMenu.setBounds(185, 15, 130, 30);
		bNuevoJ.setBounds(100, 70, 120, 30);
		bSalir.setBounds(270, 70, 120, 30);
		rbLibre.setBounds(380, 120, 100, 30);
		rbReto.setBounds(380, 150, 100, 30);
		
		frame.add(lMenu);
		frame.add(bNuevoJ);
		frame.add(bSalir);
		frame.add(rbLibre);
		frame.add(rbReto);
		
		frame.setVisible(true);
		
		bNuevoJ.addActionListener(new NuevoBoton());
		bSalir.addActionListener(new SalirBoton());
		rbLibre.addActionListener(null);
		rbReto.addActionListener(null);
	}
	
	class NuevoBoton implements ActionListener
	{
		public void actionPerformed(ActionEvent ae)
		{
			if (rbLibre.isSelected())
			{
				String i = "Libre";
				SelNivel.createFrame(i);
			}
			
			if (rbReto.isSelected())
			{
				String i = "Reto";
				SelNivel.createFrame(i);
			}
			
			if (!rbLibre.isSelected() && !rbReto.isSelected())
				JOptionPane.showMessageDialog(frame, "Seleccione al menos un modo de juego (Libre/Reto) para poder iniciar un nuevo juego", "Seleccione modo de juego", JOptionPane.WARNING_MESSAGE);
		}
	}
	
	class SalirBoton implements ActionListener
	{
		public void actionPerformed(ActionEvent ae)
		{
			int res = JOptionPane.showConfirmDialog(null, "¿Desea salir?", "Pop-up", JOptionPane.WARNING_MESSAGE);
			if (res == JOptionPane.YES_OPTION)
			{
				System.exit(0);
			}
		}
	}
	
	public static void main(String [] args)
	{
		Programa p = new Programa();
		javax.swing.SwingUtilities.invokeLater(new Runnable()
		{
			public void run()
			{
				p.Test();
			}
		});
	}
}