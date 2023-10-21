import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.awt.event.MouseListener;
import java.awt.event.MouseEvent;


class Ventana extends JFrame implements MouseListener {
	
	JLabel etiqueta1, etiqueta2;
	JLabel labelTitulo;
	JButton boton1;
 
	public Ventana() {
		
		setLayout(null);
 
		labelTitulo= new JLabel();
		labelTitulo.setText("Eventos del Mouse");
		labelTitulo.setFont(new java.awt.Font("Comic Sans MS", 0, 28));
		labelTitulo.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
		labelTitulo.setBorder(javax.swing.BorderFactory.createBevelBorder
				(javax.swing.border.BevelBorder.LOWERED));
		labelTitulo.setBounds(40, 10, 300, 40);
		labelTitulo.addMouseListener(this);
   
		etiqueta1 = new JLabel();
		etiqueta1.setBounds(10, 160, 190, 20);
		etiqueta2 = new JLabel();
		etiqueta2.setBounds(10, 180, 190, 20);
   
		boton1 = new JButton();
		boton1.setBounds(110, 75, 150, 75);
		boton1.setText("Presioname");
		boton1.addMouseListener(this);
     
		add(labelTitulo);
		add(etiqueta1);
		add(etiqueta2);
 		add(boton1);
   
 		setTitle("MouseEvent");
 		setSize(400, 240); 
	}
 
	public void mouseClicked(MouseEvent evento) {
		
		if (evento.getSource() == boton1){
			etiqueta1.setText("Hizo clic en mi bot�n");
		}
		if (evento.getSource() == labelTitulo){
			etiqueta1.setText("Hizo clic en el Titulo");
		}
	}
 
	public void mousePressed(MouseEvent evento) {
		
		etiqueta1.setText("");
		if (evento.getSource() == boton1){
			etiqueta2.setText("Presiono el bot�n");
		}
		if (evento.getSource() == labelTitulo){
			etiqueta2.setText("Presiono el Titulo");
		}
	}
 
	public void mouseReleased(MouseEvent evento) {
		
		if (evento.getSource() == boton1){
			etiqueta2.setText("Libero el bot�n");
		}
		if (evento.getSource() == labelTitulo){
			etiqueta2.setText("Libero el Titulo");
		}
	}
 
	public void mouseExited(MouseEvent evento) {
		
		if (evento.getSource() == boton1){
			etiqueta1.setText("Salio del bot�n");
		}
		if (evento.getSource() == labelTitulo){
			etiqueta1.setText("Salio del Titulo");
		}
		etiqueta2.setText("");
	}
 
	public void mouseEntered(MouseEvent evento) {
		
		if (evento.getSource() == boton1){
			etiqueta1.setText("Entro a mi bot�n");
		}
		if (evento.getSource() == labelTitulo){
			etiqueta1.setText("Entro al Titulo");
		}
		etiqueta2.setText("");
	}
}