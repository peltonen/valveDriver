#define INTERRUPTNUM 0  //Pin 2
#define CH1 3 
#define CH2 5
#define CH3 6 
#define CH4 9
#define SOLENOID 13

volatile boolean triggered = false;

//Constants
int puffDur = 500;
int solenoidDur = 500; 


void setup() {
  pinMode(SOLENOID, OUTPUT);
  pinMode(CH1, OUTPUT);
  pinMode(CH2, OUTPUT);
  pinMode(CH3, OUTPUT);
  pinMode(CH4, OUTPUT);  
  attachInterrupt(INTERRUPTNUM, triggerStimuli,RISING);
  //Serial.begin(9600);
}


void loop() {
  if(triggered)  {  //tests for trigger input
    presentStimuli();  
    triggered = false;
  }
}

void triggerStimuli() {
  triggered = true;
}

void presentStimuli()  {
  delay(500);
  triggerChannel(SOLENOID, solenoidDur);
  delay(500);
  triggerChannel(CH1, puffDur);
  delay(500);
  triggerChannel(CH2, puffDur);
  delay(500);
  triggerChannel(CH3, puffDur);
  delay(500);
  triggerChannel(CH4, puffDur);  
}


void triggerChannel(int channel, int duration)  {
  digitalWrite(channel, HIGH);
  delay(duration);
  digitalWrite(channel, LOW);
}
