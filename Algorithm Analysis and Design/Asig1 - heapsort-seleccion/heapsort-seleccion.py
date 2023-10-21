#Kavir Alvarado CI: 26.256.604
#Eliana Rodríguez CI: 13.690.091
import time
#Iportamos un metodo de la biblioteca Matplotlib para la generación
#de gráficos a partir de datos contenidos en listas
import matplotlib.pyplot as plt
from io import open

elements = list()
times = list()

def heapsort(vectorheap): 
    #"""Esta función ordenara el vector que le pases como argumento 
    #con el Método Heap Sort"""
    # Imprimimos la lista obtenida al principio 
    print("El vector a ordenar con heap es:", vectorheap)
    largo = 0 # Establecemos un contador del largo
    for _ in vectorheap:
        largo += 1 # Obtenemos el largo del vector
    # Para amontonar la subparte a partir de i. 
    # n es el tamaño del montón.
    def amontonar(vectorheap, n, i): 
        mas_largo = i # Tomamos i como el más grande 
        izq = 2 * i + 1      
        der = 2 * i + 2    
        if izq < n and vectorheap[i] < vectorheap[izq]: 
            mas_largo = izq 
        # Ver si existe la subparte de i correctamente y
        # si es mayor que i
        if der < n and vectorheap[mas_largo] < vectorheap[der]: 
            mas_largo = der 
        if mas_largo != i: 
            vectorheap[i],vectorheap[mas_largo] = vectorheap[mas_largo],vectorheap[i] 
            # Cambiar el origen, si es necesario
            # amontonar el origen. 
            amontonar(vectorheap, n, mas_largo)
    def heap(vectorheap):  
        n = largo
        # Crear un montón maximo 
        for i in range(n//2 - 1, -1, -1): 
            amontonar(vectorheap, n, i) 
        # Extraer elementos uno a uno
        for i in range(n-1, 0, -1): 
            vectorheap[i], vectorheap[0] = vectorheap[0], vectorheap[i] 
            # Intercambio 
            amontonar(vectorheap, i, 0)
    start = time.time()    
    heap(vectorheap)
    end = time.time() 
    print("El vector ordenado con heap es:", vectorheap)
    print(largo, "Elements Sorted by HeapSort in ", end-start)
    elements.append(len(vectorheap))
    times.append(end-start)

def selectionsort(vectorselect):
    """Esta función ordenara el vector que le pases como argumento con el Método Selection Sort"""
    # Imprimimos la lista obtenida al principio 
    print ("El vector a ordenar es:",vectorselect)    
    largo = 0  
    for _ in vectorselect:
        largo += 1 # Obtenemos el largo del vector
    start = time.time()
    for i in range(largo): 
        # Encontrar el minimo elemento de los restantes sin ordenar    
        minimo = i 
        for j in range(i+1, largo): 
            if vectorselect[minimo] > vectorselect[j]: 
                minimo = j                    
        # Cambiamos el elemento minimo encontrado con el primer elemento de la matriz
        vectorselect[i], vectorselect[minimo] = vectorselect[minimo], vectorselect[i]
        # Repetimos el proceso hasta terminar
    end = time.time()
    print("El vector ordenado es: ",vectorselect) 
    print(largo,"Elementos ordenados por seleccion en ", end-start)
    elements.append(len(vectorselect))
    times.append(end-start)

def hPeorCaso():#función de las entradas del peor caso del heapsort
    
    for i in range(1, 2 ):

        archivo_pc1000=open("pc1000.txt","r")
        vectorheap=archivo_pc1000.readlines()
        heapsort(vectorheap)
        archivo_pc1000.close()
        
    for i in range(1, 2 ):

        archivo_pc2000=open("pc2000.txt","r")
        vectorheap=archivo_pc2000.readlines()
        heapsort(vectorheap)
        archivo_pc2000.close()
      
    for i in range(1, 2 ):

        archivo_pc3000=open("pc3000.txt","r")
        vectorheap=archivo_pc3000.readlines()
        heapsort(vectorheap)
        archivo_pc3000.close()

    for i in range(1, 2 ):

        archivo_pc4000=open("pc4000.txt","r")
        vectorheap=archivo_pc4000.readlines()
        heapsort(vectorheap)
        archivo_pc4000.close()
        
    for i in range(1, 2 ):

        archivo_pc5000=open("pc5000.txt","r")
        vectorheap=archivo_pc5000.readlines()
        heapsort(vectorheap)
        archivo_pc5000.close()
        
    for i in range(1, 2 ):

        archivo_pc6000=open("pc6000.txt","r")
        vectorheap=archivo_pc6000.readlines()
        heapsort(vectorheap)
        archivo_pc6000.close()
        
    plt.xlabel('Longitud de la Lista') 
    plt.ylabel('Tiempo de Ejecusion') 
    plt.plot(elements, times, label ='Heap Sort') 
    plt.grid() 
    plt.legend() 
    plt.show()

def hMejorCaso():#función de las entradas del mejor caso del heapsort
    
    for i in range(1, 2 ):

        archivo_mc1000=open("mc1000.txt","r")
        vectorheap=archivo_mc1000.readlines()
        heapsort(vectorheap)
        archivo_mc1000.close()

    for i in range(1, 2 ):

        archivo_mc2000=open("mc2000.txt","r") 
        vectorheap=archivo_mc2000.readlines()
        heapsort(vectorheap)
        archivo_mc2000.close()
    
    for i in range(1, 2 ):

        archivo_mc3000=open("mc3000.txt","r")
        vectorheap=archivo_mc3000.readlines()
        heapsort(vectorheap)
        archivo_mc3000.close()

    for i in range(1, 2 ):

        archivo_mc4000=open("mc4000.txt","r")
        vectorheap=archivo_mc4000.readlines()
        heapsort(vectorheap)
        archivo_mc4000.close()

    for i in range(1, 2 ):

        archivo_mc5000=open("mc5000.txt","r")
        vectorheap=archivo_mc5000.readlines()
        heapsort(vectorheap)
        archivo_mc5000.close()

    for i in range(1, 2 ):

        archivo_mc6000=open("mc6000.txt","r")
        vectorheap=archivo_mc6000.readlines()
        heapsort(vectorheap)
        archivo_mc6000.close()

    plt.xlabel('Longitud de la Lista') 
    plt.ylabel('Tiempo de Ejecusion') 
    plt.plot(elements, times, label ='Heap Sort') 
    plt.grid() 
    plt.legend() 
    plt.show()

def hCasoPromedio():#función de las entradas del caso promedio del heapsort
    
    for i in range(1, 2 ):

        archivo_cp1000=open("cp1000.txt","r")
        vectorheap=archivo_cp1000.readlines()
        heapsort(vectorheap)
        archivo_cp1000.close()

    for i in range(1, 2 ):

        archivo_cp2000=open("cp2000.txt","r")
        vectorheap=archivo_cp2000.readlines()
        heapsort(vectorheap)
        archivo_cp2000.close()
        
    for i in range(1, 2 ):

        archivo_cp3000=open("cp3000.txt","r")
        vectorheap=archivo_cp3000.readlines()
        heapsort(vectorheap)
        archivo_cp3000.close()

    for i in range(1, 2 ):

        archivo_cp4000=open("cp4000.txt","r")
        vectorheap=archivo_cp4000.readlines()
        heapsort(vectorheap)
        archivo_cp4000.close()

    for i in range(1, 2 ):

        archivo_cp5000=open("cp5000.txt","r")
        vectorheap=archivo_cp5000.readlines()
        heapsort(vectorheap)
        archivo_cp5000.close()

    for i in range(1, 2 ):

        archivo_cp6000=open("cp6000.txt","r")
        vectorheap=archivo_cp6000.readlines()
        heapsort(vectorheap)
        archivo_cp6000.close()

    plt.xlabel('Longitud de la Lista') 
    plt.ylabel('Tiempo de Ejecusion') 
    plt.plot(elements, times, label ='Heap Sort') 
    plt.grid() 
    plt.legend() 
    plt.show()

def sPeorCaso():#función de las entradas del peor caso del selección
    
    for i in range(1, 2 ):

        archivo_pc1000=open("pc1000.txt","r")
        vectorselect=archivo_pc1000.readlines()
        selectionsort(vectorselect)
        archivo_pc1000.close()   
    
    for i in range(1, 2 ):
        
        archivo_pc2000=open("pc2000.txt","r")
        vectorselect=archivo_pc2000.readlines()
        selectionsort(vectorselect)
        archivo_pc2000.close()   

    for i in range(1, 2 ):
        
        archivo_pc3000=open("pc3000.txt","r")
        vectorselect=archivo_pc3000.readlines()
        selectionsort(vectorselect)
        archivo_pc3000.close()   

    for i in range(1, 2 ):

        archivo_pc4000=open("pc4000.txt","r")
        vectorselect=archivo_pc4000.readlines()
        selectionsort(vectorselect)
        archivo_pc4000.close()  

    for i in range(1, 2 ):

        archivo_pc5000=open("pc5000.txt","r")
        vectorselect=archivo_pc5000.readlines()
        selectionsort(vectorselect)
        archivo_pc5000.close()  

    for i in range(1, 2 ):

        archivo_pc6000=open("pc6000.txt","r")
        vectorselect=archivo_pc6000.readlines()
        selectionsort(vectorselect)
        archivo_pc6000.close()  

    plt.xlabel('Longitud de la Lista') 
    plt.ylabel('Tiempo de Ejecusion') 
    plt.plot(elements, times, label ='Selección') 
    plt.grid() 
    plt.legend() 
    plt.show()
    
def sMejorCaso():#función de las entradas del mejor caso del selección
    
    for i in range(1, 2 ):
        
        archivo_mc1000=open("mc1000.txt","r")
        vectorselect=archivo_mc1000.readlines()
        selectionsort(vectorselect)
        archivo_mc1000.close()  
    
    for i in range(1, 2 ):
        
        archivo_mc2000=open("mc2000.txt","r")
        vectorselect=archivo_mc2000.readlines()
        selectionsort(vectorselect)
        archivo_mc2000.close()

    for i in range(1, 2 ):
        
        archivo_mc3000=open("mc3000.txt","r")
        vectorselect=archivo_mc3000.readlines()
        selectionsort(vectorselect)
        archivo_mc3000.close()

    for i in range(1, 2 ):

        archivo_mc4000=open("mc4000.txt","r")
        vectorselect=archivo_mc4000.readlines()
        selectionsort(vectorselect)
        archivo_mc4000.close()

    for i in range(1, 2 ):

        archivo_mc5000=open("mc5000.txt","r")
        vectorselect=archivo_mc5000.readlines()
        selectionsort(vectorselect)
        archivo_mc5000.close()

    for i in range(1, 2 ):

        archivo_mc6000=open("mc6000.txt","r")
        vectorselect=archivo_mc6000.readlines()
        selectionsort(vectorselect)
        archivo_mc6000.close()

    plt.xlabel('Longitud de la Lista') 
    plt.ylabel('Tiempo de Ejecusion') 
    plt.plot(elements, times, label ='Selección') 
    plt.grid() 
    plt.legend() 
    plt.show()

def sCasoPromedio():#función de las entradas del caso promedio del selección
    
    for i in range(1, 2 ):
        
        archivo_cp1000=open("cp1000.txt","r")
        vectorselect=archivo_cp1000.readlines()
        selectionsort(vectorselect)
        archivo_cp1000.close()
    
    for i in range(1, 2 ):
        
        archivo_cp2000=open("cp2000.txt","r")
        vectorselect=archivo_cp2000.readlines()
        selectionsort(vectorselect)
        archivo_cp2000.close()

    for i in range(1, 2 ):
        
        archivo_cp3000=open("cp3000.txt","r")
        vectorselect=archivo_cp3000.readlines()
        selectionsort(vectorselect)
        archivo_cp3000.close()

    for i in range(1, 2 ):

        archivo_cp4000=open("cp4000.txt","r")
        vectorselect=archivo_cp4000.readlines()
        selectionsort(vectorselect)
        archivo_cp4000.close()

    for i in range(1, 2 ):

        archivo_cp5000=open("cp5000.txt","r")
        vectorselect=archivo_cp5000.readlines()
        selectionsort(vectorselect)
        archivo_cp5000.close()

    for i in range(1, 2 ):

        archivo_cp6000=open("cp6000.txt","r")
        vectorselect=archivo_cp6000.readlines()
        selectionsort(vectorselect)
        archivo_cp6000.close()

    plt.xlabel('Longitud de la Lista') 
    plt.ylabel('Tiempo de Ejecusion') 
    plt.plot(elements, times, label ='Selección') 
    plt.grid() 
    plt.legend() 
    plt.show()

def menu():#menú principal
    
    opcion=input("\tMenu de opciones:\n1.Heapsort\n2.Selección\n3.Salir\nOpcion: ")

    if opcion=="1":
        
        opcion1=input("\n\tMenu de Heapsort:\n1.Peor Caso\n2.Mejor Caso\n3.Caso Promedio\n4.Salir\nOpcion: ")
     
        if opcion1=="1":
  
            hPeorCaso()
   
        elif opcion1=="2":

            hMejorCaso()
  
        elif opcion1=="3":

            hCasoPromedio()

        elif opcion1=="4":
            
            print("Programa terminado")
            
        else:
            print("Digite una opcion correcta")
   
    elif opcion=="2":
    
        opcion2=input("\n\tMenu de Selección:\n1.Peor Caso\n2.Mejor Caso\n3.Caso Promedio\n4.Salir\nOpcion: ")

        if opcion2=="1":
  
            sPeorCaso()
   
        elif opcion2=="2":
      
            sMejorCaso()
     
        elif opcion2=="3":

            sCasoPromedio()
  
        elif opcion2=="4":
            
            print("Programa terminado")
        
        else:
            print("Digite una opcion correcta")
     
    elif opcion=="3":
        
        print("Programa terminado")
        
    else:
        print("Digite una opcion correcta")
menu()
#Fin del programa
