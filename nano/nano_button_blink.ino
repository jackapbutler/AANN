// Make a LED blink when pressed 
// Wiring https://www.instructables.com/Control-Built-in-LED-Using-Push-Button-With-Arduin/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the bulit-in LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  //Initiate Serial communication.
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {    
    digitalWrite(ledPin, HIGH); // turn LED on
    Serial.print('Turned On');
  } else {
    digitalWrite(ledPin, LOW);  // turn LED off:
    Serial.print('Turned Off');
  }
}