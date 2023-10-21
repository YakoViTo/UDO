import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.event.*;

import javax.swing.*;

public class Bola1 extends JFrame{

	Panell panel=new Panell();	

 public Bola1(){

	super("Bola Movimientoo");

	setSize(500,500);
	setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);	

	add(panel);

	setVisible(true);



 }
	
 public static void main(String[]args){

	 Bola1 bolita=new Bola1();	
	

 }


}

class Panell extends JPanel implements ActionListener{

	BolaMovimientos bolaMov=new BolaMovimientos(this);
	Timer timer;
	
 public Panell(){
	
	
	 setFocusable(true);
	 addKeyListener(new teclado());
	 timer=new Timer(15,this);
	 timer.start();

}



 public void paintComponent(Graphics g){
	
	super.paintComponent(g);
	
	Graphics2D g2=(Graphics2D)g;
	g2.setColor(Color.red);
	g2.fillOval(bolaMov.getX(), bolaMov.getY(), 30, 30);
	
 }



@Override
public void actionPerformed(ActionEvent e) {

	
 bolaMov.mover();
 repaint();
	
	
}
	private class teclado extends KeyAdapter{
	
		public void keyReleased(KeyEvent e){
			bolaMov.keyReleased(e);
		}
		public void keyPressed(KeyEvent e){
			bolaMov.keyPressed(e);
		}
	}
}




class BolaMovimientos{

	
	
Panell panel1;

int x=1;
int y=1;
int dx=0;
int dy=0;

public BolaMovimientos(Panell panelito){

this.panel1=panelito;	

}
	
public void mover(){

x=x+dx;
y=y+dy;
	
	if((x+dx)>panel1.getWidth()-30){
		dx=-1;
	
	}else if((x+dx)<0){
		dx=1;

	}else if((y+dy)>panel1.getHeight()-30){
		dy=-1;
	
	}else if((y+dy)<0){
		dy=1;
	}


	
	
}

public void keyPressed(KeyEvent e){

	int key=e.getExtendedKeyCode();
		
		if(key==KeyEvent.VK_LEFT){
			
			dx=-1;
			dy=0;
			
		}
		if(key==KeyEvent.VK_RIGHT){
			
			dx=1;
			dy=0;
			
		}
		if(key==KeyEvent.VK_UP){
	
			dx=0;
			dy=-1;
			
		}
		if(key==KeyEvent.VK_DOWN){
	
			dx=0;
			dy=1;
			
		}
	
}

public void keyReleased(KeyEvent e){

	int key=e.getExtendedKeyCode();
		
		if(key==KeyEvent.VK_LEFT){
			
			
			
		}
		if(key==KeyEvent.VK_RIGHT){
			
			
			
		}
		if(key==KeyEvent.VK_UP){
	
			
			
		}
		if(key==KeyEvent.VK_DOWN){
	
			
			
		}
	
}


public int getX(){

	return x;
}
public int getY(){
	return y;
	
}
	
}