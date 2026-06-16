import socket

FLAG = "01111110"
ESC = "011111110"

def bit_stuff(data):
    stuffed = ""
    count = 0
    for bit in data:
        stuffed += bit
        if bit == '1':
            count += 1
            if count == 5:
                stuffed += '0'   # Stuff a 0 after 5 consecutive 1s
                count = 0
        else:
            count = 0
    return stuffed

def byte_stuff(data):
    stuffed = ""
    i = 0
    while i < len(data):
        # Check for FLAG or ESC sequences
        if data[i:i+len(FLAG)] == FLAG or data[i:i+len(ESC)] == ESC:
            stuffed += ESC + data[i:i+len(FLAG)]
            i += len(FLAG)
        else:
            stuffed += data[i]
            i += 1
    return stuffed

def sender():
    data = "011111011111110111110"
    bit_stuffed = bit_stuff(data)
    byte_stuffed = byte_stuff(bit_stuffed)

    frame = FLAG + byte_stuffed + FLAG
    print("Sender sending frame:", frame)

    s = socket.socket()
    s.connect(('localhost', 9999))
    s.send(frame.encode())
    s.close()

if __name__ == "__main__":
    sender()
