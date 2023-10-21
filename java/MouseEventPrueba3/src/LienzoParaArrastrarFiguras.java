import java.awt.Canvas;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionListener;

import java.util.LinkedList;

public class LienzoParaArrastrarFiguras extends Canvas implements MouseMotionListener
{
   
    private static final long serialVersionUID = -4273648398171436938L;  
    private LinkedList<InterfaceFigura> listaFiguras = new LinkedList<InterfaceFigura>();
    private InterfaceFigura figuraArrastrandose = null;
    private int xAnteriorRaton;
    private int yAnteriorRaton;
    public LienzoParaArrastrarFiguras()
    {
        addMouseMotionListener(this);
    }

    public void addFigura(InterfaceFigura figura)
    {
        listaFiguras.add(figura);
    }

    public void removeFigura(InterfaceFigura figura)
    {
        listaFiguras.remove(figura);
    }

    public Dimension getPreferredSize()
    {
        return new Dimension(500, 500);
    }

    public void paint(Graphics g)
    {
        for (InterfaceFigura figura : listaFiguras)
        {
            figura.dibujate(g);
        }
    }

    public void mouseDragged(MouseEvent e)
    {
        
        if (figuraArrastrandose == null)
        {
           
            xAnteriorRaton = e.getX();
            yAnteriorRaton = e.getY();
           
            figuraArrastrandose = dameFigura(e);
        }
        else
        {
            figuraArrastrandose.setPosicion(
                figuraArrastrandose.getX() + (e.getX() - xAnteriorRaton),
                figuraArrastrandose.getY() + (e.getY() - yAnteriorRaton));

           
            xAnteriorRaton = e.getX();
            yAnteriorRaton = e.getY();

           
            repaint();
        }
    }

   
    private InterfaceFigura dameFigura(MouseEvent e)
    {
        for (InterfaceFigura figura : listaFiguras)
        {
            if (figura.estaDentro(e.getX(), e.getY()))
            {
                return figura;
            }
        }

        return null;
    }

    
    public void mouseMoved(MouseEvent e)
    {
        figuraArrastrandose = null;
    }
}