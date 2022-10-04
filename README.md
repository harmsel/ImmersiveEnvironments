# Immersive Environments - index
* [Quickstart: install en first test](#quickstart)
* [Connect sensors](#connect)
* [Library install and removal](#libraries)
* [Fixing errors](#errors)
* [Make Madmapper & Ableton interactive using sensors](MIDI-Madmapper-ableton.md)

### <a id="connect"></a> Connecting sensors & Actuators
### Arduino MICRO
![](images/micro.jpg)

### Arduino Pro Micro
![](images/proMicro.png)

In the code you will find annotations how to connect the sensor

| Name | Sensor   | Function   |
| :---:   | :---: | :---: |
| Distance sensor| ![Afstand sensor](https://m.media-amazon.com/images/I/51ugwbd5ynL._SL160_.jpg)  | Uses an ultrasonic signal check code how to connect this. |
| Led Strip | ![](images/ledstrip.png)   | Every led can be programmed individually in all RGB colors |
| Lightsensor | ![](images/licht.png) | Measures light|
| Temp. en Humidity | ![](images/temphu.png)   | Measures Humidity and Temperature|
| Press button | ![](images/ledknop.png)    | Looks different, beware, press button is a complex sensor (debounce problems) |
| Accelerometer - Bewegingsmeter 16g | ![](images/acceler16.png)  | You cam measure angle, movement, motion (speed of movement). It is the same sensor as used in your mobile phone.
| Servo | ![](https://silicio.mx/media/catalog/product/cache/1/small_image/195x195/5e06319eda06f020e43594a9c230972d/r/o/rob08211p/Grove---Servomotor-21.jpg) | You can rotate the servo in every angle, from 5 to 170 degrees   |
| Vibration | ![](images/tril.png) | You can give feedback with vibrations. Simular to your phone vibrations. But used in a box you can make sounds using this sensor|



# <a id="libraries"></a>Install/remove a Library  
* Arduino → Tools > Manage Libraries -> Search for “name of the lib” 
* Remove: Go to 'Arduino' → ' Preferences . You will find the 'Sketchbook location' Open en find the location of the Libraries
* Remove (delete) using finder. Normaly are the libs in Documents/Arduino/Libraries

## <a id="errors"></a>Fixing errors
There are two kinds of errors:

1. USB/port problems (this is 'normal' 😫)
2. Errors in code

#### USB/port problem or Code error?

1. Unplug all sensors (or the ground wire to the sensors)
- Upload an empy sketch (press command+n) and (command+u). 
- Still an error while uploading? **= USB/port problem**

#### USB/port problem - Fix
1. Don't try to upload if the Board and port are not selected (Like image below) it is useless and thus frustrating
- Press the button on the Micro (LED starts fading in/out)
- Wait till fading stops
- Select the board and select the port (in the Arduino IDE)
	1. Board and Port not visible in the dropdown? 
		- Use another (physical) USB port on your laptop, use another cable, try another Arduino
- Upload again 🤞

This is what we would like to see (port name could be a bit different. Windows = Com#)
![](images/boardPortSelected.png)


## <a id="quickstart"></a> Quickstart Arduino Mac (& Windows)
### install Arduino Software 
1. Download and install Arduino IDE (not the online IDE/web editor) https://www.arduino.cc/en/Main/Software 
- MAC: Move the file  ‘Arduino’ to ‘Apps’  
- Start Arduino IDE from 'Applications'  
- To be more inline with documentation here and online: 
- Go to 'Arduino' → ' Preferences  
- Pick “Editor language:” use ‘English’


### Check if it all works (you can use this in the future too)
1. Connect board (USB cable)
- select board: Arduino MICRO from the dropdown. You should see the port: /dev/cu.usbmodem*** or simular (Windows = Com port) 
- File → examples→ Basic → Blink 
- Compile and upload: you can use  ‘Command - U'  
- If you see 'Done uploading' and a blinking LED on the Micro, it works!  

    

    