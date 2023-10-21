import java.io.*;

public class PruebaCelular{
	
	public static BufferedReader Leer(){
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		return br;
	}
	
	public static int LeerEntero(){
		
		int i = 0;
		boolean sw;
		do{
			
			sw = false;
			try{
				
				i = Integer.parseInt(Leer().readLine());
			}
			
			catch(Exception e){
				
				System.out.println("Ha ocurrido un error.");
				sw = true;
			}
		}while(sw);
		return i;
	}
	
	public static void main(String [] args){
		
		Celular c = new Celular();
		int opc = 0;
		do{
			
			System.out.println("El telefono se encuentra apagado. ¿Desea prenderlo? \n1.Si.\n2.No.");
			opc = LeerEntero();
			switch(opc){
			
			case 1:
				do{
					System.out.println("¿Que desea hacer? \n1.Llamar.\n2.Enviar mensaje.\n3.Consultar saldo.\n4.Apagar.\nOpcion: ");
					opc = LeerEntero();
					switch(opc){
					
					case 1:
						if(c.getSaldo() > 450){
							
							c.Llamar();
							System.out.println("Se ha echo la llamada exitosamente.");
						}
						else
							System.out.println("Saldo insuficiente.");
						break;
						
					case 2:
						if(c.getSaldo() > 150){
							
							c.Mensaje();
							System.out.println("Se ha enviado el mensaje.");							
						}
						else
							System.out.println("Saldo insuficiente.");
						break;
						
					case 3:
						System.out.println(c.toString());
						break;
						
					case 4:
						break;
						
					default:
						System.out.println("Opncion invalida. \n");
						break;
					}
				}while(opc != 4);
				break;
				
			case 2:
				break;
				
			default:
				System.out.println("Opncion invalida. \n");
				break;
			}
		}while(opc != 2);
	}
}