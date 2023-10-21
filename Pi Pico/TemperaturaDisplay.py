from machine import Pin, I2C
from ssd1306 import SSD1306_I2C
import framebuf
import machine
import utime

sensor_temp = machine.ADC(4)
conversion_factor = 3.3 / (65535)

WIDTH = 128
HEIGHT = 64

i2c = I2C(0, scl=Pin(9), sda=Pin(8), freq=200000)

print("I2C Address: "+hex(i2c.scan()[0]).upper())
print("I2C Coniguration: "+str(i2c))

oled = SSD1306_I2C(WIDTH, HEIGHT, i2c)

buffer = bytearray(b"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00|?\x00\x01\x86@\x80\x01\x01\x80\x80\x01\x11\x88\x80\x01\x05\xa0\x80\x00\x83\xc1\x00\x00C\xe3\x00\x00~\xfc\x00\x00L'\x00\x00\x9c\x11\x00\x00\xbf\xfd\x00\x00\xe1\x87\x00\x01\xc1\x83\x80\x02A\x82@\x02A\x82@\x02\xc1\xc2@\x02\xf6>\xc0\x01\xfc=\x80\x01\x18\x18\x80\x01\x88\x10\x80\x00\x8c!\x00\x00\x87\xf1\x00\x00\x7f\xf6\x00\x008\x1c\x00\x00\x0c \x00\x00\x03\xc0\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00")

while True:
    reading = sensor_temp.read_u16() * conversion_factor
    temperature = round(27 - (reading - 0.706)/0.001721,2)
    fb = framebuf.FrameBuffer(buffer, 32, 32, framebuf.MONO_HLSB)

    oled.fill(0)

    oled.blit(fb, 96, 34)
    
    oled.invert(True)
    
    oled.text("TEMPERATURE",16,8)
    oled.text(str(round(temperature,2)),40,25)

    oled.show()