/* * CÓDIGO BASE - OFICINA DE ROBÓTICA
 * Teste de Leitura e Movimentação
 * Autores: Prof. Dr. Richard Junior Manuel Godinez Tello e Aluno Kauã Alexandre Bernarde
 */

// Entradas (Sensores e Botão)
const int PINO_BOTAO = 8;
const int SENSOR_ESQUERDA = 10;
const int SENSOR_FRONTAL = 11; 
const int SENSOR_DIREITA = 12;

// Saídas - Ponte H (Motor Direito)
const int IN1 = 7;    // Direção A
const int IN2 = 5;    // Direção B
const int ENA = 6;    // Velocidade (PWM)

// Saídas - Ponte H (Motor Esquerdo)
const int IN3 = 4;    // Direção A
const int IN4 = 3;    // Direção B
const int ENB = 2;    // Velocidade

// Variável para controlar a velocidade (0 a 255)
int velocidadeMotor = 150; 

void setup() {
  // Configuração inicial
  
  Serial.begin(9600);

  // Configurando Sensores
  pinMode(SENSOR_ESQUERDA, INPUT);
  pinMode(SENSOR_FRONTAL, INPUT);
  pinMode(SENSOR_DIREITA, INPUT);
  
  // Configurando Botão
  pinMode(PINO_BOTAO, INPUT_PULLUP);

  // Configurando Motores
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
  // Loop principal

  // Ler o estado do botão (LOW = apertado)
  bool botaoApertado = digitalRead(PINO_BOTAO) == LOW;

  if (botaoApertado == true) {
    
    // Leitura dos sensores
    int valorEsq = digitalRead(SENSOR_ESQUERDA);
    int valorMeio = digitalRead(SENSOR_FRONTAL);
    int valorDir = digitalRead(SENSOR_DIREITA);

    // Mostrar dados no Monitor se detectar linha (considerando 1 como linha)
    if (valorMeio == 1){
      Serial.print(" | Meio: ");
      Serial.print(valorMeio);
    }
    if (valorEsq == 1){
      Serial.print(" | Esq: ");
      Serial.print(valorEsq);
    }
    if (valorDir == 1){
      Serial.print(" | Dir: ");
      Serial.print(valorDir);
    }

    Serial.println();

    // Acionamento dos motores com a ponte H

    // Deslocar para frente por 3 segundos
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, velocidadeMotor); 

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, velocidadeMotor);

    delay(3000); 

    // Rotacionar para esquerda por 3 segundos
    digitalWrite(IN1, HIGH); // Direito vai pra frente
    digitalWrite(IN2, LOW);
    analogWrite(ENA, velocidadeMotor);

    digitalWrite(IN3, LOW);  // Esquerdo vai pra trás
    digitalWrite(IN4, HIGH);
    analogWrite(ENB, velocidadeMotor); 

    delay(3000);

  }
}