#Kavir Alvarado CI: 26.256.604
#Eliana Rodríguez CI: 13.690.091
import matplotlib.pyplot as plt
from numpy.random import seed 
from numpy.random import randint
from io import open

def Prueba1():
   
    archivo_x1=open("p1x1.txt","r")
    x1=archivo_x1.readlines()
    archivo_x1.close()

    archivo_y1=open("p1y1.txt","r")
    y1=archivo_y1.readlines()
    archivo_y1.close()

    archivo_x2=open("p1x2.txt","r")
    x2=archivo_x2.readlines()
    archivo_x2.close()

    archivo_y2=open("p1y2.txt","r")
    y2=archivo_y2.readlines()
    archivo_y2.close()

    archivo_x3=open("p1x3.txt","r")
    x3=archivo_x3.readlines()
    archivo_x3.close()

    archivo_y3=open("p1y3.txt","r")
    y3=archivo_y3.readlines()
    archivo_y3.close()

    archivo_x4=open("p1x4.txt","r")
    x4=archivo_x4.readlines()
    archivo_x4.close()

    archivo_y4=open("p1y4.txt","r")
    y4=archivo_y4.readlines()
    archivo_y4.close()

    archivo_x5=open("p1x5.txt","r")
    x5=archivo_x5.readlines()
    archivo_x5.close()

    archivo_y5=open("p1y5.txt","r")
    y5=archivo_y5.readlines()
    archivo_y5.close()

    #x1 = [1,3]
    #y1 = [4,4]
    #x2 = [2,2]
    #y2 = [3,4]
    #x3 = [3,4]
    #y3 = [2,3]
    #x4 = [7,1]
    #y4 = [2,4]
    #x5 = [4,2]
    #y5 = [4,3]
    
    px1=[int(i) for i in x1]
    py1=[int(i) for i in y1]
    px2=[int(i) for i in x2]
    py2=[int(i) for i in y2]
    px3=[int(i) for i in x3]
    py3=[int(i) for i in y3]
    px4=[int(i) for i in x4]
    py4=[int(i) for i in y4]
    px5=[int(i) for i in x5]
    py5=[int(i) for i in y5]
 
    r1=randint(px3[0], 7)
    r2=randint(px1[0], px1[1])
    
    if(r2==px2[0]):
        if((r1==px3[0])|(r1==px5[0])):
            px6 = [randint(px3[0],5),px2[0]]
            py6 = [py3[0], py2[1]]
            print("\nRecta de corte: ", px6[0], py6[0], px6[1], py6[1])
            print("\nSegmentos ordenados que la recta de corte va intersectando:\n\n\t3er Segmento: ", px3[0], py3[0], px3[1], py3[1],"\n\t5to Segmento: ", px5[0], py5[0], px5[1], py5[1],"\n\t4to Segmento: ", px4[0], py4[0], px4[1], py4[1],"\n\t2do Segmento: ", px2[0], py2[0], px2[1], py2[1],"\n\t1er Segmento: ", px1[0], py1[0], px1[1], py1[1])
        else:
            px6 = [randint(5,7),px2[0]]
            py6 = [py3[0], py2[1]]
            print("\nRecta de corte: ", px6[0], py6[0], px6[1], py6[1])
            print("\nSegmentos ordenados que la recta de corte va intersectando:\n\n\t3er Segmento: ", px3[0], py3[0], px3[1], py3[1],"\n\t4to Segmento: ", px4[0], py4[0], px4[1], py4[1],"\n\t5to Segmento: ", px5[0], py5[0], px5[1], py5[1],"\n\t2do Segmento: ", px2[0], py2[0], px2[1], py2[1],"\n\t1er Segmento: ", px1[0], py1[0], px1[1], py1[1])
    else:
        px6 = [r1,px1[0]]
        py6 = [py3[0], py2[1]]
        print("\nRecta de corte: ", px6[0], py6[0], px6[1], py6[1])
        print("\nSegmentos ordenados que la recta de corte va intersectando:\n\n\t3er Segmento: ", px3[0], py3[0], px3[1], py3[1],"\n\t5to Segmento: ", px5[0], py5[0], px5[1], py5[1],"\n\t2do Segmento: ", px2[0], py2[0], px2[1], py2[1],"\n\t4to Segmento: ", px4[0], py4[0], px4[1], py4[1],"\n\t1er Segmento: ", px1[0], py1[0], px1[1], py1[1])

    
        
    plt.xlabel('Eje de las X') 
    plt.ylabel('Eje de las Y') 
    plt.plot(px1, py1, label ='1er Segmento')
    plt.plot(px2, py2, label ='2do Segmento')
    plt.plot(px3, py3, label ='3er Segmento')
    plt.plot(px4, py4, label ='4to Segmento')
    plt.plot(px5, py5, label ='5to Segmento')
    plt.plot(px6, py6, label ='Recta de corte')
    plt.grid() 
    plt.legend() 
    plt.show()

def Prueba2():
   
    archivo_x1=open("p2x1.txt","r")
    x1=archivo_x1.readlines()
    archivo_x1.close()

    archivo_y1=open("p2y1.txt","r")
    y1=archivo_y1.readlines()
    archivo_y1.close()

    archivo_x2=open("p2x2.txt","r")
    x2=archivo_x2.readlines()
    archivo_x2.close()

    archivo_y2=open("p2y2.txt","r")
    y2=archivo_y2.readlines()
    archivo_y2.close()

    archivo_x3=open("p2x3.txt","r")
    x3=archivo_x3.readlines()
    archivo_x3.close()

    archivo_y3=open("p2y3.txt","r")
    y3=archivo_y3.readlines()
    archivo_y3.close()

    archivo_x4=open("p2x4.txt","r")
    x4=archivo_x4.readlines()
    archivo_x4.close()

    archivo_y4=open("p2y4.txt","r")
    y4=archivo_y4.readlines()
    archivo_y4.close()

    archivo_x5=open("p2x5.txt","r")
    x5=archivo_x5.readlines()
    archivo_x5.close()

    archivo_y5=open("p2y5.txt","r")
    y5=archivo_y5.readlines()
    archivo_y5.close()

    #x1 = [7,9]
    #y1 = [3,3]
    #x2 = [6,8]
    #y2 = [3,3]
    #x3 = [5,8]
    #y3 = [1,2]
    #x4 = [9,4]
    #y4 = [4,4]
    #x5 = [2,2]
    #y5 = [2,3]
    
    px1=[int(i) for i in x1]
    py1=[int(i) for i in y1]
    px2=[int(i) for i in x2]
    py2=[int(i) for i in y2]
    px3=[int(i) for i in x3]
    py3=[int(i) for i in y3]
    px4=[int(i) for i in x4]
    py4=[int(i) for i in y4]
    px5=[int(i) for i in x5]
    py5=[int(i) for i in y5]

    r1=randint(px2[1], 10)
    
    if(r1==px2[1]):
        
        
        px6 = [px2[1], px2[1]]
        py6 = [py3[0], py4[1]]
        
    else:
        px6 = [px2[0], px1[1]]
        py6 = [py3[0], py4[1]]

    print("\nRecta de corte: ", px6[0], py6[0], px6[1], py6[1])
    print("\nSegmentos ordenados que la recta de corte va intersectando:\n\n\t3er Segmento: ", px3[0], py3[0], px3[1], py3[1],"\n\t2do Segmento: ", px2[0], py2[0], px2[1], py2[1],"\n\t1er Segmento: ", px1[0], py1[0], px1[1], py1[1],"\n\t4to Segmento: ", px4[0], py4[0], px4[1], py4[1])
  
    plt.xlabel('Eje de las X') 
    plt.ylabel('Eje de las Y') 
    plt.plot(px1, py1, label ='1er Segmento')
    plt.plot(px2, py2, label ='2do Segmento')
    plt.plot(px3, py3, label ='3er Segmento')
    plt.plot(px4, py4, label ='4to Segmento')
    plt.plot(px5, py5, label ='5to Segmento')
    plt.plot(px6, py6, label ='Recta de corte')
    plt.grid() 
    plt.legend() 
    plt.show()

def Prueba3():
   
    archivo_x1=open("p3x1.txt","r")
    x1=archivo_x1.readlines()
    archivo_x1.close()

    archivo_y1=open("p3y1.txt","r")
    y1=archivo_y1.readlines()
    archivo_y1.close()

    archivo_x2=open("p3x2.txt","r")
    x2=archivo_x2.readlines()
    archivo_x2.close()

    archivo_y2=open("p3y2.txt","r")
    y2=archivo_y2.readlines()
    archivo_y2.close()

    archivo_x3=open("p3x3.txt","r")
    x3=archivo_x3.readlines()
    archivo_x3.close()

    archivo_y3=open("p3y3.txt","r")
    y3=archivo_y3.readlines()
    archivo_y3.close()

    archivo_x4=open("p3x4.txt","r")
    x4=archivo_x4.readlines()
    archivo_x4.close()

    archivo_y4=open("p3y4.txt","r")
    y4=archivo_y4.readlines()
    archivo_y4.close()

    archivo_x5=open("p3x5.txt","r")
    x5=archivo_x5.readlines()
    archivo_x5.close()

    archivo_y5=open("p3y5.txt","r")
    y5=archivo_y5.readlines()
    archivo_y5.close()

    #x1 = [1,1]
    #y1 = [1,3]
    #x2 = [3,1]
    #y2 = [1,4]
    #x3 = [2,3]
    #y3 = [7,7]
    #x4 = [4,4]
    #y4 = [1,6]
    #x5 = [4,7]
    #y5 = [1,3]
    
    px1=[int(i) for i in x1]
    py1=[int(i) for i in y1]
    px2=[int(i) for i in x2]
    py2=[int(i) for i in y2]
    px3=[int(i) for i in x3]
    py3=[int(i) for i in y3]
    px4=[int(i) for i in x4]
    py4=[int(i) for i in y4]
    px5=[int(i) for i in x5]
    py5=[int(i) for i in y5]

    r1=randint(px5[0], 8)
    r2=randint(py1[0], py2[1])

    if(r1==px5[0]):
        px6 = [px1[0], px5[0]]
        py6 = [randint(py1[0], py2[1]), py1[0]]
        
    elif(r1==5):
        px6 = [px1[0], 5]
        py6 = [randint(py1[0], py2[1]), py1[0]]

    elif(r1==6):
        px6 = [px1[0], 6]
        py6 = [randint(py1[0], py2[1]), randint(py1[0], py1[1])]
    
    else:
        px6 = [px1[0], px5[1]]
        py6 = [randint(py1[0], py2[1]), randint(py1[0], py2[1])]
        

    print("\nRecta de corte: ", px6[0], py6[0], px6[1], py6[1])
    print("\nSegmentos ordenados que la recta de corte va intersectando:\n\n\t1er Segmento: ", px1[0], py1[0], px1[1], py1[1],"\n\t2do Segmento: ", px2[0], py2[0], px2[1], py2[1],"\n\t4to Segmento: ", px4[0], py4[0], px4[1], py4[1],"\n\t5to Segmento: ", px5[0], py5[0], px5[1], py5[1])
  
    plt.xlabel('Eje de las X') 
    plt.ylabel('Eje de las Y') 
    plt.plot(px1, py1, label ='1er Segmento')
    plt.plot(px2, py2, label ='2do Segmento')
    plt.plot(px3, py3, label ='3er Segmento')
    plt.plot(px4, py4, label ='4to Segmento')
    plt.plot(px5, py5, label ='5to Segmento')
    plt.plot(px6, py6, label ='Recta de corte')
    plt.grid() 
    plt.legend() 
    plt.show()

def Prueba4():
   
    archivo_x1=open("p4x1.txt","r")
    x1=archivo_x1.readlines()
    archivo_x1.close()

    archivo_y1=open("p4y1.txt","r")
    y1=archivo_y1.readlines()
    archivo_y1.close()

    archivo_x2=open("p4x2.txt","r")
    x2=archivo_x2.readlines()
    archivo_x2.close()

    archivo_y2=open("p4y2.txt","r")
    y2=archivo_y2.readlines()
    archivo_y2.close()

    archivo_x3=open("p4x3.txt","r")
    x3=archivo_x3.readlines()
    archivo_x3.close()

    archivo_y3=open("p4y3.txt","r")
    y3=archivo_y3.readlines()
    archivo_y3.close()

    archivo_x4=open("p4x4.txt","r")
    x4=archivo_x4.readlines()
    archivo_x4.close()

    archivo_y4=open("p4y4.txt","r")
    y4=archivo_y4.readlines()
    archivo_y4.close()

    archivo_x5=open("p4x5.txt","r")
    x5=archivo_x5.readlines()
    archivo_x5.close()

    archivo_y5=open("p4y5.txt","r")
    y5=archivo_y5.readlines()
    archivo_y5.close()

    #x1 = [1,3]
    #y1 = [2,2]
    #x2 = [2,4]
    #y2 = [3,4]
    #x3 = [2,5]
    #y3 = [1,1]
    #x4 = [6,8]
    #y4 = [3,3]
    #x5 = [7,9]
    #y5 = [1,3]
    
    px1=[int(i) for i in x1]
    py1=[int(i) for i in y1]
    px2=[int(i) for i in x2]
    py2=[int(i) for i in y2]
    px3=[int(i) for i in x3]
    py3=[int(i) for i in y3]
    px4=[int(i) for i in x4]
    py4=[int(i) for i in y4]
    px5=[int(i) for i in x5]
    py5=[int(i) for i in y5]

    r1=randint(px1[0], 5)
    r2=randint(py2[0], 5)
    r3=randint(px2[0], 10)
    
    if(r1==px2[1]):
        if(r3==px2[0]):
            px6 = [px2[1], px2[0]]
            py6 = [py2[1], py3[0]]
            print("\nRecta de corte: ", px6[0], py6[0], px6[1], py6[1])
            print("\nSegmentos ordenados que la recta de corte va intersectando:\n\n\t2do Segmento: ", px2[0], py2[0], px2[1], py2[1],"\n\t1er Segmento: ", px1[0], py1[0], px1[1], py1[1],"\n\t3er Segmento: ", px3[0], py3[0], px3[1], py3[1])
        else:
            px6 = [px2[1], px5[1]]
            py6 = [py2[1], py1[0]]
            print("\nRecta de corte: ", px6[0], py6[0], px6[1], py6[1])
            print("\nSegmentos ordenados que la recta de corte va intersectando:\n\n\t2do Segmento: ", px2[0], py2[0], px2[1], py2[1],"\n\t4to Segmento: ", px4[0], py4[0], px4[1], py4[1],"\n\t5to Segmento: ", px5[0], py5[0], px5[1], py5[1])
        
    elif(r1==px1[1]):
        if(r3==px5[1]):
            px6 = [px1[1], px5[1]]
            py6 = [py2[1], py1[0]]
            print("\nRecta de corte: ", px6[0], py6[0], px6[1], py6[1])
            print("\nSegmentos ordenados que la recta de corte va intersectando:\n\n\t2do Segmento: ", px2[0], py2[0], px2[1], py2[1],"\n\t4to Segmento: ", px4[0], py4[0], px4[1], py4[1],"\n\t5to Segmento: ", px5[0], py5[0], px5[1], py5[1])
        else:
            px6 = [px1[1], randint(px2[0], px2[1])]
            py6 = [py2[1], py3[0]]
            print("\nRecta de corte: ", px6[0], py6[0], px6[1], py6[1])
            print("\nSegmentos ordenados que la recta de corte va intersectando:\n\n\t2do Segmento: ", px2[0], py2[0], px2[1], py2[1],"\n\t1er Segmento: ", px1[0], py1[0], px1[1], py1[1],"\n\t3er Segmento: ", px3[0], py3[0], px3[1], py3[1])

    elif(r1==px2[0]):
        if(r2==py2[0]):
            px6 = [px2[0], randint(px2[0], 5)]
            py6 = [py2[0], py3[0]]
            print("\nRecta de corte: ", px6[0], py6[0], px6[1], py6[1])
            print("\nSegmentos ordenados que la recta de corte va intersectando:\n\n\t2do Segmento: ", px2[0], py2[0], px2[1], py2[1],"\n\t1er Segmento: ", px1[0], py1[0], px1[1], py1[1],"\n\t3er Segmento: ", px3[0], py3[0], px3[1], py3[1])
        else:
            px6 = [px2[0], randint(px2[0], px2[1])]
            py6 = [py2[1], py3[0]]
            print("\nRecta de corte: ", px6[0], py6[0], px6[1], py6[1])
            print("\nSegmentos ordenados que la recta de corte va intersectando:\n\n\t2do Segmento: ", px2[0], py2[0], px2[1], py2[1],"\n\t1er Segmento: ", px1[0], py1[0], px1[1], py1[1],"\n\t3er Segmento: ", px3[0], py3[0], px3[1], py3[1])
    else:
        px6 = [px1[0], px2[1]]
        py6 = [py2[1], py3[0]]
        print("\nRecta de corte: ", px6[0], py6[0], px6[1], py6[1])
        print("\nSegmentos ordenados que la recta de corte va intersectando:\n\n\t2do Segmento: ", px2[0], py2[0], px2[1], py2[1],"\n\t1er Segmento: ", px1[0], py1[0], px1[1], py1[1],"\n\t3er Segmento: ", px3[0], py3[0], px3[1], py3[1])

                
    plt.xlabel('Eje de las X') 
    plt.ylabel('Eje de las Y') 
    plt.plot(px1, py1, label ='1er Segmento')
    plt.plot(px2, py2, label ='2do Segmento')
    plt.plot(px3, py3, label ='3er Segmento')
    plt.plot(px4, py4, label ='4to Segmento')
    plt.plot(px5, py5, label ='5to Segmento')
    plt.plot(px6, py6, label ='Recta de corte')
    plt.grid() 
    plt.legend() 
    plt.show()
    

def menu():#menú principal

    opcion=input("\tMenu de opciones:\n1.Prueba 1\n2.Prueba 2\n3.Prueba 3\n4.Prueba 4\n5.Salir\nOpcion: ")

    if opcion=="1":

        Prueba1()

    elif opcion=="2":

        Prueba2()

    elif opcion=="3":

        Prueba3()

    elif opcion=="4":

        Prueba4()

    elif opcion=="5":

        print("Programa terminado...")

    else:
        print("\nDigite una opcion correcta...\n")
        menu()
menu()
#Fin del programa
