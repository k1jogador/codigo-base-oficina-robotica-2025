/* CÓDIGO BASE - OFICINA DE ROBÓTICA
 * melhorado
 */

// Entradas (Sensores e Botão)
const int PINO_BOTAO = 8;
const int SENSOR_ESQUERDA = 12;
const int SENSOR_FRONTAL  = 11; 
const int SENSOR_DIREITA  = 10;

// === PINEAGEM  ===
// Motor Esquerdo
const int ENB = 6;
const int IN1 = 2;  // Esquerdo A
const int IN2 = 4;  // Esquerdo B

// Motor Direito
const int ENA = 3;
const int IN3 = 5;  // Direito A
const int IN4 = 7;  // Direito B

// Velocidade
int velocidadeMotor = 59; // velocidade interessante

// Estado do robô
bool roboLigado = false;

void setup() {
  Serial.begin(9600);

  pinMode(SENSOR_ESQUERDA, INPUT);
  pinMode(SENSOR_FRONTAL, INPUT);
  pinMode(SENSOR_DIREITA, INPUT);

  pinMode(PINO_BOTAO, INPUT_PULLUP);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);

  parar();
}

void loop() {

  // Liga/Desliga com debounce básico
  if (digitalRead(PINO_BOTAO) == LOW) {
    roboLigado = !roboLigado;
    delay(200);
  }

  if (!roboLigado) {
    parar();
    return;
  }

  // Leitura dos sensores
  bool S_E = digitalRead(SENSOR_ESQUERDA);
  bool S_C = digitalRead(SENSOR_FRONTAL);
  bool S_D = digitalRead(SENSOR_DIREITA);

  // ====== LÓGICA ======

  if (S_E == 1 && S_C == 1 && S_D == 1) {
    frente();
  }
  else if (S_E == 0 && S_C == 1 && S_D == 0) {
    frente();
  }
  else if (S_E == 1 && S_D == 0) {
    virarEsquerda();
  }
  else if (S_D == 1 && S_E == 0) {
    virarDireita();
  }
  else {
    frente();
  }
}

void frente() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);  // Esquerdo
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);  // Direito
  analogWrite(ENB, velocidadeMotor);
  analogWrite(ENA, velocidadeMotor);
}

void virarEsquerda() {
  digitalWrite(IN1, LOW);  digitalWrite(IN2, HIGH); // Esquerdo ré
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);  // Direito frente
  analogWrite(ENB, velocidadeMotor);
  analogWrite(ENA, velocidadeMotor);
}

void virarDireita() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);  // Esquerdo frente
  digitalWrite(IN3, LOW);  digitalWrite(IN4, HIGH); // Direito ré
  analogWrite(ENB, velocidadeMotor);
  analogWrite(ENA, velocidadeMotor);
}

void parar() {
  analogWrite(ENB, 0);
  analogWrite(ENA, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}