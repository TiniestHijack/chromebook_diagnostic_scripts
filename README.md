# Chromebook Diagnostic Scripts
Some keystroke mimicking scripts for Arduino IDE that run general diagnostics on chromebooks automatically (battery, camera, mic, keyboard)

# Basic Instructions
1. Download as zip or clone the repository
2. Insert the Chrome_Key_Coms folder into the **Documents/Arduino/libraries** directory on your computer
3. Open the diagnostic.ino folder of your choice in the diagnostic folder with Arduino IDE
4. Plug in your board (I used a pro micro) and upload the code. Make sure you pick the right COM port!
5. After uploading, turn on your chromebook and select the add user button. Confirm the cursor is blinking in the enter username box and plug in your board, then just let it run!

# Code Context
You will likely have to make changes to some of the delays and commands depending on what machine you're using, how quickly it operates, and what version of chromeOS it's using.

This diagnostic tool assumes your are a system administrator logging into your account to troubleshoot a malfunctioning student or worker computer.

# Troubleshooting
The code should be easily understood, most of the key combinations are in the Chrome_Key_Coms library in the .cpp file. If you need a reference for key commands then check out the Arduino Keyboard and Mouse libraries. 

Some basic key commands can be found here: https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardmodifiers/

**ChromeOS Version:** If you are unsure of your version of chromeOS, sign in and go to the settings in the lower right hand corner. Then in the left hand side of the settings window, click on about ChromeOS and it'll be on that page.

**Video Viewer Issue:** There is a version of chromeOS where when you open the gallery app after taking a test video to view it, there are more buttons to tab through so you'd have to change the tabMultiplier setting in the Chrome_Key_Coms.cpp file to 9 instead of 1 (there is a comment there as well). 
