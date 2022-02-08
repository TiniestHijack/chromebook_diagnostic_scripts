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
  Keyboard.println("example@school.net");
  delay(10000);

  //user password
  Keyboard.println("password");
  delay(20000); //wait for pc to load

  //open crosh and run battery_test 1
  batteryTest();

  //camera/mic  test: open, record, and view
  testCamera();

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

  //turn off laptop
  tabMultiplier(3);
  Keyboard.write(KEY_RETURN);
  Keyboard.end();

  // terminates program so it only runs once
  exit(0);
}
