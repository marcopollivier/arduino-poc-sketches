const int PIN_LED_VERDE = 8;
const int PIN_LED_AMARELO = 9;
const int PIN_LED_VERMELHO = 10;

const int PIN_BOTAO = 2;

boolean pedestre = false;

int buttonState = 0;

void setup() {
  pinMode(PIN_BOTAO, INPUT);

  pinMode(PIN_LED_VERDE, OUTPUT);
  pinMode(PIN_LED_AMARELO, OUTPUT);
  pinMode(PIN_LED_VERMELHO, OUTPUT);
}

void loop() {

  buttonState = digitalRead(PIN_BOTAO);

  if (buttonState == HIGH) {
    
    digitalWrite(PIN_LED_VERMELHO, HIGH);
  
  } else {
    digitalWrite(PIN_LED_VERMELHO, LOW);
  }

}

void fecharSinal() {
  ligaDesliga(PIN_LED_VERDE, 500);
  ligaDesliga(PIN_LED_AMARELO, 200);
  ligaDesliga(PIN_LED_VERMELHO, 600);
}

void ligaDesliga(int pin, int timeDelay) {
  digitalWrite(pin, HIGH);
  delay(timeDelay);
  digitalWrite(pin, LOW);
}


