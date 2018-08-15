/*
 * Experimento para estudo da cinemática
 * - Estudo do movimento retilíneo uniforme 
 * 
 * Obtenção do tempo para o cálculo da velocidade considerando 
 * que o distância entre o ponto inicial e final é conhecida 
 * 
 * As marcações dos pontos são linhas pretas
 * 
 * Quando o robô ler o branco o sinal do sensor é 0 
 */
#include "ServoMotor.h" 

// motor esquerdo e direito 
ServoMotor sm;

// armazena o comando vindo da serial 
char c = 'x';
// para contagem das transições entre branco e preto 
int contMudanca = 0; 
// contador de tempo 
unsigned long tempoInicial; 
unsigned long primeiroTempo; 
unsigned long tempoAtual;
// Sensor instaldo no pino 13 
int pinSensor = 13; 
// estados do sensor 
bool refAnterior = false; // lendo branco recebe 0 
bool refAtual = false;  // lendo branco recebe 0 
// variavel de aceleracao
int acelerador = 1;
bool flag = false;

void setup() {
  Serial.begin(9600); 
  pinMode(pinSensor,INPUT); 
  sm.setup(11,10);
  sm.calibra(90,85);
  delay(100); 
  sm.parado(); 
}

void loop() {
  refAtual = digitalRead(pinSensor);
  // Ler um caracter da porta serial quando disponível 
  if (Serial.available())
  {
    c = Serial.read();
    if (c == 'i') { // iniciar o experimento 
      flag = false;
      sm.frente(); 
    }
    else if (c == 'p') { // parar o experimento 
      flag = false;
      sm.parado();
      contMudanca = 0; 
    }
    else if (c == 'a') { // acelerar
      flag = true;
    }
  }
  if ( ! refAnterior && refAtual) { // detectar transição entre branco e preto 
    contMudanca++; 
    if (contMudanca == 1) { // primeira transição 
      primeiroTempo = millis(); 
      Serial.println("1: 0"); 
    }
    else {
      tempoAtual = millis();
      double tempReal =(tempoAtual - primeiroTempo)/1000.0;
      Serial.print(contMudanca);
      Serial.print(": "); 
      Serial.println(tempReal); 
    }
    
  }

  if (flag == true)
  {
    int inicial = 30;
    int *coisa = sm.acelera(acelerador,inicial);
    Serial.print("[");
    Serial.print(coisa[0]);
    Serial.print(";");
    Serial.print(coisa[1]);
    Serial.println("]");
    Serial.print(acelerador);
    if((coisa[0]==0)&&(coisa[1]==180)) Serial.println("Maxima velocidade"); 
    else acelerador++; // Aceleração
    delay(250);
  }
  else acelerador = 0;
  
  refAnterior = refAtual; 
  delay(30); // intervalo mínimo entre as leituras do sensor de reflectância 
}
