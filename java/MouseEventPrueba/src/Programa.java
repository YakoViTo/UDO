import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.awt.event.MouseListener;
import java.awt.event.MouseEvent;

public class Programa 
{
	JFrame frame = new JFrame("Prueba");
	
	JButton Boton = new JButton("Boton");
	
	int Contador, Cont;
	
	private void Test()
	{
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Contador = Cont = 0;
		
		frame.getContentPane();
		frame.setLayout(new FlowLayout());
		frame.setSize(250, 250);
		
		frame.add(Boton);
		
		frame.addMouseListener(new Op());
		
		Boton.addActionListener(new Boton1());
		
		frame.setVisible(true);
	}
	
	class Boton1 implements ActionListener
	{
		public void actionPerformed(ActionEvent ae)
		{
			Contador++;
			JOptionPane.showMessageDialog(frame, "Se le ha hecho click al boton: " + Contador);
		}
	}
	
	class Op implements MouseListener
	{
		@Override
		public void mouseClicked(MouseEvent ae)
		{
			int i = ae.getClickCount();
			
			JOptionPane.showMessageDialog(frame, "Se le ha hecho click al boton: " + i++);
		}

		@Override
		public void mouseEntered(MouseEvent e) 
		{
			//
		}

		@Override
		public void mouseExited(MouseEvent e) 
		{
			//
		}

		@Override
		public void mousePressed(MouseEvent e) 
		{
			//	
		}

		@Override
		public void mouseReleased(MouseEvent e) {
			// TODO Auto-generated method stub
			
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