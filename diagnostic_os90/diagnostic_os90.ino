/**
 * Used for chromeOS version 90 with sideways camera and thin window 
 * without "Chromebooke managed..." message on login page.
 * 
 * Author: Ian Nostrant
 * Date: 2/28/22
 */

#include <Keyboard.h>
#include <Chrome_Key_Coms.h>

void setup() {
  Keyboard.begin();
  delay(10000); //gives time to erase the script when testing
}

void loop() {
  /**selects 'add person' and waits for window
  tabMultiplier(5);
  Keyboard.write(KEY_RETURN);
  delay(5000);
  */
  
  //user ID
  Keyboard.println("username");
  delay(10000);

  //user password
  Keyboard.println("password");
  delay(20000); //wait for pc to load

  //open crosh and run battery_test 1
  batteryTest();

  //camera/mic  test: open, record, and view
  testCamera(2,10000,1);

  //leave on search to test keyboard manually
  Keyboard.write(KEY_LEFT_GUI);
  delay(30000);

  //logout user ctrl+shift+q (twice)
  logout();

  //remove account
  Keyboard.write(KEY_TAB);
  delay(1000);
  Keyboard.write(KEY_RETURN);
  delay(1000);
  Keyboard.write(KEY_RETURN);
  delay(1000);
  Keyboard.write(KEY_RETURN);
  delay(10000);

  // terminates program so it only runs once
  exit(0);
}
