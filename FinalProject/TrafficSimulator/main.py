import serial
import time


def send_message(arduino_port, baud_rate, message):
    conn = serial.Serial(arduino_port, baud_rate, timeout=1)
    print(message)
    time.sleep(2)
    conn.write(message.encode())
    conn.close()


if __name__ == "__main__":
    arduino_port = "COM3"
    baud_rate = 9600
    timing = 5
    messages = ['1', '2', '3', '4']

    for message in messages:
        send_message(arduino_port, baud_rate, message)
        time.sleep(timing)
