
int x = 0;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  x = analogRead(A0);//đọc giá trị từ biến trở, cất vào x
  int brightness = map(x,0,1023,0,255);//qui đổi sang độ sáng
  analogWrite(9, brightness);//sáng led theo brightness
}
