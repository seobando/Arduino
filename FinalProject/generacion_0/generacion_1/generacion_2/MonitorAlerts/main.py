import serial
from flask import Flask, jsonify

app = Flask(__name__)

# Change this to the appropriate serial port (e.g., COM3 on Windows, /dev/ttyUSB0 on Linux)
SERIAL_PORT = '/dev/ttyUSB0'
# Change this to the baud rate of your Arduino
BAUD_RATE = 9600

# Initialize the serial connection
ser = serial.Serial(SERIAL_PORT, BAUD_RATE)

# Route to handle GET requests
@app.route('/')
def get_serial_data():
    # Read a line from the serial port
    serial_data = ser.readline().decode().strip()
    # Check if the line starts with "Alert!"
    if serial_data.startswith('Alert!'):
        # Return the data as JSON
        return jsonify({'data': serial_data})
    else:
        # Return an empty response if the line does not start with "Alert!"
        return '', 204
    
if __name__ == '__main__':
    app.run(debug=True)
