#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN);
Servo myServo;

int servoPin = 7;
int piezopin = 6;

// Erlaubte RFID-Karte
byte allowedUID[4] = {0x33, 0xDF, 0x6D, 0xE2};


void setup()
{
    Serial.begin(9600);
    SPI.begin();
    rfid.PCD_Init();

    myServo.attach(servoPin);
    myServo.write(0);

    pinMode(piezopin, OUTPUT);

    pinMode(5, OUTPUT);   // Grün LED
    pinMode(6, OUTPUT);   // Rot LED

    Serial.println("RFID Access Control bereit...");
}


void loop()
{
    // Warten auf neue Karte
    if (!rfid.PICC_IsNewCardPresent()) 
        return;

    if (!rfid.PICC_ReadCardSerial()) 
        return;

    Serial.print("Karte erkannt. UID: ");

    bool match = true;

    // UID vergleichen
    for (byte i = 0; i < rfid.uid.size; i++)
    {
        Serial.print(rfid.uid.uidByte[i], HEX);
        Serial.print(" ");

        if (rfid.uid.uidByte[i] != allowedUID[i])
        {
            match = false;
        }
    }
    Serial.println();


    // Entscheidung
    if (match)
    {
        Serial.println("ZUGRIFF ERLAUBT!");

        digitalWrite(5, HIGH);   // Grün
        digitalWrite(6, LOW);    // Rot aus

        myServo.write(90);       // Öffnen
    }
    else
    {
        Serial.println("ZUGRIFF VERWEIGERT!");

        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);   // Rot ein

        tone(piezopin, 400, 200);
    }


    // Karte abmelden
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();

    delay(1500);

    // Servo zurücksetzen
    myServo.write(0);
}
