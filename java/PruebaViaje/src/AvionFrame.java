
package pruebaviaje;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;
public class AvionFrame extends JFrame implements ActionListener{
     JLabel lpar,lll,ldis,lve,lm;
    JTextField tpar,tll,tdis,tve;
    JButton bGuardar;
    ArregloViaje v;
    Viaje vi;
    Container c;

    public AvionFrame(ArregloViaje v) {
        super("Viaje en Avion");
        this.v=v;
         super.setVisible(true);
         c=getContentPane();
        c.setLayout(new FlowLayout());
        
        lpar=new JLabel("Pto. Partida:");
        lll=new JLabel("Pto. Llegada:");
        ldis=new JLabel("Distancia:");
        lve=new JLabel("Velocidad:");
        lm=new JLabel("");
        
        tpar=new JTextField(10);
        tll=new JTextField(10);
        tdis=new JTextField(5);
        tve=new JTextField(5);
        
        bGuardar=new JButton("Guardar");
        bGuardar.addActionListener(this);
        
        c.add(lpar); c.add(tpar);
        c.add(lll); c.add(tll);
        c.add(ldis); c.add(tdis);
        c.add(lve); c.add(tve);
        c.add(bGuardar);
        c.add(lm);
        super.setSize(500,500);
        repaint();
    }

   
    
   public void actionPerformed(ActionEvent ae) {
        String part = null,ll = null;
        float dis = 0,ve = 0;
        if(ae.getSource().equals(bGuardar)){
        try{
            part=tpar.getText();
            ll=tll.getText();
            dis=Float.parseFloat(tdis.getText());
            ve=Float.parseFloat(tve.getText());
            
        }
        catch(Exception ex){
            JOptionPane.showMessageDialog(null,"Error");
        }
        vi=new Avion(dis,ve,part,ll);
        JOptionPane.showMessageDialog(null, v.agregarViaje(vi));
    }
   }
}
