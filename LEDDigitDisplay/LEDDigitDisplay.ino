int adigit[10][13]={{1,2,3,4,5,6,8,9,10,11,12,13},{1,4,6,9,11},{1,2,3,5,6,7,8,9,11,12,13},{1,2,3,4,6,7,8,9,11,12,13},{1,4,6,7,8,9,10,11,13},{1,2,3,4,6,7,8,10,11,12,13},{1,2,3,5,6,7,8,9,10,11,12,13},
{11,12,13,9,6,4,1},{1,2,3,4,5,6,7,8,9,10,11,12,13},{1,2,3,4,6,7,8,9,10,11,12,13}};
void setup() {
  Serial.begin(9600);
  for(int i=1;i<=13;i++)
  {
    pinMode(i,OUTPUT);
  }
  // put your setup code here, to run once:
}

void loop() {
  if(Serial.available()>0)
{
  Serial.println("Enter the digit you want to type");
char digit=Serial.read();
Serial.print("You Entered:");
Serial.print(digit);
Serial.print("\n");
int idigit=digit;
int ASCIInum[3]={0,0,0};
int j=1;
while(idigit>0)
{
int ddigit;
ddigit=idigit%10;
ASCIInum[3-j]=ddigit;
idigit=(idigit-ddigit)/10;  
j++;
}
Serial.print("\n ASCII NUM:");
for(int i=0;i<3;i++)
{
  Serial.print(ASCIInum[i]);
}
Serial.print("\n");
for(int i=0;i<3;i++)
{
    displayDigit(ASCIInum[i]);
}
}
  
  // put your main code here, to run repeatedly:

}
void displayDigit(int dig){
   Serial.print("Show digit:");
   Serial.print(dig);
   Serial.print(":");
   int i=0;
  while(adigit[dig][i]!=0){
    Serial.print(adigit[dig][i]);
    Serial.print(",");
    digitalWrite(adigit[dig][i],HIGH);
    i++;
      }
   Serial.print("\n");
 delay(1000);
   for(int i=1;i<=13;i++)
  {
    digitalWrite(i,LOW);
  }
}




  
