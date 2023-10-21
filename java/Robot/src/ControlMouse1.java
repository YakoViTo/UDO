import java.awt.Robot;
import java.awt.AWTException;
 
class ControlMouse1 {
 
    public static void main(String[] args) throws AWTException {
        //instanciamos la clase Robot
        Robot robot = new Robot();
 
        //cambia la posición en pantalla del puntero a las coordenadas
        //X=300 e Y=600.
        robot.mouseMove(300, 600);
    }
}