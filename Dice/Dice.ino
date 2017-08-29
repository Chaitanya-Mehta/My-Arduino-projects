

int ShowNumPin[6][6]={{5},{1,9},{1,5,9},{2,4,6,8},{1,3,5,7,9},{1,4,7,3,6,9}};
int process[8]={1,2,3,6,9,8,7,4};
int DiceThrown[9]={1,2,3,4,5,6,7,8,9};
const int buttonPin=11;
int buttonState=0;
int previousButtonState=buttonState;
void setup() {
    Serial.begin(9600);
    pinMode(buttonPin,INPUT);
  for(int i=2;i<=10;i++)
  {
  
    pinMode(i,OUTPUT);
    
        }
  // put your setup code here, to run once:

}

void loop()
{
   // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  if (buttonState == previousButtonState) 
   {
     for(int i=2;i<=10;i++)
    digitalWrite(i, LOW);
    showProcessing();
   }
  if (buttonState !=previousButtonState)
  {
    Serial.println("buttonState changed.");
    throwDice();
  }
  previousButtonState=buttonState;
}
void throwDice()
{
  for(int i=2;i<=10;i++)
    digitalWrite(i, LOW);
     Serial.println("Dice Thrown");
  for(int i=0;i<9;i++)
  {
    digitalWrite(DiceThrown[i]+1,HIGH);
    delay(100);
  }
  for(int i=0;i<9;i++)
  {
    digitalWrite(DiceThrown[i]+1,LOW);
    delay(100);
  }
   int n;
  randomSeed(analogRead(5));
  n=random(1,7);
  Serial.println(n);
  for(int i=0;i<n;i++)
  {
    
    digitalWrite((ShowNumPin[n-1][i])+1,HIGH);
    
  }
    delay(3000);
}
void showProcessing()
{
  Serial.println("Processing");
  for(int i=0;i<8;i++)
  {
    digitalWrite(process[i]+1,HIGH);
    delay(100);
  }
  for(int i=0;i<8;i++)
  {
    digitalWrite(process[i]+1,LOW);
    delay(100);
  }
}

