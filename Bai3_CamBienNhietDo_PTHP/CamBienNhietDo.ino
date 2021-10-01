// C++ code
//

int temperature = 0;
int temp[5]; // Lấy ra những giá trị nhiệt độ tốt.

void setup()
{
   pinMode(A0, INPUT);
   pinMode(10, OUTPUT);
  
}

void loop()
{
  // Chuyển đổi giá trị đọc được từ chân A0 thành 
  //nhiệt độ tương ứng
  temp[0] = map(analogRead(A0),20,358,-40,125); 
  delay(40); // Đợi 40 mili giây để lấy giá trị tiếp theo
    
  temp[1] = map(analogRead(A0),20,358,-40,125); 
  delay(40); // Đợi 40 mili giây để lấy giá trị tiếp theo
    
  temp[2] = map(analogRead(A0),20,358,-40,125); 
  delay(40); // Đợi 40 mili giây để lấy giá trị tiếp theo
    
  temp[3] = map(analogRead(A0),20,358,-40,125); 
  delay(40); // Đợi 40 mili giây để lấy giá trị tiếp theo
    
  temp[4] = map(analogRead(A0),20,358,-40,125);
    
  // Lấy nhiệt độ trung bình  
  temperature = (temp[0]+temp[1]+temp[2]+temp[3]+temp[4])/5; 
  
  if(temperature > 37) {digitalWrite(10,HIGH);}
  else {digitalWrite(10,LOW);}
  
  delay(500);
  
}
