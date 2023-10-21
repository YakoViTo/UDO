
import java.awt.Canvas;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionListener;

import javax.swing.JFrame;
import javax.swing.WindowConstants;


public class ArrastrarGrafico extends Canvas implements MouseMotionListener{
	
	    
	private static final long serialVersionUID = -4273648398171436938L;
    private int xRectangulo = 0;
    private int yRectangulo = 0;
    private int anchoRectangulo = 100;
    private int altoRectangulo = 100;
    private boolean arrastrando = false;
    private int xAnteriorRaton;
    private int yAnteriorRaton;

    public ArrastrarGrafico(){
    	
        addMouseMotionListener(this);
    }

    public Dimension getPreferredSize() {
    	
        return new Dimension(500, 500);
    }

    public void paint(Graphics g){
    	
        g.setColor(Color.RED);
        g.fillRect(xRectangulo, yRectangulo, anchoRectangulo, altoRectangulo);
    }

    public static void main(String[] args){
    	
        JFrame v = new JFrame("Arrastrar Grafico");
        ArrastrarGrafico c = new ArrastrarGrafico();
        v.getContentPane().add(c);
        v.pack();
        v.setVisible(true);
        v.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
    }

    public void mouseDragged(MouseEvent e){
    	
        if (!arrastrando){
          
            if (estaDentro(e)){
              
                xAnteriorRaton = e.getX();
                yAnteriorRaton = e.getY();
                arrastrando = true;
            }
        }
        else{
          
            xRectangulo = (xRectangulo + e.getX()) - xAnteriorRaton;
            yRectangulo = (yRectangulo + e.getY()) - yAnteriorRaton;
            
            xAnteriorRaton = e.getX();
            yAnteriorRaton = e.getY();
            
            repaint();
        }
    }

    private boolean estaDentro(MouseEvent e){
    	
        if ((e.getX() > xRectangulo) &&
                (e.getX() < (xRectangulo + anchoRectangulo)) &&
                (e.getY() > yRectangulo) &&
                (e.getY() < (yRectangulo + altoRectangulo))){
        	
            return true;
        }

        return false;
    }

    public void mouseMoved(MouseEvent e){
    	
        arrastrando = false;
    }
}