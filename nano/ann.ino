// Perceptron learning algorithm on Arduino Nano
// Wiring: https://www.instructables.com/Control-Built-in-LED-Using-Push-Button-With-Arduin/

const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the bulit-in LED pin
int buttonState = 0;         // variable for reading the pushbutton status

// initial perpectron configuration (no bias)
float learning_rate = 0.01;
float weights[3] = {1.2, 0.5, 1.2};

bool approx_equal(double x, double y)
{  
   const double EPSILON = 1E-4;
   if (x == 0) return fabs(y) <= EPSILON;
   if (y == 0) return fabs(x) <= EPSILON;
   return fabs(x - y) / max(fabs(x), fabs(y)) <= EPSILON;
}

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

  // calculate prediction
  float input_array[3] = {buttonState, buttonState - 0.5, buttonState + 0.5};
  float prediction = 0;
  for (int i = 0; i < 3; i++){
      prediction = prediction + input_array[i] * weights[i];    
  }

  // applying gradient descent & print weights
  float error = prediction - buttonState;
  for (int i = 0; i < 3; i++){
      weights[i] = weights[i] - error * learning_rate * input_array[i];    
      Serial.println(weights[i]);
  }
  Serial.println(error);

  // light LED if correct
  bool verdict = approx_equal(prediction, buttonState); 
  if (verdict) {
    digitalWrite(ledPin, HIGH); // turn LED on
  }
  else {
    digitalWrite(ledPin, LOW);  // turn LED off:
  }

  Serial.println(0);
}