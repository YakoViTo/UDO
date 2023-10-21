
try:
  import usocket as socket
except:
  import socket

from machine import Pin
import network

import gc
gc.collect()

ssid = 'Viking'
password = '&@M0_e1_c@F3_C0N_1ecH3&'

station = network.WLAN(network.STA_IF)

station.active(True)
station.connect(ssid, password)

while station.isconnected() == False:
  pass

print('Connection successful')
print(station.ifconfig())

led = Pin("LED", Pin.OUT)
led.on()