boolean pedestre = true;

void setup() {
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  
  digitalWrite(10, HIGH);

  if(pedestre) {
    fecharSinal();  
  }

}

void fecharSinal() {
  digitalWrite(10, HIGH);
  delay(5000);
  digitalWrite(10, LOW);

  digitalWrite(11, HIGH);
  delay(2000);
  digitalWrite(11, LOW);


  digitalWrite(12, HIGH);
  delay(6000);
  digitalWrite(12, LOW);
}

