// analogWrite pins identified by ~ on board
// (pins with Pulse-Width Modulation support)
const int PIN_RED = 11;
const int PIN_GREEN = 10;
const int PIN_BLUE = 9;

int speed = 10000; // total length of fade up/down

// target RGB values for pumpkin orange
int redTarget = 255;
int greenTarget = 40;
//int blueTarget = 0;

int redBrightness;
int greenBrightness;
//int blueBrigthness;

long time=0;

void setup() {
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
}

void loop() {
  time = millis(); //Set time var to milliseconds elapsed since Arduino boot
  redBrightness = (redTarget/2) + (redTarget/2 - 1)*cos(2*PI / speed*time);
  analogWrite(PIN_RED, redBrightness); 
  greenBrightness = (greenTarget/2) + (greenTarget/2 - 1)*cos(2*PI / speed*time);
  analogWrite(PIN_GREEN, greenBrightness);
}
