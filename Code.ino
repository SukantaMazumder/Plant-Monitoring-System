const int dry = 600; //this value means when soil is dry. the value is changable. You need to change them according to the reading from Serial Monitor.

const int wet = 240; //this value means when soil is wet. the value is changable. You need to change them according to the reading from Serial Monitor

const int pump = 6;  //defining pump from relay IN to Arduino

const int green = 4; //defining green led

const int red = 3; //defining red led

void setup()
{
  Serial.begin(9600);
  pinMode(pump, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);

  digitalWrite(pump, HIGH);  //defining pump as off from the beginning
  digitalWrite(green, LOW);
  digitalWrite(red, LOW);
}

void loop()
{
  int sensor_value = analogRead(A0);  //getting value from Moisture sensor which output is connected to Arduino A0.
  //Try to see the value placing moisture sensor in dry soil and wet soil.
  //according to the value getting from dry soil and wet soil  change the value at the top const int dry & const int wet

  //Serial.println(sensor_value); //uncomment it to see analog value from moisture sensor
  //take decision according the value shown in serial monitor

  int moisture = map(sensor_value, wet, dry, 100, 0); //converting the moisture level in percentage

  //uncomment the lines below after deciding wet value and dry value.

  /*
    Serial.print(moisture);
    Serial.println("%");

    delay (100);
  */

  if (moisture <= 40) //if soil moisture percentange is less or equal to 40%  , you can change the percentage according to your choice
  {
    digitalWrite(pump, LOW); //pump will be on
  }

  if (moisture >= 90) //if soil moisture percentange is greater or equal to 90%  , you can change the percentage according to your choice
  {
    digitalWrite(pump, HIGH); //pump will be off
  }

  if (moisture >= 50 && moisture <= 100)  //if moisture level is between 50% to 100% green led will on as good moisture
  {
    digitalWrite(red, LOW); //red led will be off
    digitalWrite(green, HIGH); //green led will be on as good moisture indicator
  }

  if (moisture >= 0 && moisture < 50) //if moisture level is less than 50% red led will on as low moisture
  {
    digitalWrite(red, HIGH); //red led will be blinking as low moisture indicator
    delay(200);
    digitalWrite(red, LOW);
    delay(200);
    digitalWrite(green, LOW); //green led will be off
  }
}
