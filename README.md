
Übersicht



Ich habe ein RFID-Projekt erstellt.

In diesem Projekt zeige ich, wie man ein RFID-RC522-Modul mit einem Arduino anschließt.



Erklärungsvideo: https://youtu.be/aIOdKdzlT2U


<img width="702" height="523" alt="Unbenannt" src="https://github.com/user-attachments/assets/2e914126-824b-46f2-97f9-7b962a260d95" />




Die Projektidee ist ein einfacher Türscanner, wie man ihn in Schulen, Firmen usw. benutzen kann.

Setup







Benötigte Bibliotheken installieren.



#include <SPI.h>

#include <MFRC522.h>

#include <Servo.h>



Build und Ausführung




Ich verwende PlatformIO für dieses Projekt, daher muss es vorher installiert sein.

Öffne anschließend das Projekt und verbinde deinen Arduino. Danach solltest du einfach auf Build und Run klicken können.












