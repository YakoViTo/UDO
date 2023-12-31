from machine import Pin, I2C
from time import sleep_ms
from ssd1306 import SSD1306_I2C
import framebuf

WIDTH = 128
HEIGHT = 64

MODO_MAX = 5
global modo
global contador
modo = 0
contador = 0

boton = Pin(16, Pin.IN, Pin.PULL_DOWN)
i2c = I2C(0, scl=Pin(9), sda=Pin(8), freq=200000)
oled = SSD1306_I2C(WIDTH, HEIGHT, i2c)

def boton_interrupt(pin):
    global modo
    global contador
    
    if boton.value():
        modo += 1
        print(modo)
        
    if modo > MODO_MAX:
        modo = 0
        contador = 0

boton.irq(trigger=Pin.IRQ_RISING, handler=boton_interrupt)

while True:
    oled.fill(1)
    
    if modo == 0:
        oled.text("Bienvenidos", 0, 0)
        oled.text("Prueba de texto", 0, 16)
        oled.text("Like", 30, 32)
        
    elif modo == 1:
        oled.text("Variables", 0, 0)
        oled.text("Contando:", 10, 32)
        oled.text(str(contador), 90, 32)
        oled.show()
        sleep_ms(1000)
        contador += 1
        
    elif modo == 2:
        for i in range(0, 63, 8):
            oled.hline(0, i, 127, 1)
            
    elif modo == 3:
        for i in range(0, 127, 8):
            oled.vline(i, 0, 63, 1)
            
    elif modo == 4:
        oled.rect(10, 10, 40, 20, 1)
        oled.rect(60, 30, 50, 20, 1)
        
    elif modo == 5:
        oled.fill_rect(10, 10, 40, 20, 1)
        oled.fill_rect(60, 30, 50, 20, 1)
        oled.fill_rect(62, 32, 20, 10, 0)
        oled.fill_rect(87, 38, 20, 10, 0)
    
    oled.show()