import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class AgregarVentana 
{
	public static void createFrame(Arreglo x, JButton bAg, JButton bMos)
	{	
		JFrame frame = new JFrame("Agregar figura");
		
		JLabel lTitulo = new JLabel("¿Que desea agregar?");
		
		JRadioButton rbRectangulo, rbTriangulo, rbCirculo, rbCuadrado;
		rbRectangulo = new JRadioButton("Rectangulo");
		rbTriangulo = new JRadioButton("Triangulo");
		rbCirculo = new JRadioButton("Circulo");
		rbCuadrado = new JRadioButton("Cuadrado");
		
		EventQueue.invokeLater(new Runnable()
		{
			public void run()
			{
				frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
				
				ButtonGroup bg = new ButtonGroup();
				
				frame.setLayout(null);
				frame.setLocationRelativeTo(null);
				frame.setSize(350, 250);
				
				lTitulo.setBounds(100, 1, 150, 40);
				rbRectangulo.setBounds(25, 50, 100, 30);
				rbTriangulo.setBounds(200, 50, 100, 30);
				rbCirculo.setBounds(25, 100, 100, 30);
				rbCuadrado.setBounds(200, 100, 100, 30);
				
				bg.add(rbRectangulo);
				bg.add(rbTriangulo);
				bg.add(rbCirculo);
				bg.add(rbCuadrado);
				
				frame.add(lTitulo);
				frame.add(rbRectangulo);
				frame.add(rbTriangulo);
				frame.add(rbCirculo);
				frame.add(rbCuadrado);
				
				rbRectangulo.addActionListener(new Rec());
				rbTriangulo.addActionListener(new Tri());
				rbCirculo.addActionListener(new Cir());
				rbCuadrado.addActionListener(new Cua());
				
				frame.setVisible(true);
			}
			
			class Rec implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					AgregarRec.createFrame(x, bAg, bMos, frame);
				}
			}
			
			class Tri implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					AgregarTri.createFrame(x, bAg, bMos, frame);
				}
			}
			
			class Cir implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					AgregarCir.createFrame(x, bAg, bMos, frame);
				}
			}
			
			class Cua implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					AgregarCua.createFrame(x, bAg, bMos, frame);
				}
			}
		});
	}
}