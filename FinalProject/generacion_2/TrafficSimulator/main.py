#
import serial
import time

arduinoData = serial.Serial("com3", 9600)

while True:
    cmd = input("Please Enter Your Command: ")
    cmd = cmd + "\r"
    arduinoData.write(cmd.encode())
