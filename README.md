## Quickstart Arduino Mac (& Windows)  
### install Arduino Software 
Download and install Arduino IDE (not the online IDE/web editor) https://www.arduino.cc/en/Main/Software 
MAC: Move the file  ‘Arduino’ to ‘Apps’  
Start Arduino from Applications  

### Set UI to Englisch 
To be more inline with documentation here and online 
Go to 'Arduino' → ' Preferences  
Pick “Editor language:” use ‘english’ 
Connect board (USB cable) and select board: Arduino MICRO from the dropdown. You should see the port: /dev/cu.usbmodem*** or simular (Windows = Com port) 
(if your board )

### Upload your code
File → examples→ Basic → Blink 
Compile and upload: you can use  ‘Command - U'  
If you see 'Done uploading' it worked!  

### Blink code adjustment 
The blue led on the board is blinking (1 second/1 second) 
Change the frequency of the blinking led in the code, upload again. Can you see the difference?  

 
## Install/remove a Library  

Open Arduino 
Go to Tools > Manage Libraries 
Search for “Grove Ultrasonic ranger” 
Install and close Library management’ 
Go to File > Examples and check if the “Grove Ultrasonic Ranger” is installed. 

Remove: Go to 'Arduino' → ' Preferences . You will find the 'Sketchbook location' Open en find the location of the Libraries
Remove using finder. (normaly are the libs in Documents/Arduino/Libraries)

## Fixing errors
There are two kinds of errors:
- Errors connecting with USB (happens to much)
- Errors in code

Upload an empy sketch (press command+n) and (command+u). If uploading fails it is port/USB/connection problem.

#### Connection (USB/port) problems
- Select the board and select the port
    -  Not possible? Use another (physical) USB port on your laptop
    - Use another cable
    - Use another Arduino
- The Arduino and port are available
    - Use the blink code
    
