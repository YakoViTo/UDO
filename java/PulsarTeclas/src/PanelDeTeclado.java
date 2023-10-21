import javax.swing.*;
import java.awt.event.*;

public class PanelDeTeclado extends JPanel implements KeyListener, MouseListener {
public boolean isFocusable(){
return true;
}
public void mousePressed( MouseEvent e ) {}
public void mouseReleased( MouseEvent e ) {}
public void mouseClicked( MouseEvent e ) {}
public void mouseEntered( MouseEvent e ) {
this.requestFocus();
}
public void mouseExited( MouseEvent e ) {}
public void keyReleased( KeyEvent e ) {
}
public void keyTyped( KeyEvent e ) {
}
public void keyPressed( KeyEvent e ) {
System.out.println("Usted ha presionado la tecla: "+e.getKeyText(e.getKeyCode()));
}

public PanelDeTeclado(){
this.addMouseListener(this);
this.addKeyListener(this);
}

public static void main( String [] args ){
JFrame f = new JFrame();
f.getContentPane().add(new PanelDeTeclado());
f.setSize(400,300);
f.setVisible(true);
f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
}
}