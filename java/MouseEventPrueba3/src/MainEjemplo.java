import java.awt.Color;

import javax.swing.JFrame;
import javax.swing.WindowConstants;


public class MainEjemplo
{
    public static void main(String[] args)
    {
        JFrame v = new JFrame("Arrastrar Grafico");
        LienzoParaArrastrarFiguras c = new LienzoParaArrastrarFiguras();
        c.addFigura(new Rectangulo(2, 3, 50, 33, Color.RED));
        c.addFigura(new Rectangulo(7, 22, 150, 10, Color.GREEN));
        c.addFigura(new Rectangulo(11, 44, 20, 100, Color.CYAN));
        c.addFigura(new Circunferecia(6, 8, 34, Color.YELLOW));
        c.addFigura(new Circunferecia(34, 8, 55, Color.WHITE));
        c.addFigura(new Circunferecia(64, 8, 22, Color.BLUE));
        v.getContentPane().add(c);
        v.pack();
        v.setVisible(true);
        v.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
    }
}
