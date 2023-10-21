import java.awt.Color;
import java.awt.Graphics;

public class Circunferecia implements InterfaceFigura
{
    private int x;

    private int y;

    private Color color;

    
    private int radio;

  
    public Circunferecia(int x, int y, int radio, Color color)
    {
        this.x = x;
        this.y = y;
        this.color = color;
        this.radio = radio;
    }

   
    public void dibujate(Graphics g)
    {
        g.setColor(color);
        g.drawOval(x - radio, y - radio, 2 * radio, 2 * radio);
    }

   
    public boolean estaDentro(int x, int y)
    {
        if (
            Math.sqrt(
                    ((this.x - x) * (this.x - x)) +
                    ((this.y - y) * (this.y - y))) < radio)
        {
            return true;
        }

        return false;
    }

    
    public void setPosicion(int x, int y)
    {
        this.x = x;
        this.y = y;
    }

    public int getX()
    {
        return x;
    }

   
    public int getY()
    {
        return y;
    }
}
