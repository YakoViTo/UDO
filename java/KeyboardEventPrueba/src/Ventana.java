import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.awt.event.MouseListener;
import java.awt.event.MouseEvent;

class Ventana extends JFrame implements KeyListener {
	
	  JLabel labelTitulo;
	  JLabel labelAreaEntrada;
	  JLabel labelAreaSalida;
	  JLabel labelSalida;
	  JLabel labelContadorVocales;
	  JTextArea areaEntradaDeTexto;
	  JScrollPane scrollPaneAreaEntrada;
	  JTextArea areaSalidaDeTexto;
	  JScrollPane scrollPaneAreaSalida;
	 
	  int cantidadVocales=0;
	  String vocales="";
	   
	public Ventana() {
		
	     setLayout(null);
	     iniciaComponentes();
	     
	     setTitle("Keyboard Event");
	     
	     setSize(550,350);
	     
	     setLocationRelativeTo(null);
	     setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	   }
	 
	private void iniciaComponentes() {
		
		labelTitulo= new JLabel();
		labelTitulo.setFont(new java.awt.Font("Comic Sans MS", 0, 28));
		labelTitulo.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
		labelTitulo.setText("Eventos del Teclado");
		labelTitulo.setBorder(javax.swing.BorderFactory.
				createBevelBorder(javax.swing.border.BevelBorder.RAISED));
		labelTitulo.setBounds(110, 20, 300, 40);
	  
		labelAreaEntrada= new JLabel();
		labelAreaEntrada.setBounds(10, 70, 180, 40);
		labelAreaEntrada.setText("Area Entrada de Texto");
	   
		areaEntradaDeTexto = new JTextArea();
		areaEntradaDeTexto.setLineWrap(true);
		areaEntradaDeTexto.addKeyListener(this);
	   
		scrollPaneAreaEntrada = new JScrollPane();
		scrollPaneAreaEntrada.setBounds(10, 100, 513, 70);
		scrollPaneAreaEntrada.setViewportView(areaEntradaDeTexto);
	         
		labelAreaSalida= new JLabel();
		labelAreaSalida.setBounds(10, 170, 180, 40);
		labelAreaSalida.setText("Area Salida de Texto");
	   
		areaSalidaDeTexto = new JTextArea();
		areaSalidaDeTexto.setLineWrap(true);
		areaSalidaDeTexto.addKeyListener(this);
	   
		scrollPaneAreaSalida = new JScrollPane();
		scrollPaneAreaSalida.setBounds(10, 200, 513, 70);
		scrollPaneAreaSalida.setViewportView(areaSalidaDeTexto);
	  
		labelContadorVocales = new JLabel();
		labelContadorVocales.setBounds(380, 280, 190, 20);
	   
		labelSalida = new JLabel();
		labelSalida.setText("Para salir presione la tecla Escape");
		labelSalida.setBounds(10, 280, 210, 20);
	   
		add(labelTitulo);
	  	add(labelSalida);
	  	add(labelContadorVocales);
	  	add(labelAreaEntrada);
	  	add(labelAreaSalida);
	  	add(scrollPaneAreaEntrada);
	  	add(scrollPaneAreaSalida);
	   
	}
	 
	
	
	public void keyPressed(KeyEvent e) {
	   
		if (e.getSource()==areaEntradaDeTexto){
		  
		  if (e.VK_A==e.getKeyCode()) {
			  
			  vocales+="a ";
			  cantidadVocales++;
		  }
		  
		  if (e.VK_E==e.getKeyCode()) {
			  
			  vocales+="e "; 
			  cantidadVocales++;
		  }
		  
		  if (e.VK_I==e.getKeyCode()) {
			  
			  vocales+="i ";
			  cantidadVocales++;
		  }
		  
		  if (e.VK_O==e.getKeyCode()) {
			  
			  vocales+="o "; 
			  cantidadVocales++;
		  }
		  
		  if (e.VK_U==e.getKeyCode()) {
			  
			  vocales+="u ";
			  cantidadVocales++;
		  }
	  } 
		areaSalidaDeTexto.setText(vocales);
		labelContadorVocales.setText("Numero Vocales: "+cantidadVocales);
	}
	 
	
	public void keyReleased(KeyEvent e) {
		
	  System.out.println("Soltó la tecla:  "+e.getKeyText(e.getKeyCode()));
	  
	   if (e.getSource()==areaEntradaDeTexto){
		   
		   if (e.VK_ESCAPE==e.getKeyCode()){
			   
			   int respuesta = JOptionPane.showConfirmDialog(this,"Esta seguro que desea salir?", "Confirmación",JOptionPane.YES_NO_OPTION);
			   
			   if (respuesta == JOptionPane.YES_NO_OPTION) {
				   
				   System.exit(0);
			   }
	      }
	   } 
	}
	 
	
	public void keyTyped(KeyEvent e) {
		  
	}
}
