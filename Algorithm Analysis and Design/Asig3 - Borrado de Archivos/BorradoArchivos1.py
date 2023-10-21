#Kavir Alvarado CI: 26.256.604
#Eliana Rodríguez CI: 13.690.091
from io import open

outputdata=open("MINBORRA.OUT","w")


def borrado(ida):
    
    n=int(ida[0])#N archivos que se deben borrar
    t=1#variable que almacena líneas importantes
    i=1#variable que almacena líneas importantes
    borrado1(n,t,i,ida)
    
def borrado1(n,t,i,ida):#función para comparar longitudes
    
    while n!=1:
        i = 1
        if(len(ida[i])==len(ida[n])):
            t=t+1
            n=n-1
            itera2(n,t,i,ida)      
        else:
            i=i+1
            itera1(n,t,i,ida)
            
            
def itera1(n,t,i,ida):#función para comparar longitudes
    
    while i!=n:
        
        if(len(ida[i])==len(ida[n])):
            t=t+1
            n=n-1
            itera2(n,t,i,ida)
        else:
            i=i+1
            itera1(n,t,i,ida)
    outputdata.write("DEL ")
    outputdata.write(ida[i])         
    n=n-1
    borrado1(n,t,i,ida)


def itera2(n,t,i,ida):#función para comparar longitudes
    
    while n!=i:
        
        if(len(ida[i])==len(ida[n])):
            t=t+1
            n=n-1
            itera2(n,t,i,ida)
        else:
            i=i+1
            itera1(n,t,i,ida)
    outputdata.write("\nDEL  ")
    dt=t
    x=len(ida[i])-2
    dx=x
    itera3(x,dx,t,dt,ida)
    borrado1(n,t,i,ida)

def itera3(x,dx,t,dt,ida):#compara caracteres entre cada linea
    
    while (x != -1):

        while dt!=1:
        
            if(ida[dt][dx-x]==ida[dt-1][dx-x]):
                dt=dt-1
                itera3(x,dx,t,dt,ida)
            else:
                outputdata.write("?")
                x=x-1
                itera3(x,dx,t,dt,ida)
        outputdata.write(ida[dt][dx-x])
        x=x-1
        dt=t
        itera3(x,dx,t,dt,ida)
        
    outputdata.close()
         
def menu():#menú principal

    opcion=input("\tMenu de opciones:\n1.Prueba 1\n2.Prueba 2\n3.Prueba 3\n4.Prueba 4\n5.Salir\nOpcion: ")

    if opcion=="1":
        inputdata=open("MINBORRA1.IN","r")
        ida=inputdata.readlines()
        inputdata.close()
        borrado(ida)

    elif opcion=="2":
        inputdata=open("MINBORRA2.IN","r")
        ida=inputdata.readlines()
        inputdata.close()
        borrado(ida)

    elif opcion=="3":
        inputdata=open("MINBORRA3.IN","r")
        ida=inputdata.readlines()
        inputdata.close()
        borrado(ida)

    elif opcion=="4":
        inputdata=open("MINBORRA4.IN","r")
        ida=inputdata.readlines()
        inputdata.close()
        borrado(ida)

    elif opcion=="5":

        print("Programa terminado...")

    else:
        print("\nDigite una opcion correcta...\n")
        menu()
menu()
#Fin del programa

