/*
PWM Val Mapping
Budro Gerung
@McTavish
*/

//Variable for pwm Value Mapping 

int minValPercent    = 10;    //desired mininum value of fan output(0-100%)
int maxValPercent    = 50;   //desired maximum value of fan output(0-100%)

//-------------------------------------

const int fan = 7;
const int cpap = 3;

double fanRaw;
int fanState;
double fanOut;
double fanPwm;


int maxFanIn  = 9900;  //max input value of 

int minVal;
int maxVal;
void setup()
{
  pinMode(fan, INPUT);
  pinMode(cpap, OUTPUT);

  minVal = map(minValPercent, 0, 100, 0, 255);

  maxVal = map(maxValPercent, 0, 100, 0, 255);

  Serial.begin(9600);
}

void loop()
{
  fanRaw = pulseIn(fan, LOW);
  fanState = digitalRead(fan);

  if(fanRaw == 0 && fanState == 1)
  {
    fanOut = 0;
    analogWrite(cpap, fanOut);
  }

  else if(fanRaw == 0 && fanState == 0)
  {
    fanOut = maxVal;
    analogWrite(cpap, fanOut);
  }

  else
  {
    fanOut = map(fanRaw, 0, maxFanIn, minVal, maxVal);
    analogWrite(cpap, fanOut);
  }


  
  //Serial.print(fanRaw);
  //Serial.print("  --  ");
  //Serial.print(fanState);
  //Serial.print("  --  ");
  //Serial.println(fanOut);
  delay(10);
  
}
