#include <IRremote.h>

int RECV_PIN = 11;
int led = 9;
IRrecv irrecv(RECV_PIN);
decode_results results;
int parlaklik = 255;

#define yukari 0xF076C13B
#define asagi 0xA3C8EDDB 


void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
  analogWrite(led, parlaklik);
}

void loop() 
  if (irrecv.decode(&results))
  {
    if (results.value == yukari)
      parlaklik = parlaklik + 25;
    if (results.value == asagi)
      parlaklik = parlaklik - 25;
    if (parlaklik >= 250)
      parlaklik = 255;
    if (parlaklik <= 0)
      parlaklik = 0;
    analogWrite(led, parlaklik);
    Serial.println(parlaklik);
    irrecv.resume();
  }
}
