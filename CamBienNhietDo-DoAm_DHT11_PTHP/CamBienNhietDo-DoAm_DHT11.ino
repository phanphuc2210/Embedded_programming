//Thêm thư viện DHT.h để sử dụng cảm biến DHT11 dễ dàng
#include "DHT.h"  
//Khai báo chân kết nối cho cảm biến DHT ở đây mình dùng chân D4 trên Arduino Uno.          
int DHTPIN = 12;      
int DHTTYPE = DHT11; 

int D0=2,D1=3,D2=4,D3=5,D4=6,D5=7,D6=8,D7=9;
int RS=0,E=1;

//Thiết lập cho thư viện DHT.h
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  dht.begin(); //Khởi động thư viện
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(RS, OUTPUT);
  pinMode(E, OUTPUT);  
}

void loop()
{
  float h = dht.readHumidity();  // Đọc giá trị nhiệt độ từ cảm biến
  float t = dht.readTemperature(); // Đọc giá trị độ ẩm từ cảm biến 

  // Xoa noi dung tren LCD
  sendCMD2LCD(0x01);  
  // Bat hien thi man hinh, tat con tro
  sendCMD2LCD(0x0C);
  
  //In nhiet đô ra màn hình LCD
  sendString2LCD("Nhiet do: ");  
  String nhietdo = String(t, 1); // chuyển float thành chuỗi sử dụng float và các vị trí thập phân
  sendString2LCD(nhietdo);
  // Xuong dong 2
  sendCMD2LCD(0x38);   // CHE DO 2 DONG
  sendCMD2LCD(0xC0);    // TRO XUONG DONG 2 
  //In độ ẩm ra màn hình LCD
  sendString2LCD("Do am: "); 
  String doam = String(h, 1); // chuyển float thành chuỗi sử dụng float và các vị trí thập phân
  sendString2LCD(doam);

  delay(100);
}

// Ham gui data/cmd ra 8 chan cua LCD
void send8BitLCD(char D) {
  // Dem D and so hoc voi 2^i de biet bit thu i =0 hay khac ko
  // tim gia tri cac bit
  int b0,b1,b2, b3,b4, b5, b6, b7;
  if ((D & 1) == 0)  b0=0;    // 1== 2^0
  else b0 =1;
  if ((D & 2) == 0)  b1=0;    // 2== 2^1
  else b1 =1;
  if ((D & 4) == 0)  b2=0;    // 4== 2^2
  else b2 =1;
  if ((D & 8) == 0)  b3=0;    // 8== 2^3
  else b3 =1;
  if ((D & 16) == 0)  b4=0;   // 16== 2^4
  else b4 =1;
  if ((D & 32) == 0)  b5=0;   // 32== 2^5
  else b5 =1;
  if ((D & 64) == 0)  b6=0;   // 64== 2^6
  else b6 =1;
  if ((D & 128) == 0)  b7=0;  // 128== 2^7
  else b7 =1;
  digitalWrite(D0,b0);
  digitalWrite(D1,b1);
  digitalWrite(D2,b2);
  digitalWrite(D3,b3);
  digitalWrite(D4,b4);
  digitalWrite(D5,b5);
  digitalWrite(D6,b6);
  digitalWrite(D7,b7);
}

// Ham gui lenh
void sendCMD2LCD(char cmd) {
  //B1. Done
  //B2. Dat chan RS =0, de noi rang cmd  là lenh
  digitalWrite(RS, LOW);
  //B3. Gui 8 bit CMD vao 8 pin
  send8BitLCD(cmd);
  //B4. Enable cho cmd-->lcd
  digitalWrite(E, LOW);
  digitalWrite(E, HIGH);
  //
  delay(1);
}

// Ham gui ky tu hien thi
void sendChar2LCD(char Char) {
  //B1. Done
  //B2. Dat chan RS =1,  
  digitalWrite(RS, HIGH);
  //B3. Gui 8 bit CMD vao 8 pin
  send8BitLCD(Char);
  //B4. Enable cho cmd-->lcd
  digitalWrite(E, LOW);
  digitalWrite(E, HIGH);
  //
  delay(1);
}


void sendString2LCD(String str) {
   for (int i=0; str[i] != '\0';  i++) {
      sendChar2LCD(str[i]);
   }  
}
