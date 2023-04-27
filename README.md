# ESP32_BTKeyboard
Programmable BT keyboard 

This is quick and easy code for esp32 to operate as a programmable bt keyboard.

Usage:

1. open arduino file in arduino ide, configure pins and upload project
2. connect esp32 to pc and open configurator (.exe file) 
3. Search ports, select port, select key (1-8) and select function to key. You can use up to 3key makro to one key on keyboard
4. click program (if everything went ok you should be able to hear a duck sound, if not program will exit that means you made a mistake configuring)
5. good luck 

ALTERNATIVE

As you can see in .ino file there is a function buttonConf which is overloaded :

void buttonConf(String S1, String S2);

void buttonConf(String S1, String S2, String S3);

void buttonConf(String S1, String S2, String S3, String S4);

.exe file is just a simple serial coding program. You dont have to use it, but it makes life easier for 'end user'. Alternatively you can just open any terminal and use this:

A B C D   !IMPORTANT! use space between fields

A=number of key (1-8, mandatory)
B= sign to be assigned to a key on keyboard (mandatory)
C,D = same as B. (not mandatory)

example:
1 e ->1st key will be read as 'e' letter
1 KEY_LEFT_CTRL c -> 1st key will be read as ctr+c makro

All possible keys are listed in .ino file in definicje function. 
