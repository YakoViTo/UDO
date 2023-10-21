from machine import Pin, ADC
import utime

xAxis = ADC(Pin(27))
yAxis = ADC(Pin(26))

led_left = Pin(22, Pin.OUT)
led_left2 = Pin(6, Pin.OUT)
led_middle = Pin(28, Pin.OUT)
led_right = Pin(21, Pin.OUT)
led_right2 = Pin(20, Pin.OUT)
led_up = Pin(1, Pin.OUT)
led_up2 = Pin(0, Pin.OUT)
led_down = Pin(18, Pin.OUT)
led_down2 = Pin(16, Pin.OUT)

while True:
    xValue = xAxis.read_u16()
    yValue = yAxis.read_u16()
    
    totalValue = xValue + yValue/2
    
    xStatus = "middle"
    yStatus = "middle"
    
    led_left.value(0)
    led_left2.value(0)
    led_down.value(0)
    led_down2.value(0)
    led_up.value(0)
    led_up2.value(0)
    led_right.value(0)
    led_right2.value(0)
    led_middle.value(1)
        
    if totalValue <= 20000:
        yStatus = "up"
        led_up.value(1)
        led_up2.value(1)
        led_middle.value(0)
        
    if totalValue >= 80000:
        yStatus = "down"
        led_down.value(1)
        led_down2.value(1)
        led_middle.value(0)
        
    if totalValue >=30000 and totalValue <= 45000:
        xStatus = "right"
        led_right.value(1)
        led_right2.value(1)
        led_middle.value(0)
        
    if totalValue >= 60000 and totalValue <= 75000:
        xStatus = "left"
        led_left.value(1)
        led_left2.value(1)
        led_middle.value(0)

    print(totalValue, " X: " + xStatus + ", Y: " + yStatus)
    utime.sleep(0.2)