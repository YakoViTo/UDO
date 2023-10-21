# led_server
from ssd1306 import SSD1306_I2C
from easy_comms import Easy_comms
from time import sleep
from machine import Pin, I2C
import json

WIDTH = 128
HEIGHT = 64

i2c = I2C(0, scl=Pin(9), sda=Pin(8), freq=200000)

oled = SSD1306_I2C(WIDTH, HEIGHT, i2c)

command = {'command':'blink', 'args': 'on'}

com1 = Easy_comms(0,9600)
led = Pin(25, Pin.OUT)

while True:
    
    com1.send(str(json.dumps(command)))
    
    oled.fill(0)
    oled.invert(True)
    
    
    if command['args'] == 'on':
       command = {'command':'blink', 'args': 'off'}
       oled.text("send sms: off",4,25)
    else:
       command = {'command':'blink', 'args': 'on'}
       oled.text("send sms: on",4,25)
    led.toggle()
    
    sleep(1)
    oled.show()
