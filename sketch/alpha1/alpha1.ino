#define headphonesOff 3;
#define headphonesOn 30;

int buttonState = 0;
int headphonesRelayState = 0;

void setup() {
  // put your setup code here, to run once:
// Инициализируем цифровой вход/выход в режиме выхода.
  // Выход 13 на большинстве плат Arduino подключен к светодиоду на плате.
  pinMode(13, OUTPUT);
 pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);
pinMode(7, INPUT); 
}

void loop() {
  buttonState = digitalRead(7);
 
  // проверяем нажата ли кнопка
  // если нажата, то buttonState будет HIGH:
  if (buttonState == HIGH) {   
    // включаем светодиод   
    digitalWrite(2, HIGH);
   digitalWrite(3, HIGH); 
  }
  else {
    // выключаем светодиод
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
  }

  //digitalWrite(2, HIGH);   // зажигаем светодиод
  //delay(500);              // ждем секунду
  //digitalWrite(2, LOW);
  // put your main code here, to run repeatedly:
  //digitalWrite(13, HIGH);   // зажигаем светодиод
  //delay(500);              // ждем секунду
  //digitalWrite(13, LOW);  // выключаем светодиод
  //delay(500);              // ждем секунду
  //digitalWrite(13, HIGH);  // выключаем светодиод
  //delay(500);              // ждем секунду
  //digitalWrite(13, LOW);  // выключаем светодиод
  //delay(2000);              // ждем секунду
}
