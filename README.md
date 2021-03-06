# AANN
Artificial Arduino Neural Network using Arduino Nano.

Included is an implementation of a perceptron in `nano/ann.ino` which uses a switch button as input signal and a LED light as a correct classification signal. The algorithm dynamically updates it's weights using online gradient descent with a configurable learning rate. 

There is also a collection of various scripts related to the Arduino Nano and Uno boards in their respective folders.

# Setup 

1. You will need to install the Arduino IDE or Web Editor to interface with the boards.

2. Assemble the circuit following the diagrams named `layout.png` or link at the top of the `.ino` script.

3. Upload the code contained in this sketch on to your board using the IDE or Web Interface.
  > This will execute the code on the microcontroller.

# Materials

* Arduino Uno board (standard)

* Arduino Nano board (AT328P flavour)

* Breadboard

* Jumper cables

* Charging cables

  * USB 2.0 to Micro USB (Nano)

  * Standard A-B USB cable (Uno)