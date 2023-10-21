import machine
import utime
from machine import Pin

# Define SPI pins
sck = machine.Pin(2, machine.Pin.IN)
mosi = machine.Pin(4, machine.Pin.IN)
miso = machine.Pin(3, machine.Pin.OUT)
cs = machine.Pin(5, machine.Pin.IN)

# Configure SPI interface
sck.value(0)
miso.value(0)

# Wait for master to initiate communication
while True:
    if (cs.value() == 0):
        print("Esperando")
        utime.sleep(1)
    else:
        break

# Read data from the master
arreglo = ''
byte = 0
for bit in range(8):
    byte = mosi.value()
    print("Recibe: " +str(byte))
    sck.high()
    utime.sleep(1.55)
    arreglo = arreglo + str(byte)   
    sck.low()
print(arreglo)