import serial
import time

def send_message(arduino_port, baud_rate,message):
    conn = serial.Serial(arduino_port, baud_rate, timeout=1)
    time.sleep(2)
    conn.write(message)
    conn.close()

if __name__ == "__main__":
    arduino_port = 'COM3'
    baud_rate = 9600 
    timing = 5
    messages = ["HH","HL","LH","LL"]

    for message in messages:
        send_message(arduino_port, baud_rate,message,timing)
        time.sleep(timing)