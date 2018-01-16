#include <HCMAX7219.h>
#include "SPI.h"
#define LOAD 10

HCMAX7219 HCMAX7219(LOAD);



void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

}
void loop() {
  // put your main code here, to run repeatedly:
   int c = analogRead(A0);
   c=c-348; 
   
   // delta v = 0.38v
   // 38 ohm pe 100 grade
   
  /* Clear the output buffer */
  HCMAX7219.Clear();
  Serial.println(c);
  delay(500);
  /* Write some text to the output buffer */
 HCMAX7219.print7Seg(c,8);
  // printare ANalogRead  HCMAX7219.print7Seg(pt100,8);
    HCMAX7219.print7Seg("Ce",1);
  /* Send the output buffer to the display */
  HCMAX7219.Refresh();  
  

delay(400);
}
