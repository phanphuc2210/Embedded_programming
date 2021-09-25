
int x = 0;

void setup()
{
  pinMode(2, INPUT); 
  pinMode(13, OUTPUT);
}

void loop()
{
    //Đọc cổng 2, lưu trữ vào biến x
    x = digitalRead(2);
    //Kiểm tra xem nút có đang bấm không
    if (x == HIGH){
      //Bật led
      digitalWrite(13,HIGH);
      
    } else {
      //Tắt led
      digitalWrite(13,LOW);
    }
    delay(100); //Đợi trong 100 mili giây
}
