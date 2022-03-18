#include "chrome_key_coms.h"
#include <Keyboard.h>

void tabMultiplier(int count) {
  for(int i =0; i < count; i++) {
    Keyboard.write(KEY_TAB);
    delay(50); //needed to not overload computer
  }
}

void blink(int count) {
  int RXLED = 17; // The RX LED for blink debugging
  pinMode(RXLED, OUTPUT);  // Set RX LED as an output

  for(int i = 0; i < count; i++) {
    digitalWrite(RXLED, HIGH);    // set the RX LED OFF
    TXLED1; //TX LED macro to turn LED ON
    delay(1000);  
    
    digitalWrite(RXLED, LOW);   // set the RX LED ON
    TXLED0; //TX LED is not tied to a normally controlled pin so a macro is needed, turn LED OFF
    delay(1000);              // wait for a second
  }
}

void openCrosh() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('t');
  Keyboard.releaseAll();
  delay(15000);
}

void batteryTest() {
  openCrosh();
  Keyboard.println("battery_test 1");
  delay(10000); //wait for user to view 
}

void testCamera(int openGal, int waitGal, int toPlay) {
  //open camera app
  Keyboard.write(KEY_LEFT_GUI); //search key
  delay(2000);
  Keyboard.print("camera");
  delay(1000);
  Keyboard.write(KEY_RETURN);
  delay(15000); //wait to load and for popup to disappear
  
  //create a short recording to test
  Keyboard.write(KEY_TAB);
  delay(1000);
  Keyboard.write(KEY_LEFT_ARROW);
  delay(3000);
  tabMultiplier(6);
  delay(500);
  Keyboard.write(KEY_RETURN);
  delay(5000); //time to make a noise!
  Keyboard.write(KEY_RETURN);
  delay(waitGal);

  //view recording
  tabMultiplier(openGal);
  Keyboard.write(KEY_RETURN);
  delay(5000);
  tabMultiplier(toPlay); // either 1 or 9 based on chromeOS version
  Keyboard.write(KEY_RETURN);
  delay(5000);
}

void powerwash() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(1000);
}

void powerwashConfOld() {
  // clicks through first screen
  Keyboard.write(KEY_TAB);
  delay(100);
  Keyboard.write(KEY_TAB);
  delay(100);
  Keyboard.write(KEY_RETURN);
  delay(500);
  
  // clicks through confirmation screen
  Keyboard.write(KEY_TAB);
  delay(100);
  Keyboard.write(KEY_TAB);
  delay(100);
  Keyboard.write(KEY_RETURN);
}

void networkSelect() {
  // begins setup and selects network
  Keyboard.write(KEY_RETURN);
  delay(10000); //wait for SSID's to load
  //Keyboard.write(KEY_TAB); //pennfield_guest will appear on top
  //delay(1000);
  Keyboard.write(KEY_RETURN);
  delay(10000); //wait for terms of service to load
}

void acceptTerms(int count) {
  //loop to click through terms of service and land on enter
  tabMultiplier(count); //0, 97, or 98
  Keyboard.write(KEY_RETURN);
  delay(5000); //wait for splash screen
}

void finishPowerwash() {
  //click on splash page if it appears, if not
  //machine will update, enroll, and stop at final page
  Keyboard.write(KEY_TAB);
  delay(1000);
  Keyboard.write(KEY_RETURN);
  //wait for enrollment and click through to sign-in page
  delay(30000);
  Keyboard.write(KEY_TAB);
  delay(500);
  Keyboard.write(KEY_RETURN);
}

void logout() {
  //logout user ctrl+shift+q (twice)
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.write('q');
  delay(500);
  Keyboard.write('q');
  Keyboard.releaseAll();
  delay(15000);
}