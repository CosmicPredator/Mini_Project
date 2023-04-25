import serial
import time
import speech_recognition as sr

print(serial.__version__)

ser = serial.Serial(
    "COM6", 
    9600, 
    parity=serial.PARITY_NONE, 
    stopbits=serial.STOPBITS_ONE, 
    bytesize=serial.EIGHTBITS
)

r = sr.Recognizer()

while True:
    with sr.Microphone() as source:
        print("Speak now...")
        audio = r.listen(source)
    try:
        # command = r.recognize_houndify(audio
        #                                ,client_id="TOcJqPxHBvJU9kiLPQK79g==",
        #                                client_key="wtjBRYin9w3FqtZ-66KA2p24R0sAC3BS-mElN5oubnrC1U8F7xs2JnqLTAN9nseqshXqGKPy5nKmT94O3np8sw==")
        command = r.recognize_google(audio, language="en-US", pfilter=2)
        print("You said:", command)
        if command.__contains__("open"):
            ser.write(b'O')
        if command.__contains__("close"):
            ser.write(b'C')
        if command.__contains__("left"):
            ser.write(b'L')
        if command.__contains__("right"):
            ser.write(b'R')
        if command.__contains__("home"):
            ser.write(b'H')
    except sr.UnknownValueError:
        print("Sorry, I didn't understand what you said.")
    except sr.RequestError:
        print("Sorry, I couldn't connect to the speech recognition service.")