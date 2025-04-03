#include <SD.h>
#include <SPI.h>
#include <TMRpcm.h>

// Chip Select pin for SD card
const int chipSelect = 10;

// Initialize TMRpcm object
TMRpcm ad;



void setup() {
  // Start serial communication
  Serial.begin(9600);
  pinMode(8, INPUT_PULLUP);
  while (!Serial) {
    ; // Wait for serial port
  }

  // Set speaker pin (must be a PWM pin: D3, D5, D6, D9, D10, D11 on Nano)
  ad.speakerPin = 9; // Change if you used a different pin

  Serial.print("Initializing SD card...");
  if (!SD.begin(chipSelect)) {
    Serial.println("SD card failed, or not present");
    while (1); // Halt if SD fails                                         
  }
  ad.quality(1); 
  ad.volume(7);

}



void loop() {
  // Audio plays in the background; add logic here if needed

  if (digitalRead(8) == LOW){
    int randomTrack = random(1, 101);  // Generate random number between 1 and 100
    char filename[7];
    sprintf(filename, "%d.wav", randomTrack);
    ad.play(filename);
    Serial.println(filename);
    delay(2000);                                                                                                                     
    }
}
