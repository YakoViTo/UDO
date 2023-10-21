import machine
import utime
from machine import Pin

# Define SPI pins
sck = machine.Pin(2, machine.Pin.OUT)
mosi = machine.Pin(3, machine.Pin.OUT)
miso = machine.Pin(4, machine.Pin.IN)
cs = machine.Pin(5, machine.Pin.OUT)

# Configure SPI interface
sck.value(0)
mosi.value(0)
cs.value(1)
utime.sleep(0.5)
#a = 120 # 01111000
#a = 84 # 00101010
a = 72 # 01001000
arreglo = ''

# Send data to the slave
cs.low()

for bit in range(8):
    sck.high()
    c = bin(a)
    byte = int(c,2)
    r = (byte >> bit) & 1
    print("Enviando: "+str(r))
    mosi.value(r)
    utime.sleep(1.35)
    arreglo = arreglo + str(r)
    sck.low()
cs.high()
#Finaliza
print("Final,", arreglo)
cs.value(0)



