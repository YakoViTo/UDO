import urequests
from machine import Pin
import time


btn = Pin(17, Pin.IN, Pin.PULL_UP)
count = 0

def http_get(path: str):
    try:
        url = 'http://192.168.4.1/?'+path
        response = urequests.get(url)   
        response.close()
    except Exception as e:
        print(e)

def set_rgb_led(pin):
    
    global count
    count = count + 1
    print("Pi Pico W: " + str(count))  
    if(count > 2):
        count = 0
    if(count == 0):
        http_get("led-r")
    if(count == 1):
       http_get("led-g")
    if(count == 2):
        http_get("led-b")

    time.sleep_ms(100)

btn.irq(handler=set_rgb_led, trigger=Pin.IRQ_FALLING)

while(1):
    pass