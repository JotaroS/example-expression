/* Sweep
  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 8 Nov 2013
  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo innerservo, outerservo; // create servo object to control a servo
// twelve servo objects can be created on most boards

int posi = 0, poso = 0;  // variable to store the servo position
unsigned char expression;
int veci = 0, veco = 0;
int H ;
int R , G , B ;

void setup() {
  innerservo.attach(9);  // attaches the servo on pin 9 to the servo object
  outerservo.attach(10);
  Serial.begin(9600);
}

void loop() {
  while (Serial.available()) {
    expression = Serial.read();
  }
  switch (expression) {
    case 0://none
      posi = posi;
      poso = poso;
      break;

    case 1://smile
      if (0 <= posi && posi <= 180 && veci == 0) { // goes from 0 degrees to 180 degrees
        posi = posi + 1; // in steps of 1 degree
        innerservo.write(posi);              // tell servo to go to position in variable 'pos'
        delay(15 + abs(90 - posi));// waits 15ms for the servo to reach the position
        if (posi == 180)veci = -1;
      }
      else {
        posi = posi - 1; // in steps of 1 degree
        innerservo.write(posi);              // tell servo to go to position in variable 'pos'
        delay(15 + abs(90 - posi));// waits 15ms for the servo to reach the position
        if (posi == 0)veci = 0;
      }
      if (0 <= poso && poso <= 180 && veco == 0) { // goes from 0 degrees to 180 degrees
        poso = poso + 1; // in steps of 1 degree
        outerservo.write(poso);              // tell servo to go to position in variable 'pos'
        delay(15 + abs(90 - poso));// waits 15ms for the servo to reach the position
        if (poso == 180)veco = -1;
      }
      else {
        poso = poso - 1; // in steps of 1 degree
        outerservo.write(poso);              // tell servo to go to position in variable 'pos'
        delay(15 + abs(90 - poso));// waits 15ms for the servo to reach the position
        if (poso == 0)veco = 0;
      }

      /* HSVのH値を0-360で回します */
      for (H = 0 ; H <= 360 ; H++) {
        /* HSVのH値を各ＬＥＤのアナログ出力値(0-255)に変換する処理 */
        if (H <= 120) {
          /* H値(0-120) 赤-黄-緑     */
          R = map(H, 0, 120, 255, 0) ; // 赤LED R←→G
          G = map(H, 0, 120, 0, 255) ; // 緑LED G←→R
          B = 0 ;
        } else if (H <= 240) {
          /* H値(120-240) 緑-水色-青 */
          G = map(H, 120, 240, 255, 0) ; // 緑LED G←→B
          B = map(H, 120, 240, 0, 255) ; // 青LED B←→G
          R = 0 ;
        } else {
          /* H値(240-360) 青-紫-赤   */
          B = map(H, 240, 360, 255, 0) ; // 青LED B←→R
          R = map(H, 240, 360, 0, 255) ; // 青LED R←→B
          G = 0 ;
        }
        /* ＲＧＢＬＥＤに出力する処理   */
        analogWrite(3, R) ;               // 　９番ピンから赤LEDの出力
        analogWrite(5, G) ;              // １１番ピンから緑LEDの出力
        analogWrite(6, B) ;              // １０番ピンから青LEDの出力
        delay(100) ;
      }
      break;

    case 2: //mouth opened

      break;

    case 3: //angry
      break;

    case 4: //sadness
      break;

    case 5: //eye closed
      break;

    case 6: //eyebrow raised
      break;

    default:
      
      break;
  }

}

