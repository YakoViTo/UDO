import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class CVAI 
{
	public static JFrame frame;

	public static void createFrame(Tienda t, JButton bVen, JButton bMos, JButton bMon, boolean sw, JFrame aux)
	{
		JLabel lNombre, lMarca, lGrado, lTiempo, lCant;
		lNombre = new JLabel("Nombre de la bebida: ");
		lMarca = new JLabel("Nombre de la marca: ");
		lGrado = new JLabel("Grado de la bebida: ");
		lTiempo = new JLabel("Tiempo de la bebida: ");
		lCant = new JLabel("Cantidad que desea: ");

		JTextField tNombre, tMarca, tGrado, tTiempo, tCant;
		tNombre = new JTextField(10);
		tMarca = new JTextField(10);
		tGrado = new JTextField(3);
		tTiempo = new JTextField(3);
		tCant = new JTextField(2);

		JButton bAceptar, bCancelar, bLimpiar;
		bAceptar = new JButton("Aceptar");
		bCancelar = new JButton("Cancelar");
		bLimpiar = new JButton("Limpiar");

		EventQueue.invokeLater(new Runnable()
		{
			public void run()
			{
				if (sw)
				{
					frame = new JFrame("Comprar alcoholica");
					frame.setSize(400, 350);
					lMarca.setBounds(5, 70, 140, 30); tMarca.setBounds(130, 70, 100, 30);
					lGrado.setBounds(5, 130, 120, 30); tGrado.setBounds(130, 130, 100, 30);
					lTiempo.setBounds(5, 190, 120, 30); tTiempo.setBounds(130, 190, 100, 30);
					lCant.setBounds(5, 250, 120, 30); tCant.setBounds(130, 250, 100, 30);
					bAceptar.setBounds(25, 290, 100, 30);
					bCancelar.setBounds(130, 290, 100, 30);
					bLimpiar.setBounds(235, 290, 100, 30);

					frame.add(lMarca); frame.add(tMarca);
					frame.add(lGrado); frame.add(tGrado);
					frame.add(lCant); frame.add(tCant);
					frame.add(bAceptar);
					frame.add(bCancelar);
					frame.add(bLimpiar);
				}

				else
				{
					frame = new JFrame("Vender alcoholica");
					frame.setSize(300, 200); 
					lCant.setBounds(5, 70, 120, 30); tCant.setBounds(110, 70, 100, 30);
					bAceptar.setBounds(25, 125, 100, 30);
					bCancelar.setBounds(130, 125, 100, 30);
					bLimpiar.setBounds(235, 125, 100, 30);

					frame.add(lCant); frame.add(tCant);
					frame.add(bAceptar);
					frame.add(bCancelar);
					frame.add(bLimpiar);
				}
				
				frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

				frame.setLayout(null);
				frame.setLocationRelativeTo(null);

				lNombre.setBounds(5, 10, 140, 30); tNombre.setBounds(130, 10, 100, 30);

				frame.add(lNombre); frame.add(tNombre);

				frame.setVisible(true);

				bAceptar.addActionListener(new AceptarBoton());
				bCancelar.addActionListener(new CancelarBoton());
				bLimpiar.addActionListener(new LimpiarBoton());
			}

			class AceptarBoton implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					Bebida b;
					if (sw)
					{
						int cant = 0;
						float gr = 0;
						short tiem = 0;
						String n, m, g, c, ti;
						n = tNombre.getText();
						m = tMarca.getText();
						g = tGrado.getText();
						ti = tTiempo.getText();
						c = tCant.getText();

						if (!n.isEmpty() && !m.isEmpty() && !g.isEmpty() && !ti.isEmpty() && !c.isEmpty())
						{
							try
							{
								gr = Float.parseFloat(g);
								tiem = Short.parseShort(ti);
								cant = Integer.parseInt(c);
							}

							catch (Exception e)
							{
								JOptionPane.showMessageDialog(frame, "Ha ocurrido un error");
							}

							b = new Alcoholica(n, m, gr, tiem);
							bVen.setEnabled(true);
							bMos.setEnabled(true);
							bMon.setEnabled(true);
							JOptionPane.showMessageDialog(frame, t.Comprar(b, cant));
							aux.dispatchEvent(new WindowEvent (frame, WindowEvent.WINDOW_CLOSING));
							frame.dispatchEvent(new WindowEvent (frame, WindowEvent.WINDOW_CLOSING));

						}

						else
						{
							JOptionPane.showMessageDialog(frame, "Ingrese datos", "Error", JOptionPane.ERROR_MESSAGE);
							tNombre.setText("");
							tMarca.setText("");
							tGrado.setText("");
							tTiempo.setText("");
							tCant.setText("");
						}
					}

					else
					{
						int cant = 0;
						String n, c;
						n = tNombre.getText();
						c = tCant.getText();

						if (!n.isEmpty() && !c.isEmpty())
						{
							try
							{
								cant = Integer.parseInt(c);
							}

							catch (Exception e)
							{
								JOptionPane.showMessageDialog(frame, "Ha ocurrido un error");
							}

							JOptionPane.showMessageDialog(frame, t.Vender(n, cant));
							aux.dispatchEvent(new WindowEvent (frame, WindowEvent.WINDOW_CLOSING));
							frame.dispatchEvent(new WindowEvent (frame, WindowEvent.WINDOW_CLOSING));
						}

						else
						{
							JOptionPane.showMessageDialog(frame, "Ingrese datos", "Error", JOptionPane.ERROR_MESSAGE);
							tNombre.setText("");
							tCant.setText("");
						}
					}
				}
			}

			class CancelarBoton implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					frame.dispatchEvent(new WindowEvent (frame, WindowEvent.WINDOW_CLOSING));
				}
			}

			class LimpiarBoton implements ActionListener
			{
				public void actionPerformed(ActionEvent ae)
				{
					tNombre.setText("");
					tMarca.setText("");
					tGrado.setText("");
					tTiempo.setText("");
					tCant.setText("");
				}
			}
		});
	}
}