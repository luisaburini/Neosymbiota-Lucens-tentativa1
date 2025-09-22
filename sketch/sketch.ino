const int DIRECAO = 2;
const int PULSO = 3;
 
int LDRDC = A0;             // Inicia LDRDC no pino A0
int LDRDB = A1;             // Inicia LDRDB no pino A1
 
void setup()  {
  Serial.begin(9600);
  pinMode(DIRECAO, OUTPUT);
  pinMode(PULSO, OUTPUT);
  delay(3000);              // Aguarda 3 segundos
}
 
void loop() {
  int LDC = analogRead(LDRDC);      // Leitura Analógica do LDR Direita Cima
  int LDB = analogRead(LDRDB);      // Leitura Analógica do LDR Direita PINO_HORIZONTAL

  int tol = 50;
 
  int ValorSup = LDC;   // Média da leitura dos LDR superior
  int ValorInf = LDB;   // Média da leitura dos LDR inferior
 
  int DifSupInf = ValorSup - ValorInf;      // Diferença entre LED superior e inferior
 
  /*---------------------------------------------------*/
  Serial.print("Diff sup inf ");
  Serial.println(DifSupInf);
  // Realiza a leitura e executa os movimentos referente ao motor de passo vertical
  if (-1 * tol > DifSupInf || DifSupInf > tol)  {
    Serial.print("Servo vertical ");
    if (ValorSup > ValorInf)  {
      Serial.println("LOW");
      digitalWrite(DIRECAO, LOW);
    }
    else if (ValorSup < ValorInf)  {
      Serial.println("HIGH");
      digitalWrite(DIRECAO, HIGH);
    }
  }
  digitalWrite(PULSO, LOW);
  digitalWrite(PULSO, HIGH); 
 
  delay(10);   // Aguarda 0,1 segundo
}
