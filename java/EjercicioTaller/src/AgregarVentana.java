import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class AgregarVentana{
	
	public static void createFrame(Arreglo x, JButton bMostrar){
		
		JLabel lTitulo, lX1, lX2, lX3, lX4;
		lTitulo = new JLabel("¿Que desea agregar?????");
		lX1 = new JLabel("");
		lX2 = new JLabel("");
		lX3 = new JLabel("");
		lX4 = new JLabel("");
		
		JTextField tX1, tX2, tX3, tX4;
		tX1 = new JTextField(3);
		tX2 = new JTextField(3);
		tX3 = new JTextField(3);
		tX4 = new JTextField(3);
		
		JRadioButton rbLinea, rbRect, rbCir;
		rbLinea = new JRadioButton("Linea");
		rbRect = new JRadioButton("Rectangulo");
		rbCir = new JRadioButton("Circulo");
		
		ButtonGroup bg = new ButtonGroup();
		
		JButton bAceptar, bLimpiar;
		bAceptar = new JButton("Aceptar");
		bLimpiar = new JButton("Limpiar");
		
		JFrame frame = new JFrame("Agregar");
		
		EventQueue.invokeLater(new Runnable(){
			
			public void run(){
				
				frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
				
				frame.setSize(690, 400);
				
				frame.setLayout(null);
				frame.setLocationRelativeTo(null);
				
				lTitulo.setBounds(5, 10, 140, 30);
				rbLinea.setBounds(5, 70, 120, 30);
				rbRect.setBounds(5, 130, 120, 30);
				rbCir.setBounds(5, 190, 120, 30);
				lX1.setBounds(450, 10, 140, 30); tX1.setBounds(555, 10, 100, 30);
				lX2.setBounds(450, 70, 140, 30); tX2.setBounds(555, 70, 100, 30);
				lX3.setBounds(450, 130, 140, 30); tX3.setBounds(555, 130, 100, 30);
				lX4.setBounds(450, 190, 140, 30); tX4.setBounds(555, 190, 100, 30);
				bAceptar.setBounds(50, 310, 100, 30);
				bLimpiar.setBounds(260, 310, 100, 30);
				lX1.setVisible(false); tX1.setVisible(false);
				lX2.setVisible(false); tX2.setVisible(false);
				lX3.setVisible(false); tX3.setVisible(false);
				lX4.setVisible(false); tX4.setVisible(false);
				bAceptar.setVisible(false);
				bLimpiar.setVisible(false);
				
				bg.add(rbLinea);
				bg.add(rbRect);
				bg.add(rbCir);
				
				frame.add(lTitulo);
				frame.add(rbLinea);
				frame.add(rbRect);
				frame.add(rbCir);
				frame.add(lX1); frame.add(tX1);
				frame.add(lX2); frame.add(tX2);
				frame.add(lX3); frame.add(tX3);
				frame.add(lX4); frame.add(tX4);
				frame.add(bAceptar);
				frame.add(bLimpiar);
				
				rbLinea.addItemListener(new Botones());
				rbRect.addItemListener(new Botones());
				rbCir.addItemListener(new Botones());
				bAceptar.addActionListener(new AceptarBoton());
				bLimpiar.addActionListener(new LimpiarBoton());
				
				frame.setVisible(true);
			}
			
			class Botones implements ItemListener
			{
				public void itemStateChanged(ItemEvent ie)
				{
					if (rbLinea.isSelected())
					{
						lX1.setText("Ingrese X1: ");
						lX2.setText("Ingrese Y1");
						lX3.setText("Ingrese X2: ");
						lX4.setText("Ingrese Y2: ");
						lX1.setVisible(true); tX1.setVisible(true);
						lX2.setVisible(true); tX2.setVisible(true);
						lX3.setVisible(true); tX3.setVisible(true);
						lX4.setVisible(true); tX4.setVisible(true);
						bAceptar.setVisible(true);
						bLimpiar.setVisible(true);
					}
					
					else if (rbRect.isSelected())
					{
						lX1.setText("Ingrese X: ");
						lX2.setText("Ingrese Y: ");
						lX3.setText("Ingrese ancho: ");
						lX4.setText("Ingrese alto: ");
						lX1.setVisible(true); tX1.setVisible(true);
						lX2.setVisible(true); tX2.setVisible(true);
						lX3.setVisible(true); tX3.setVisible(true);
						lX4.setVisible(true); tX4.setVisible(true);
						bAceptar.setVisible(true);
						bLimpiar.setVisible(true);
					}
					
					else if (rbCir.isSelected())
					{
						lX1.setText("Ingrese X: ");
						lX2.setText("Ingrese Y: ");
						lX3.setText("Ingrese ancho: ");
						lX4.setText("Ingrese alto: ");
						lX1.setVisible(true); tX1.setVisible(true);
						lX2.setVisible(true); tX2.setVisible(true);
						lX3.setVisible(true); tX3.setVisible(true);
						lX4.setVisible(true); tX4.setVisible(true);
						bAceptar.setVisible(true);
						bLimpiar.setVisible(true);
					}
				}
			}
			
			class AceptarBoton implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					Figura f;
					String x1, x2, x3, x4, tipo;
					x1 = tX1.getText();
					x2 = tX2.getText();
					x3 = tX3.getText();
					x4 = tX4.getText();
					tipo = "";
					int X1, X2, X3, X4;
					X1 = X2 = X3 = X4 = 0;
					
					if (!x1.isEmpty() && !x2.isEmpty() && !x3.isEmpty() && !x4.isEmpty())
					{
						try
						{
							X1 = Integer.parseInt(x1);
							X2 = Integer.parseInt(x2);
							X3 = Integer.parseInt(x3);
							X4 = Integer.parseInt(x4);
						}
						
						catch (Exception e)
						{
							JOptionPane.showMessageDialog(frame, "Ha ocurrido un error");
						}
						
						if (rbLinea.isSelected())
							tipo = "Linea";
						
						else if (rbRect.isSelected())
							tipo = "Rectangulo";
						
						else if (rbCir.isSelected())
							tipo = "Circulo";
						
						f = new Figura(X1, X2, X3, X4, tipo);
						JOptionPane.showMessageDialog(frame, x.Agregar(f));
						lX1.setVisible(false); tX1.setVisible(false);
						lX2.setVisible(false); tX2.setVisible(false);
						lX3.setVisible(false); tX3.setVisible(false);
						lX4.setVisible(false); tX4.setVisible(false);
						bAceptar.setVisible(false);
						bLimpiar.setVisible(false);
						tX1.setText("");
						tX2.setText("");
						tX3.setText("");
						tX4.setText("");
						bg.clearSelection();
						bMostrar.setEnabled(true);
						frame.dispatchEvent(new WindowEvent(frame, WindowEvent.WINDOW_CLOSING));
					}
					
					else
						JOptionPane.showMessageDialog(frame, "Debe ingresar todos los valores");
				}
			}
			
			class LimpiarBoton implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					tX1.setText("");
					tX2.setText("");
					tX3.setText("");
					tX4.setText("");
				}
			}
		});
		
	}
}