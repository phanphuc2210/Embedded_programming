
int _clock = 7, _latch = 6, _data = 5;

void setup() {
  pinMode(_latch, OUTPUT);
  pinMode(_clock, OUTPUT);
  pinMode(_data, OUTPUT);
}

#Hàm tính lũy thừa x^y
int LuyThua(int x,int y){
  int luythua = 1;
  for(int i = 1; i <= y;i++)
    luythua = luythua * x;
   return luythua;
}

// Hàm làm sáng LED theo sô thập phân tương ứng
void SangLedTheoDoiSo(int x){
    digitalWrite(_latch, LOW);
    shiftOut(_data, _clock, LSBFIRST, x);
    digitalWrite(_latch, HIGH);
    delay(500);
}


void loop() { 
      for(int i = 0; i <= 7; i++){
          //Sáng từng led 1 từ dưới lên trên 
          // Q7 = 2^0=1 | Q6 = 2^1=2 | Q5 = 2^2=4 | ... | Q0 = 2^7 = 128
          SangLedTheoDoiSo(LuyThua(2,i)); 
      }

}
