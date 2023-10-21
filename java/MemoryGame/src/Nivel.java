import javax.swing.*;
import java.awt.Color;
import java.awt.EventQueue;
import java.awt.event.*;
import java.util.Random;

public class Nivel 
{
	private static int aux = 0;
	private static boolean check = false;
	public static int Intentos = 0;
	private static Color GreenB = new Color(0, 159, 0);
	public static void createFrame(int x, String M, JButton[] Boton, int h)
	{	
		int Cantidad = x + 1;
		
		CartaVol CV;
		
		CV = new CartaVol (65, 65, 3f);
		
		FiguraX FX, FX1, FX2;
		FX = new FiguraX (65, 65, 3.5f, 0, 0, 159);
		FX1 = new FiguraX (65, 65, 3.5f, 0, 255, 255);
		FX2 = new FiguraX (65, 65, 3.5f, 0, 39, 0);
		
		FiguraTri FT, FT1, FT2;
		FT = new FiguraTri (65, 65, 219, 0, 0);
		FT1 = new FiguraTri (65, 65, 219, 219, 0);
		FT2 = new FiguraTri (65, 65, 10, 10, 10);
		
		FiguraCua FC, FC1, FC2;
		FC = new FiguraCua (65, 65, 110, 110, 110);
		FC1 = new FiguraCua (65, 65, 219, 0, 219);
		FC2 = new FiguraCua (65, 65, 39, 0, 0);
		
		FiguraRombo FR, FR1;
		FR = new FiguraRombo (65, 65, 255, 255, 36);
		FR1 = new FiguraRombo (65, 65, 183, 92, 0);
		
		Icon Imagen[] = {FX, FT, FC, FX1, FT1, FC1, FR, FR1, FX2, FT2, FC2};
		
		Carta c[] = new Carta[Cantidad * 2];

		JButton Botones[];
		Botones = new JButton[Cantidad * 2];

		JFrame frame;
		
		JTextField tfIntentos = new JTextField(3);
		tfIntentos.setEditable(false);

		String Cadena = "";

		try
		{
			Cadena = Integer.toString(x - 2);
		}

		catch (Exception e)
		{
			JOptionPane.showMessageDialog(null, "Ha ocurrido un error", "Error", JOptionPane.ERROR_MESSAGE);
		}

		frame = new JFrame("Nivel " + Cadena);

		EventQueue.invokeLater(new Runnable()
		{	
			public void run()
			{	
				String Numeros = "";
				
				if (M == "Libre")
					Intentos = (2 * x) + 2;
				else
					Intentos = 2 * x;
				
				try
				{
					Numeros = Integer.toString(Intentos);
				}
				
				catch (Exception e)
				{
					JOptionPane.showMessageDialog(frame, "");
				}
				
				int Contador = 0;

				int AxisXPar, AxisXImpar, AxisY, W, H;
				AxisXPar = AxisXImpar = 45;
				AxisY = 25;
				W = 80;
				H = 80;

				if (x == 3)
					{
						frame.setSize(505, 250);
						tfIntentos.setBounds(445, 25, 35, 35);
						tfIntentos.setText(Numeros);
						frame.add(tfIntentos);
					}

				if (x == 4)
					{
						frame.setSize(595, 250);
						tfIntentos.setBounds(535, 25, 35, 35);
						tfIntentos.setText(Numeros);
						frame.add(tfIntentos);
					}

				if (x == 5)
					{
						frame.setSize(695, 250);
						tfIntentos.setBounds(635, 25, 35, 35);
						tfIntentos.setText(Numeros);
						frame.add(tfIntentos);
					}

				if (x == 6)
					{
						frame.setSize(795, 250);
						tfIntentos.setBounds(735, 25, 35, 35);
						tfIntentos.setText(Numeros);
						frame.add(tfIntentos);
					}

				if (x == 7)
					{
						frame.setSize(795, 350);
						tfIntentos.setBounds(735, 25, 35, 35);
						tfIntentos.setText(Numeros);
						frame.add(tfIntentos);
					}

				if (x == 8)
					{
						frame.setSize(795, 350);
						tfIntentos.setBounds(735, 25, 35, 35);
						tfIntentos.setText(Numeros);
						frame.add(tfIntentos);
					}

				if (x == 9)
					{
						frame.setSize(795, 350);
						tfIntentos.setBounds(735, 25, 35, 35);
						tfIntentos.setText(Numeros);
						frame.add(tfIntentos);
					}

				if (x == 10)
					{
						frame.setSize(795, 450);
						tfIntentos.setBounds(735, 25, 35, 35);
						tfIntentos.setText(Numeros);
						frame.add(tfIntentos);
					}

				frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

				if (x < 7)
				{
					for (int i = 0; i < (Cantidad * 2); i++)
					{	
						if (i == 0)
						{
							Botones[i] = new JButton ();
							Botones[i].setIcon(CV);
							Botones[i].setBackground(GreenB);
							c[i] = new Carta(Imagen[Contador]);
							Botones[i].addMouseListener(new BotonOp());
							Botones[i].setBounds(AxisXPar, AxisY, W, H);
							AxisXPar += 100;
							AxisY = 105;
							frame.add(Botones[i]);
						}

						else if (i == 1)
						{
							Botones[i] = new JButton ();
							Botones[i].setIcon(CV);
							Botones[i].setBackground(GreenB);
							c[i] = new Carta(Imagen[Contador]);
							Botones[i].addMouseListener(new BotonOp());
							Botones[i].setBounds(AxisXImpar, AxisY, W, H);
							AxisXImpar += 100;
							AxisY = 25;
							frame.add(Botones[i]);
							Contador++;
						}

						else if (i % 2 == 0)
						{
							Botones[i] = new JButton ();
							Botones[i].setBackground(GreenB);
							Botones[i].setIcon(CV);
							c[i] = new Carta(Imagen[Contador]);
							Botones[i].addMouseListener(new BotonOp());
							Botones[i].setBounds(AxisXPar, AxisY, W, H);
							AxisXPar += 100;
							AxisY = 105;
							frame.add(Botones[i]);
						}

						else
						{
							Botones[i] = new JButton ();
							Botones[i].setBackground(GreenB);
							Botones[i].setIcon(CV);
							c[i] = new Carta(Imagen[Contador]);
							Botones[i].addMouseListener(new BotonOp());
							Botones[i].setBounds(AxisXImpar, AxisY, W, H);
							AxisXImpar += 100;
							AxisY = 25;
							frame.add(Botones[i]);
							Contador++;
						}
					}
				}

				else
				{					
					for (int i = 0; i < (Cantidad * 2); i++)
					{
						if (i >= 14)
						{
							int AY, AX;
							AY = 185;
							AX = 45;
							for (; i < (Cantidad * 2); i++)
							{
								if (i == 21)
								{
									AY += 100;
									AX = 345;
									Botones[i] = new JButton ();
									Botones[i].setIcon(CV);
									Botones[i].setBackground(GreenB);
									c[i] = new Carta(Imagen[Contador]);
									Botones[i].addMouseListener(new BotonOp());
									Botones[i].setBounds(AX, AY, W, H);
									AX += 100;
									frame.add(Botones[i]);
								}

								else if (i % 2 == 0)
								{
									Botones[i] = new JButton ();
									Botones[i].setIcon(CV);
									Botones[i].setBackground(GreenB);
									c[i] = new Carta(Imagen[Contador]);
									Botones[i].addMouseListener(new BotonOp());
									Botones[i].setBounds(AX, AY, W, H);
									AX += 100;
									frame.add(Botones[i]);
								}

								else
								{
									Botones[i] = new JButton ();
									Botones[i].setIcon(CV);
									Botones[i].setBackground(GreenB);
									c[i] = new Carta(Imagen[Contador]);
									Botones[i].addMouseListener(new BotonOp());
									Botones[i].setBounds(AX, AY, W, H);
									AX += 100;
									frame.add(Botones[i]);
									Contador++;
								}
							}
						}

						else if (i == 0)
						{
							Botones[i] = new JButton ();
							Botones[i].setIcon(CV);
							Botones[i].setBackground(GreenB);
							c[i] = new Carta(Imagen[Contador]);
							Botones[i].addMouseListener(new BotonOp());
							Botones[i].setBounds(AxisXPar, AxisY, W, H);
							AxisXPar += 100;
							AxisY = 105;
							frame.add(Botones[i]);
						}

						else if (i == 1)
						{
							Botones[i] = new JButton ();
							Botones[i].setIcon(CV);
							Botones[i].setBackground(GreenB);
							c[i] = new Carta(Imagen[Contador]);
							Botones[i].addMouseListener(new BotonOp());
							Botones[i].setBounds(AxisXImpar, AxisY, W, H);
							AxisXImpar += 100;
							AxisY = 25;
							frame.add(Botones[i]);
							Contador++;
						}

						else if (i % 2 == 0)
						{
							Botones[i] = new JButton ();
							Botones[i].setIcon(CV);
							Botones[i].setBackground(GreenB);
							c[i] = new Carta(Imagen[Contador]);
							Botones[i].addMouseListener(new BotonOp());
							Botones[i].setBounds(AxisXPar, AxisY, W, H);
							AxisXPar += 100;
							AxisY = 105;
							frame.add(Botones[i]);
						}

						else
						{
							Botones[i] = new JButton ();
							Botones[i].setIcon(CV);
							Botones[i].setBackground(GreenB);
							c[i] = new Carta(Imagen[Contador]);
							Botones[i].addMouseListener(new BotonOp());
							Botones[i].setBounds(AxisXImpar, AxisY, W, H);
							AxisXImpar += 100;
							AxisY = 25;
							frame.add(Botones[i]);
							Contador++;
						}
					}
				}

				Random r = new Random();
				for (int i = 0; i < Cantidad * 2; i++)
				{
					int j = r.nextInt(Cantidad * 2);
					Carta aux = c[i];
					c[i] = c[j];
					c[j] = aux;
					
				}
				
				frame.setLayout(null);
				frame.setLocationRelativeTo(null);

				frame.setVisible(true);


			}
			
			public boolean Comprobar(int x, int y)
			{
				String N = "";
				
				if (Botones[x].isEnabled())
				{
					if ((c[x].getNombre() == c[y].getNombre()) && (Botones[x].isEnabled() && !Botones[y].isEnabled()))
					{
						Botones[x].setBackground(Color.WHITE);
						Botones[x].setEnabled(false);
						Botones[y].setBackground(Color.WHITE);
						Botones[y].setEnabled(false);
						check = false;
						return true;
					}
					else
					{
						Intentos--;
						try
						{
							N = Integer.toString(Intentos);
						}
						
						catch (Exception e)
						{
							JOptionPane.showMessageDialog(frame, "Ha ocurrido un error");
						}
						
						tfIntentos.setText(N);
						Botones[y].setEnabled(true);
						Botones[x].setText("");
						Botones[x].setIcon(CV);
						Botones[x].setBackground(GreenB);
						Botones[y].setIcon(CV);
						Botones[y].setBackground(GreenB);
						Botones[y].setText("");
						check = false;
					}
				}
				return false;
			}

			public void Ganar()
			{
				JOptionPane.showMessageDialog(frame, "Ha ganado el juego");
			}
			
			int Cant = 0;
			
			class BotonOp implements MouseListener
			{
				@Override
				public void mousePressed(MouseEvent ae)
				{	
					for (int i = 0; i < Cantidad * 2; i++)
					{
						
						if (ae.getSource() == Botones[i]) 
						{
							if (Botones[i].isEnabled())
							{
								Botones[i].setIcon(c[i].getNombre());
								Botones[i].setBackground(Color.WHITE);

								if (!check) 
								{
									aux = i;
									check = true;
									Botones[i].setEnabled(false);
								}
								else
									if (aux != i) 
									{
										Botones[aux].setIcon(c[aux].getNombre());
										Botones[aux].setBackground(Color.WHITE);
										
										if (Comprobar(i, aux))
											Cant++;
										
										if (Cant == Cantidad)
											{
												if (h != 0)
												{
													Ganar();
													Boton[h].setEnabled(true);
													frame.dispatchEvent(new WindowEvent(frame, WindowEvent.WINDOW_CLOSING));
												}
												
												else
												{
													Ganar();
													frame.dispatchEvent(new WindowEvent(frame, WindowEvent.WINDOW_CLOSING));
												}
											}
										
										if (Intentos == 0)
											{
												JOptionPane.showMessageDialog(frame, "Se ha quedado sin intentos");
												for (int d = 2; d < 9; d++)
												{
													Boton[d].setEnabled(false);
												}
												frame.dispatchEvent(new WindowEvent(frame, WindowEvent.WINDOW_CLOSING));
											}
									}
							}
						}

					}

				}

				@Override
				public void mouseClicked(MouseEvent arg0) 
				{

				}

				@Override
				public void mouseEntered(MouseEvent arg0) 
				{

				}

				@Override
				public void mouseExited(MouseEvent arg0) 
				{

				}

				@Override
				public void mouseReleased(MouseEvent arg0) 
				{

				}
			}

		});
	}
}