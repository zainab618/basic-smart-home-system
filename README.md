# basic-smart-home-system
this project implements a smart home system using both manual & Bluetooth control for appliances, along with efficient task scheduling and status feed back.

###key features: 

-**dual appliances control**: appliances (leds and fans) can be controlled manually by DIP switches. 
or by bluetooth control using HC-05 bluetooth module and a bluetooth serial terminal using uart protocol. 

-**control methods switching**:  user can switch between manual and bluetooth control by a DIP switch. 

-**priority based task schedualing**:  uses freeRTOS preemptive schedualing with priorities to manage tasks efficiently.  

-**LCD&BUZZER status display**: the LCD shows the current state of the device (i.e: led ON) and the buzzer Beebs everytime any device goes off and whenever the manual control mode is on.



this project was developed to be a simple software mechanism for a smart home and to be a base for expanding more into more advanced smart home features.
