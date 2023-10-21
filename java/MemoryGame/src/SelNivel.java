import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class SelNivel 
{
	public static void createFrame(String i)
	{
		JFrame frame = new JFrame ("Selección de nivel");
		
		JButton bNivel[];
		bNivel = new JButton[9];
		
		EventQueue.invokeLater(new Runnable()
		{
			public void run()
			{
				String Matriz;
				boolean sw;
				
				if (i == "Libre")
				{
					JButton Bot[];
					Bot = new JButton[1];
					int f = 0;
					int Cantidad = 0;
					do
					{
						sw = true;
						Matriz = JOptionPane.showInputDialog("Ingrese el nivel que desea (ej: 1 para nivel 1, 2 para nivel 2, etc. Mínimo 1 y máximo 8): ");
						
						if (Matriz != null)
						{
							try
							{
								Cantidad = Integer.parseInt(Matriz);
							}
							
							catch (Exception e)
							{
								JOptionPane.showMessageDialog(frame, "Ha ocurrido un error");
							}
							
							if (Cantidad < 1 || Cantidad > 8)
							{
								JOptionPane.showMessageDialog(frame, "Ingrese un tamaño que se encuentre en el rango establecido (Mínimo 1, máximo 8)", "Error", JOptionPane.ERROR_MESSAGE);
								sw = false;
							}
							
							else
								sw = true;
						}
						
					} while (sw == false);
					
					if (sw && Cantidad != 0 && Cantidad > 0 && Cantidad < 9)
						Nivel.createFrame(Cantidad + 2, i, Bot, f);
				}
				
				if (i == "Reto")
				{
					int x, y, w, h;
					x = 55;
					y = 70;
					w = 90;
					h = 30;
					
					JLabel lMenu = new JLabel ("¿Que nivel desea seleccionar?");
					
					frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
					
					for (int j = 1; j < 9; j++)
					{
						if (j == 5)
						{
							x = 100;
							y = 110;
						}
						
						if (j == 8)
						{
							x = 200;
							y = 150;
						}
						
						bNivel[j] = new JButton("Nivel " + j);
						bNivel[j].setBounds(x, y, w, h);
						frame.add(bNivel[j]);
						
						if (j == 1)
							bNivel[j].addActionListener(new Nivel1Boton());
						
						else if (j == 2)
							bNivel[j].addActionListener(new Nivel2Boton());
						
						else if (j == 3)
							bNivel[j].addActionListener(new Nivel3Boton());
						
						else if (j == 4)
							bNivel[j].addActionListener(new Nivel4Boton());
						
						else if (j == 5)
							bNivel[j].addActionListener(new Nivel5Boton());
						
						else if (j == 6)
							bNivel[j].addActionListener(new Nivel6Boton());
						
						else if (j == 7)
							bNivel[j].addActionListener(new Nivel7Boton());
						
						else
							bNivel[j].addActionListener(new Nivel8Boton());
						
						x += 100;
						
						if (j > 1)
							bNivel[j].setEnabled(false);
					}
					
					frame.setLayout(null);
					frame.setSize(500, 250);
					frame.setLocationRelativeTo(null);
					
					lMenu.setBounds(155, 15, 180, 30);
					
					frame.setVisible(true);
					
					
					
				}
			}
			class Nivel1Boton implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					int Cant = 3;
					int aux = 2;
					Nivel.createFrame(Cant, i, bNivel, aux);
				}
			}
			
			class Nivel2Boton implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					int Cant = 4;
					int aux = 3;
					Nivel.createFrame(Cant, i, bNivel, aux);
				}
			}
			
			class Nivel3Boton implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					int Cant = 5;
					int aux = 4;
					Nivel.createFrame(Cant, i, bNivel, aux);
				}
			}
			
			class Nivel4Boton implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					int Cant = 6;
					int aux = 5;
					Nivel.createFrame(Cant, i, bNivel, aux);
				}
			}
			
			class Nivel5Boton implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					int Cant = 7;
					int aux = 6;
					Nivel.createFrame(Cant, i, bNivel, aux);
				}
			}
			
			class Nivel6Boton implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					int Cant = 8;
					int aux = 7;
					Nivel.createFrame(Cant, i, bNivel, aux);
				}
			}
			
			class Nivel7Boton implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					int Cant = 9;
					int aux = 8;
					Nivel.createFrame(Cant, i, bNivel, aux);
				}
			}
			
			class Nivel8Boton implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					JButton Boton[];
					Boton = new JButton[0];
					int Cant = 10;
					int aux = 9;
					Nivel.createFrame(Cant, i, Boton, aux);
				}
			}
		});
	}
}