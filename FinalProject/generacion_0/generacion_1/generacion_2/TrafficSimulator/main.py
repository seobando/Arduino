#
import serial
import time
import serial.tools.list_ports

ports = serial.tools.list_ports.comports()

for port in ports:
    print(port)

arduinoData = serial.Serial("/dev/tty.usbmodem11201", 9600)

while True:
    cmd = input("Please Enter Your Command: ")
    cmd = cmd + "\r"
    arduinoData.write(cmd.encode())
