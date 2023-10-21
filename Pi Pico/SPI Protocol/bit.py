import time

a = 72
b = 2
byte = 0b11011010

for i in range(8):
    c = bin(a)
    byte = int(c,2)
    bit = (byte >> i) & 1
    resultado = c[2::]
    print(bit)

    #print(resultado)
    time.sleep(1)