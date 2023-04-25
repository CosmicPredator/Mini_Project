import speech_recognition as sr

# create a recognizer object
r = sr.Recognizer()

# use the default microphone as the audio source
with sr.Microphone() as source:
    print("Speak now...")
    # listen for speech and store it as an audio object
    audio = r.listen(source)

try:
    # recognize speech using Google Speech Recognition
    command = r.recognize_google(audio, language="en-IN")
    print("You said:", command)
except sr.UnknownValueError:
    print("Sorry, I didn't understand what you said.")
except sr.RequestError:
    print("Sorry, I couldn't connect to the speech recognition service.")