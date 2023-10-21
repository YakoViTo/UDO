package pruebaviaje;

import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.Graphics;
import java.awt.HeadlessException;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JFrame;
import javax.swing.JTextArea;

public class ListaFrame extends JFrame implements ActionListener{
    JTextArea tm;
    ArregloViaje v;
    Container c;

    public ListaFrame(ArregloViaje v){
        super("Lista de Viajes");
        setLayout(new FlowLayout());
        c=getContentPane();
        this.v=v;
        tm=new JTextArea(300,300);
        c.add(tm);
    }
    public void actionPerformed(ActionEvent ae) {
        tm.setText(v.ListarTodo());
    }
    public void paint (Graphics g){
        super.paint(g);
    }

}
