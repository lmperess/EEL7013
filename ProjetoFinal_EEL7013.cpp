/******************************************************************************/
/*                 Projeto final para a disciplina EEL7013                    */
/*          Protótipo: Sensor de ré automotivo /  Data 22/10/2022             */
/*     Alunos: Lucas Moacir Peres e Francisco Ernesto Carniato Mondardo       */
/******************************************************************************/

// inclusao das bibliotecas
#include <LiquidCrystal_I2C.h>

// configuracoes das portas utilizadas do arduino

// HC-SR04 (sensor de distancia)
const int ECHO = 2;
const int TRIG = 3;

// demais componentes
const int ledVermelho = 5;
const int ledLaranja = 6;
const int ledAmarelo = 7;
const int ledVerde = 8;
const int buzzer = 9;

// configuracoes do display LCD
LiquidCrystal_I2C lcd(0x20, 16, 2);

void setup() {
  Serial.begin(9600);
  
  lcd.init();
  lcd.setBacklight(HIGH);
  
  lcd.setCursor(0,0);
  lcd.print("  Projeto Final ");
  lcd.setCursor(0,1);
  lcd.print("EEL7013 - 2022.2");
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print(" Lucas M. Peres ");
  lcd.setCursor(0,1);
  lcd.print("Francisco M.");
  delay(1000);
  lcd.clear();

  // configuracoes do sensor
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  
  // configuracoes dos LEDs
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledLaranja, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);

  // configuracao do buzzer
  pinMode(buzzer, OUTPUT); 
}

void loop() {
  int distancia = sensor_morcego(TRIG,ECHO);
  
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println("cm");

  lcd.setCursor(0,0);
  lcd.print("Distancia: ");
  lcd.print(distancia);
  lcd.println("cm");

  if(distancia < 150 && distancia >= 120) {
      digitalWrite(ledVerde, HIGH);
      delay(50);
      digitalWrite(ledVerde, LOW);
      delay(50);
      digitalWrite(ledAmarelo, HIGH);
      digitalWrite(ledLaranja, HIGH);
      digitalWrite(ledVermelho, HIGH);
      tone(buzzer, 1000);
      delay(50);
      noTone(buzzer);
      delay(1000);
    }
    else if (distancia < 120 && distancia >= 90) {
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledAmarelo, HIGH);
      delay(50);
      digitalWrite(ledAmarelo, LOW);
      delay(50);
      digitalWrite(ledLaranja, HIGH);
      digitalWrite(ledVermelho, HIGH);
      tone(buzzer, 1000);
      delay(50);
      noTone(buzzer);
      delay(500);
    }
    else if (distancia < 90 && distancia >= 60) {
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledAmarelo, LOW);
      digitalWrite(ledLaranja, HIGH);
      delay(50);
      digitalWrite(ledLaranja, LOW);
      delay(50);
      digitalWrite(ledVermelho, HIGH);
      tone(buzzer, 1000);
      delay(50);
      noTone(buzzer);
      delay(250);
    }
    else if (distancia < 60 && distancia >= 40) {
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledAmarelo, LOW);
      digitalWrite(ledLaranja, LOW);
      digitalWrite(ledVermelho, HIGH);
      delay(50);
      digitalWrite(ledVermelho, LOW);
      delay(50);
      tone(buzzer, 1000);
      delay(50);
      noTone(buzzer);
      delay(50);
    }
    else if (distancia < 40 && distancia >= 30) {
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledAmarelo, LOW);
      digitalWrite(ledLaranja, LOW);
      digitalWrite(ledVermelho, HIGH);
      delay(50);
      digitalWrite(ledVermelho, LOW);
      delay(50);
      tone(buzzer, 1000);
      delay(50);
      noTone(buzzer);
      delay(25);
    }
    else if (distancia < 30) {
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledAmarelo, LOW);
      digitalWrite(ledLaranja, LOW);
      digitalWrite(ledVermelho, HIGH);
      tone(buzzer, 1000);
      delay(50);
    }
    else {
      digitalWrite(ledVerde, HIGH);
      digitalWrite(ledAmarelo, LOW);
      digitalWrite(ledLaranja, LOW);
      digitalWrite(ledVermelho, LOW);
      noTone(buzzer);
    }
}

int sensor_morcego(int pinotrig,int pinoecho){ 
  digitalWrite(pinotrig,LOW);
  delayMicroseconds(2);
  digitalWrite(pinotrig,HIGH);
  delayMicroseconds(10);
  digitalWrite(pinotrig,LOW);

  return pulseIn(pinoecho,HIGH)/58;
  
}
