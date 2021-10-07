int a=13, b=12, c=11, d=10;

void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
}

void Khong(){
  digitalWrite(d,LOW); digitalWrite(c,LOW);
  digitalWrite(b,LOW); digitalWrite(a,LOW);
}

void Mot(){
  digitalWrite(d,LOW); digitalWrite(c,LOW);
  digitalWrite(b,LOW); digitalWrite(a,HIGH);
}

void Hai(){
  digitalWrite(d,LOW); digitalWrite(c,LOW);
  digitalWrite(b,HIGH); digitalWrite(a,LOW);
}

void Ba(){
  digitalWrite(d,LOW); digitalWrite(c,LOW);
  digitalWrite(b,HIGH); digitalWrite(a,HIGH);
}

void Bon(){
  digitalWrite(d,LOW); digitalWrite(c,HIGH);
  digitalWrite(b,LOW); digitalWrite(a,LOW);
}

void Nam(){
  digitalWrite(d,LOW); digitalWrite(c,HIGH);
  digitalWrite(b,LOW); digitalWrite(a,HIGH);
}

void Sau(){
  digitalWrite(d,LOW); digitalWrite(c,HIGH);
  digitalWrite(b,HIGH); digitalWrite(a,LOW);
}

void Bay(){
  digitalWrite(d,LOW); digitalWrite(c,HIGH);
  digitalWrite(b,HIGH); digitalWrite(a,HIGH);
}

void Tam(){
  digitalWrite(d,HIGH); digitalWrite(c,LOW);
  digitalWrite(b,LOW); digitalWrite(a,LOW);
}

void Chin(){
  digitalWrite(d,HIGH); digitalWrite(c,LOW);
  digitalWrite(b,LOW); digitalWrite(a,HIGH);
}

void loop() {
    Khong();
  delay(1000); // đợi 1 giây
  Mot();
  delay(1000);// đợi 1 giây
  Hai();
  delay(1000);// đợi 1 giây
  Ba();
  delay(1000);// đợi 1 giây
  Bon();
  delay(1000);// đợi 1 giây
  Nam();
  delay(1000);// đợi 1 giây
  Sau();
  delay(1000);// đợi 1 giây
  Bay();
  delay(1000);// đợi 1 giây
  Tam();
  delay(1000);// đợi 1 giây
  Chin();
  delay(1000);// đợi 1 giây
}
