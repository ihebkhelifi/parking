int a=0;
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  // print the data from the sensor
      
      while(a==0){
      Serial.println("1 ok");
      if(digitalRead(22)==HIGH && a==0)
      a=1;
      }
      Serial.println("2 ok");
      
      //if(digitalRead(22)==HIGH && a==0){
      //Serial.println("1 ok");
      //a++;
      //delay(3000);
      //}
      //if(digitalRead(24)==HIGH && a==1){
      //Serial.println("2 ok");
      //a--;
      delay(1000);
      //}
    }
