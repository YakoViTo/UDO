from machine import Pin
import rgb

btn = Pin(19, Pin.IN, Pin.PULL_UP)

rgbObj = rgb.rgb(16,15,2,False)
rgbObj.off()
count = 0

def set_rgb_led(pin):
    global count
    count = count + 1
    print("Pi Pico W: " + str(count))
    if(count > 2):
        count = 0
    if(count == 0):
        rgbObj.red()
    if(count == 1):
        rgbObj.green()
    if(count == 2):
        rgbObj.blue()
        
btn.irq(handler=set_rgb_led, trigger=Pin.IRQ_FALLING)

while(True):
    pass
     
        
    