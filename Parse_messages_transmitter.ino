#include <stdio.h>
#include <string.h>

struct header {
  char command[16]; /* for storing keywords such as Buzzer, LED, Motor, etc.*/
  char stat[8];   /* for storing On and Off */
};

struct header hdr;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {

  memset(hdr.command, 0, 16);
  memset(hdr.stat, 0, 8);
  
  strncpy(hdr.command, "Buzzer", 6);
  strncpy(hdr.stat, "On", 2); 

  Serial.println(hdr.command);
  Serial.println(hdr.stat);
  
  delay(1000);
  
  memset(hdr.command, 0, 16);
  memset(hdr.stat, 0, 8);
  
  strncpy(hdr.command, "LED", 3);
  strncpy(hdr.stat, "Off", 3);

  Serial.println(hdr.command);
  Serial.println(hdr.stat);

  delay(1000);
}
