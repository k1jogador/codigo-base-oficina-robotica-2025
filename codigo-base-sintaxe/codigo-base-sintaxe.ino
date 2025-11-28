/* CÓDIGO BASE - OFICINA DE ROBÓTICA
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
int velocidadeMotor = 59;

// Estado do robô
bool roboLigado = false;

void setup() {
  Serial.begin(9600);

  // Sensores
  pinMode(SENSOR_ESQUERDA, INPUT);
  pinMode(SENSOR_FRONTAL, INPUT);
  pinMode(SENSOR_DIREITA, INPUT);
  pinMode(PINO_BOTAO, INPUT_PULLUP);

  // Motores
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);

  // Garante que começa parado
  parar();
}

void loop() {
  
  // Lógica do Botão (Liga/Desliga)
  if (digitalRead(PINO_BOTAO) == LOW) {
    roboLigado = !roboLigado; // (se estitver ligado, desliga...)
    delay(200);
  }

  // Se o robô estiver desligado, chama a função parar()
  if (roboLigado == false) {
    parar();
    return;
  }

  // Leitura dos Sensores (retornam false ou true)
  bool s_esq = digitalRead(SENSOR_ESQUERDA);
  bool s_cen = digitalRead(SENSOR_FRONTAL);
  bool s_dir = digitalRead(SENSOR_DIREITA);

  // ====================================================
  // DESAFIO: CHAMADA DE FUNÇÕES
  // Aqui você vai usar a lógica "SE... ENTÃO..."
  // De inicio, teste apenas chamar a função frente();
  // ====================================================
  
  // Exemplo de teste:
  // frente(); 

}

// ================= CRIE AS FUNÇÕES DE MOVIMENTAÇÃO =================

/* * SINTAXE DE UMA FUNÇÃO:
 * void nomeDaFuncao() {
 * // comandos
 * }
 */

// DESAFIO: Preencha o comportamento de cada movimento

void frente() {
  // DICA: Para ir para frente, Motor Esq e Dir devem avançar
  // Escreva o código aqui:
  
}

void virarEsquerda() {
  // DICA: Motor Esq para trás, Motor Dir para frente
  // Escreva o código aqui:

}

void virarDireita() {
  // DICA: Motor Esq para frente, Motor Dir para trás
  // Escreva o código aqui:

}

void parar() {
  // Exemplo pronto:
  analogWrite(ENB, 0);
  analogWrite(ENA, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}