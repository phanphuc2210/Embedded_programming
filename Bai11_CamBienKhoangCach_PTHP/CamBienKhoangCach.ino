int trig = 13; // chân trig của HC-SR04
int echo = 12; // chân echo của HC-SR04

void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT); // chân trig sẽ phát tín hiệu
  pinMode(echo, INPUT); // chân echo sẽ thu tín hiệu
}

void loop()
{
  unsigned long thoigian;
  float khoangcach;
  
  // Phát xung từ chân trig
  digitalWrite(trig,LOW);   // tắt chân trig
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);   // phát xung từ chân trig
  delayMicroseconds(5);   // xung có độ dài 5 microSeconds
  
  // Tính toán thời gian
  //Đo độ rộng xung HIGH ở chân echo. 
  thoigian = pulseIn(echo, HIGH);
  // Tính khoảng cách đến vật.
  //Tốc độ của âm thanh trong không khí là 340 m/s
  //tương đương với 0.034 cm/microSeconds ((340*100)/10^6 )
  // distance = (travel time/2)*speed ò sound
  khoangcach = (float)thoigian/2*0.034;
  
  // In kết quả ra Serial Monitor
  Serial.print(khoangcach);
  Serial.println("cm");
  delay(200);
}
