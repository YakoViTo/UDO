
package pruebaviaje;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class PruebaViajeFrame extends JFrame
        implements ActionListener, ItemListener{
    JLabel ltipo;
    JRadioButton rAg,rCal,rLi,rAu,rAvi;
    ButtonGroup opc,tipo;
    JButton bAceptar,bGuardar;
    Container c;
    ArregloViaje v;
    Viaje x;

    public PruebaViajeFrame() {
        super("Agencia de Viaje");
        setLayout(new FlowLayout());
        c=getContentPane();
        this.v=v;
        rAg=new JRadioButton("Agregar Viaje");
        rCal=new JRadioButton("Calcular Tiempo");
        rLi=new JRadioButton("Listar Viaje");
        bAceptar=new JButton("Siguiente");
       
        opc=new ButtonGroup();
        opc.add(rAg);
        opc.add(rCal);
        opc.add(rLi);
        bAceptar.addActionListener(this);
        ltipo=new JLabel("Tipo:");
        rAu=new JRadioButton("Auto");
        rAvi=new JRadioButton("Avion");
        tipo=new ButtonGroup();
        tipo.add(rAu);
        tipo.add(rAvi);
        bGuardar=new JButton("Guardar");
        bGuardar.addActionListener(this);
        
        c.add(rAg); 
        c.add(rCal);
        c.add(rLi);
        c.add(bAceptar);
        c.add(ltipo);
        c.add(rAu);
        c.add(rAvi);
        c.add(bGuardar);
        mostrar(false);
    }
    
    public void mostrar(boolean d){
        ltipo.setVisible(d);
        rAu.setVisible(d);
        rAvi.setVisible(d);
        bGuardar.setVisible(d);
		
	}
    
    public void paint (Graphics g){
        super.paint(g);
    }

    public void actionPerformed(ActionEvent ae) {
        if(ae.getSource().equals(bAceptar)){
        if(rAg.isSelected()){
            
                mostrar(true);
            }
            else 
                if(rCal.isSelected()){
                    CalcularFrame f1=new CalcularFrame(v);
                    f1.setVisible(true);
                }
                if(rLi.isSelected()){
                    ListaFrame f1=new ListaFrame(v);
                    f1.setVisible(true);
                }       
        
        
        else JOptionPane.showMessageDialog(null, "ingrese una opcion valida");
        }
            if(rAu.isSelected()){
                    AutoFrame auf=new AutoFrame(v);
                    auf.setVisible(true);
                }
                if(rAvi.isSelected()){
                    AvionFrame avf=new AvionFrame(v);
                    avf.setVisible(true);
                } 
           
    }
    public void itemStateChanged(ItemEvent ie){
        
    }
   
}
