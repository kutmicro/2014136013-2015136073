int trigPin=32;
int echoPin=33;

int pump_pin = 34;

int pumb_flag_cur = 0;
int pumb_flag_prev = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pump_pin,OUTPUT); 
  pinMode(trigPin,OUTPUT); 
  pinMode(echoPin,INPUT); 

  digitalWrite(pump_pin,HIGH); 
  delay(100);
  
  Serial.println("pump off");
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration, distance; 
  digitalWrite(trigPin,LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin,HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin,LOW); 
  
  duration = pulseIn(echoPin,HIGH); 
  distance = (duration/2)/29.1; 
  Serial.print(distance);
  
  if(distance<2)
    pumb_flag_cur = 1;
  else
    pumb_flag_cur = 0;

  if(pumb_flag_cur==1 && pumb_flag_prev==0)
  {
    Serial.println("pump on");
    
    delay(1000);
    for(int i=0;i<8;i++)
    {
      digitalWrite(pump_pin, LOW); 
      delay(420);
      digitalWrite(pump_pin, HIGH); 
    }
    delay(1000);
    
    Serial.println("pump off");
  }

  pumb_flag_prev = pumb_flag_cur;
  
  delay(100); 
}


