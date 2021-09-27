int pot = A0;
int led = 9;
int led_write = 0;
int bot = 5;
int rele = 8;

bool estado_bot = false;
bool estado_bot_ant = false;
bool blynk = false;
bool chave = false;
int rampa = 0;
bool timer = false;

long int valor_timer = 1800000;
long int tempo = 0;

long int atual = 0;
long int anterior = 0;

#include <IRremote.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

const int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);

  irrecv.enableIRIn();

  Serial.println("############  NANO START 11.2 ############");

  pinMode(bot, INPUT);
  pinMode(led, OUTPUT);
  pinMode(rele, OUTPUT);
  pinMode(pot, INPUT);
}

void loop() {
  Serial.println(results.value,HEX);
  if (timer & (millis() - tempo) > valor_timer) {
    timer = false;
    tempo = 0;
    digitalWrite(rele, LOW);
  }

  if (timer) {
    Serial.println((String)((millis() - tempo) / 60000) + " | " + (String)valor_timer);
  }

  if (irrecv.decode(&results)) {
    irrecv.resume(); // Receive the next value

    atual = results.value;
    if (atual == -1)atual = anterior;
    if (atual != anterior)anterior = atual;

    if (atual == 1647615021 || atual == -1547112997 || atual == -1410204993 || atual == -1924779084 || atual == 452107421 || atual == -1547112997 || atual == 1430918278 || atual == -883661222 || atual == -1096365843) {
      chave = true;
      digitalWrite(rele, HIGH);
    }
    if (atual == 16752735 || atual == -1416522465 || atual == 309182138 || atual == -1416522468 || atual == 1687693088) {
      chave = false;
      rampa = 0;
      timer = false;
      analogWrite(led, rampa);
      digitalWrite(rele, LOW);
    }
    if (atual == 1942101314 || atual == -1714805164 || atual == 324312031 || atual == 16722135 || atual == 264665118 || atual == 1641801934) {
      tempo = millis();
      timer = true;
      digitalWrite(rele, HIGH);
    }
    if (atual == 16748655 || atual == -439370369 || atual == -439370369 || atual == 596540466) {
      rampa = rampa + 5;
      Serial.println("botão pressionado");
    }
    if (!chave & rampa != 0) {
      analogWrite(led, rampa);
    }
  }
  if (rampa > 300) {
    rampa = 0;
    blynk = false;
  }
  if (rampa == 225 & !blynk) {
    blynk = true;
    analogWrite(led, 0);
    delay(1000);
    analogWrite(led, 225);
    delay(1000);
    analogWrite(led, 0);
    delay(1000);
    analogWrite(led, 225);
  }
  delay(100);
}
