# ATTiny24a_pausable_walking_lights
This repository is for a project with a ATTiny24a


You can download the .ino files and upload them like the description says.
- attiny_001.ino = Pausable Walking-Lights
- attiny_002.ino = Precision Game

# Description:

# ATTiny24a powered Pausable Walking-Lights

# 1 General:

  The ATTiny24a powered Pausable Walking-Lights project is a unique and interactive LED lighting system designed for
  entertainment  purposes. Here is a detailed description of the features and functionalities of this project:

  Features:


  - ATTiny24a Microcontroller: Controls the operation and behavior of the LED lights and games.

  - Pausable Walking-Lights: Consists of 8 LEDs that light up in a sequence to create a walking-light effect.

  - Pause Button: Allows users to pause the light sequence at any point by pressing the button.

  - Power LED: Indicates when the system is powered on and operational.

  - Pause Status LED: Shows whether the light sequence is currently paused or running.

  - SN74HC595N Shift Register: Provides additional output pins to expand the number of LEDs that can be controlled.
  
  Walking-Lights Mode:
  	The 8 LEDs light up in a sequential pattern, resembling a walking effect.
  	Users can pause the sequence at any point by pressing the pause button.
  	The Pause Status LED indicates whether the sequence is paused or running.

  Interactive Games: The system can be programmed to operate as a game with two modes:
  - Precision Game: Requires the player to pause the light sequence at exactly the right position.
  - Memory Game: Challenges the player to memorize the order of blinking LEDs and replicate it by pressing the button at the
correct moment.


# 2 Programming & Customizing:

# 2.0 Programming Pins

  With the ATTiny24a powered Pausable Walking-Lights project utilizing a DIP IC Base for connectivity, users have the 
  flexibility to customize and program the 8 LEDs, the Pause LED, and the button individually to create their own unique 
  games and lighting effects. Here are some ways users can leverage this customization:

  - Individual LED Control: Users can program each of the 8 LEDs to light up in specific patterns, colors, or timings, 
	  	allowing for a wide range of visual effects.

  - Pause LED Customization: The Pause LED can be programmed to indicate different states or functions within the 
	  	game, such as signaling when a level is completed or when the game is paused.

  - Button Functionality: The button can be programmed to trigger various actions, such as advancing to the next level, 
		  starting a new game, or activating special effects.


  Pins:
  - 0 - Pause LED
  - 1 - Button
  - 2 - dataPin (SN74HC595N)
  - 3 - shiftPin (SN74HC595N)
  - 4 - storePin (SN74HC595N)



#  2.1 Programming the ATTiny24a via Arduino Uno

To program the ATTiny24a using an Arduino as a programmer, follow these steps:

Hardware Connection:

2.1.0 Connect the ATTiny24a pins as follows:
- Pin 1 to 5V+
- - Pin 4 to D10 on the Arduino
- Pin 7 to D11 on the Arduino
- Pin 8 to D12 on the Arduino
- Pin 9 to D13 on the Arduino
- Pin 14 to GND

2.1.1 Setting up Arduino IDE:
- Open Arduino IDE 1.8.x on your computer.
- Load the ArduinoISP example sketch.
- Scroll till you find the line "// #define USE_OLD_STYLE_WIRING" and delete the "/"
- Select your port and the Arduino Uno board in the Arduino IDE.
- Upload.

2.1.2 Installing ATTinyCore:
- Search for AttinyCore on GitHub.
- Copy the link "http://drazzy.com/package_drazzy.com_index.json" (!not made by me!) provided in the installation guide.
- Go to Arduino IDE, navigate to Preferences.
- Paste the copied link in the Additional Board Manager URLs section.
- Close the Preferences window.

 2.1.3 Selecting ATTiny24 Board:
- Go to Tools > Board > Boards Manager.
- Search for ATTinyCore and install the ATTinyCore.
- Select the ATTiny24 board, the ATTiny24 Processor and the correct port in the Tools menu.

2.1.4 Uploading Sketch:
- Set the programmer to Arduino as ISP
- Load your custom sketch for the ATTiny24a in the Arduino IDE.
- Make sure you have the correct ATTiny24 board selected.
- Connect the Arduino Uno to your computer.
- Upload the sketch to the ATTiny24a by selecting Sketch > Upload Using Programmer.


#  2.2 Using the Shiftregister

To use the SN74HC595N shift register, follow these steps:

2.2.0 Understanding the SN74HC595N:
- The SN74HC595N is an 8-bit shift register with a serial-in, parallel-out functionality.
- It allows you to expand the number of output pins of a microcontroller by serially shifting in data 
and then latching the data to the output pins.
- By storing a bit all the stored bits get shifted to the next position to make room for the new bit.
  
2.2.1 Writing Data:
- Set the dataPin to the desired binary value (0 or 1).
- Pulse the shiftPin to shift the data into the register.
- Repeat this process for each bit of data.
	
2.2.2 Latching Data:
- Once all the data is shifted in, pulse the storePin to latch the data to the output pins.
- This action sets the output pins to the values you have shifted in.
