int LEDblue=3; //Blue ở chân 3
int LEDred=5; //Red ở chân 5
int LEDgreen=6; //Green ở chân 6
int b=1000; //b ngừng trong 1000ms (1 giây)

int brightnessblue=150; //giá trị từ 0 đến 255 - định nghĩa độ sáng của màu đơn

int brightnessred=150; //giá trị từ 0 đến 255 - định nghĩa độ sáng của màu đơn 

int brightnessgreen=150; //giá trị từ 0 đến 255 - định nghĩa độ sáng của màu đơn

int dark=0; //Giá trị 0 là điện áp ở 0V - do đó đèn LED tắt

// Hàm thiết lập màu
void setColor(int r,int g,int b){
  digitalWrite(LEDred, r);
  digitalWrite(LEDgreen, g);
  digitalWrite(LEDblue, b);
  delay(b); //Break
}


void setup()
{
  pinMode(LEDblue, OUTPUT);
  pinMode(LEDgreen, OUTPUT);
  pinMode(LEDred, OUTPUT);
}

void loop()
{
  digitalWrite(LEDblue, brightnessblue); //bật blue
  delay(b); //nghỉ
 
  digitalWrite(LEDblue, dark); //tắt blue
 
  digitalWrite(LEDred, brightnessred); //bật red
  delay(b); //Break 
 
  digitalWrite(LEDred, dark); // tắt red
 
  digitalWrite(LEDgreen, brightnessgreen); //bật green
  delay(b); //Break

  digitalWrite(LEDgreen, dark); //tắt green
}
