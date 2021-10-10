int _clock_r = 1, _latch_r = 0, _data_r = 2;
int _clock_c = 9, _latch_c = 8, _data_c = 10;


void setup() {
  pinMode(_latch_r, OUTPUT);
  pinMode(_clock_r, OUTPUT);
  pinMode(_data_r, OUTPUT);
  pinMode(_latch_c, OUTPUT);
  pinMode(_clock_c, OUTPUT);
  pinMode(_data_c, OUTPUT);
}

//Hàm tính lũy thừa x^y
int LuyThua(int x,int y){
  int luythua = 1;
  for(int i = 1; i <= y;i++)
    luythua = luythua * x;
   return luythua;
}

// Hàm làm sáng LED theo sô thập phân tương ứng
void SangLedTheoDoiSoCol_atRow(int x,int row){
    digitalWrite(_latch_r, LOW);
    shiftOut(_data_r, _clock_r, MSBFIRST, (255 - LuyThua(2,row)));
    digitalWrite(_latch_r, HIGH);
  
    digitalWrite(_latch_c, LOW);
    shiftOut(_data_c, _clock_c, MSBFIRST, x);
    digitalWrite(_latch_c, HIGH);

    delay(5);
}

//Hàm vẽ mặt cười
void matCuoi(){
  //row 0 - sáng tại cột 2 3 4 5
  SangLedTheoDoiSoCol_atRow((LuyThua(2,2)+LuyThua(2,3)+LuyThua(2,4)+LuyThua(2,5)),0);
  //row 1 - sáng tại cột 1 6
  SangLedTheoDoiSoCol_atRow((LuyThua(2,1)+LuyThua(2,6)),1);
  //row 2 - sáng tại cột 0 2 5 7
  SangLedTheoDoiSoCol_atRow((LuyThua(2,0)+LuyThua(2,2)+LuyThua(2,5)+LuyThua(2,7)),2);
  //row 3 - sáng tại cột 0 7
  SangLedTheoDoiSoCol_atRow((LuyThua(2,0)+LuyThua(2,7)),3);
  //row 4 sáng tai cột 0 1 6 7
  SangLedTheoDoiSoCol_atRow((LuyThua(2,0)+LuyThua(2,1)+LuyThua(2,6)+LuyThua(2,7)),4);
  //row 5 sáng tại cột 0 2 3 4 5 7
  SangLedTheoDoiSoCol_atRow((LuyThua(2,0)+LuyThua(2,2)+LuyThua(2,3)+LuyThua(2,4)+LuyThua(2,5)+LuyThua(2,7)),5);
  //row 6 - sáng tại cột 1 6
  SangLedTheoDoiSoCol_atRow((LuyThua(2,1)+LuyThua(2,6)),6);
  //row 7 - sáng tại cột 2 3 4 5
  SangLedTheoDoiSoCol_atRow((LuyThua(2,2)+LuyThua(2,3)+LuyThua(2,4)+LuyThua(2,5)),7);
}

void loop() {
  matCuoi();
}
