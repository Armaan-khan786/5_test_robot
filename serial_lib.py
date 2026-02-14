import serial
import time

ser = None


def open_port(port):
    global ser
    print("Opening port:", port)
    ser = serial.Serial(port, 115200, timeout=2)
    time.sleep(3)
    ser.reset_input_buffer()
    print("Port opened successfully")


def send_command(cmd):
    global ser
    if ser is None:
        raise Exception("Serial not opened")

    print("Sending:", cmd)
    ser.write((cmd + "\n").encode("utf-8"))
    ser.flush()
    time.sleep(0.5)


def read_response():
    global ser
    if ser is None:
        raise Exception("Serial not opened")

    response = ser.readline().decode("utf-8", errors="ignore").strip()
    print("Received:", response)
    return response


def close_port():
    global ser
    if ser:
        ser.close()
        print("Port closed")