#Requires pyserial and json library.
import serial
import time
import json
arduino = serial.Serial(port='COM21', baudrate=115200, timeout=.1) #Initiating Serial link.

while True: #Loop Forever
    for i in range(0,33): #Left to Right 
        message = json.dumps({'R'+str(i): 200, 'fadeall':180}) #Turn on a LED and gradually fade out every other ones.
        arduino.write(bytes(message, 'utf-8'))
        time.sleep(0.05)
    for i in range(32,-1, -1): #Right to Left
        message = json.dumps({'R'+str(i): 200, 'fadeall':180}) #Turn on a LED and gradually fade out every other ones.
        arduino.write(bytes(message, 'utf-8'))
        time.sleep(0.05)