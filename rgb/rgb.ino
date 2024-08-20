int buttonPin = 12; // Pin for the button
int redPin = 2;
int greenPin = 3;
int bluePin = 4;
bool buttonState = false; // State of the button (pressed or not)

// Array to store RGB values of different colors
int colors[][3] = {
  {255, 0, 0},    // Red
  {0, 255, 0},    // Green
  {0, 0, 255},    // Blue
  {255, 255, 255},  // White
  {170, 0, 255},  // Purple
  {127, 127, 127}  // Light Blue
};

// Number of colors in the array
int numColors = sizeof(colors) / sizeof(colors[0]);

// Index to keep track of the current color
int colorIndex = 0;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buttonPin, INPUT); // Set button pin as input
}

void loop() {
  buttonState = digitalRead(buttonPin); // Read the state of the button

  // If button is pressed, change to the next color
  if (buttonState == HIGH) {
    // Increment colorIndex and wrap around if needed
    colorIndex = (colorIndex + 1) % numColors;
    
    // Set LED color to the next color in the array
    setColor(colors[colorIndex][0], colors[colorIndex][1], colors[colorIndex][2]);
    
    // Delay to debounce the button press
    delay(500);
  }
}

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
