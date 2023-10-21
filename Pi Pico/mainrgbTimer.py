import time
from machine import Timer
import rgb

rgbObj = rgb.rgb(16,15,0,False)
rgbObj.off()

time_led = 300
count = 0

def set_rgb_led():
    global count 
    count = count + 1
    print("Pi Pico W: " + str(count))
    time.sleep_ms(time_led)
    
    if(count > 2):
        count = 0
    if(count == 0):
        rgbObj.red()
    if(count == 1):
        rgbObj.green()
    if(count == 2):
        rgbObj.blue()
        
tim = Timer()
tim.init(period=time_led, mode=Timer.PERIODIC, callback=lambda t:set_rgb_led())

while(True):
     pass
        
    