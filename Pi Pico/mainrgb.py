import time
import rgb

rgbObj = rgb.rgb(16,15,0,False)
rgbObj.off()

time_led = 100
count = 0
count2 = 0
while(count2 < 50):
    count2 = count2 + 1
    count = count + 1
    print("Pi Pico W: " + str(count))
    time.sleep_ms(time_led)
    
    if(count > 3):
        count = 0
    if(count == 0):
        rgbObj.red()
    if(count == 1):
        rgbObj.blue()
    if(count == 2):
        rgbObj.green()
    if(count == 3):
        rgbObj.blue()
     
        
    