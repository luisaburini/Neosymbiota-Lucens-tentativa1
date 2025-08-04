#define NIVEL_AGUA A0
#define TURBIDEZ A1

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  //calculaNTU();
  medeNivel();
  delay(800);
}

void medeNivel() {
  int nivel = analogRead(NIVEL_AGUA);
  if (nivel > 500) {
    Serial.println("Nivel alto - liga bomba");
  } else {
    Serial.println("Nivel baixo - desliga bomba");
  }
}

/*****************************************************************
a turbidez pode ser entendida como a medida do espalhamento da luz
produzido pela presença de partículas em suspensão sendo expressa 
como Unidade Nefelométrica de Turbidez. 
Nefelometria é o processo de medida da concentração de uma emulsão 
por comparação de sua transparência com a de uma preparação padrão.
******************************************************************/
double calculaNTU() {
  int sensorValue = analogRead(TURBIDEZ);
  double voltage = sensorValue * 5.0 / 1024.0;
  double ntu = -(1120.4 * voltage * voltage) + (5742.3 * voltage) - 4352.9;
  Serial.print(voltage);
  Serial.print(" ");
  Serial.println(ntu);
  delay(500);
}