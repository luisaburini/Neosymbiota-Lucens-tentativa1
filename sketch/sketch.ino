
#include <Servo.h>          

// Codigo para uso com motor servo de rotacao continua
int SENTIDO_HORARIO = 0;// 0: velocidade maxima em sentido horario
int PARADO = 90; // 90: parado
int SENTIDO_ANTI_HORARIO = 180; // 180: velocidade maxima em sentido anti-horario 
 
Servo Horizontal;           // Inicia o Servo da Horizontal
Servo Vertical;             // Inicia o Servo da Vertical

int PINO_HORIZONTAL = 3;
int PINO_VERTICAL = 5;

int ServoHorizontal = 90;   // Estabelece valor fixo à ServoHorizontal
int ServoVertical = 90;     // Estabelece valor fixo à ServoVertical
 
int LDRDC = A0;             // Inicia LDRDC no pino A0
int LDRDB = A1;             // Inicia LDRDB no pino A1
int LDREC = A2;             // Inicia LDREC no pino A2
int LDREB = A3;             // Inicia LDREB no pino A3
 
void setup()  {
  Serial.begin(9600);
  Vertical.attach(PINO_VERTICAL);
  Vertical.write(PARADO);
  Horizontal.attach(PINO_HORIZONTAL);
  Horizontal.write(PARADO);
  delay(3000);              // Aguarda 3 segundos
}
 
void loop() {
  int LDC = analogRead(LDRDC);      // Leitura Analógica do LDR Direita Cima
  int LEC = analogRead(LDREC);      // Leitura Analógica do LDR Esquerda Cima
  int LDB = analogRead(LDRDB);      // Leitura Analógica do LDR Direita PINO_HORIZONTAL
  int LEB = analogRead(LDREB);      // Leitura Analógica do LDR Esquerda PINO_HORIZONTAL
 
  int tol = 20;
 
  int ValorSup = (LDC + LEC) / 2;   // Média da leitura dos LDR superior
  int ValorInf = (LDB + LEB) / 2;   // Média da leitura dos LDR inferior
  int ValorDir = (LDC + LDB) / 2;   // Média da leitura dos LDR da direita
  int ValorEsq = (LEC + LEB) / 2;   // Média da leitura dos LDR da esquerda
 
  int DifSupInf = ValorSup - ValorInf;      // Diferença entre LED superior e inferior
  int DifDirEsq = ValorDir - ValorEsq;      // Diferença entre LED direita e esquerda
 
  /*---------------------------------------------------*/
  Serial.print("Diff sup inf ");
  Serial.println(DifSupInf);
  // Realiza a leitura e executa os movimentos referente ao Servo Vertical
  if (-1 * tol > DifSupInf || DifSupInf > tol)  {
    if (ValorSup > ValorInf)  {
      ServoVertical = SENTIDO_ANTI_HORARIO;
    }
    else if (ValorSup < ValorInf)  {
      ServoVertical = SENTIDO_HORARIO;
    }
    Serial.print("Servo vertical ");
    Serial.println(ServoVertical);
    Vertical.write(ServoVertical);
  } else {
    Vertical.write(PARADO);
  }
 
  Serial.print("Diff dir esq ");
  Serial.println(DifDirEsq);
  // Realiza a leitura e executa os movimentos referente ao Servo Horizontal
  if (-1 * tol > DifDirEsq || DifDirEsq > tol) {
    if (ValorDir > ValorEsq)  {
      ServoHorizontal = SENTIDO_ANTI_HORARIO;
    }
    else if (ValorDir < ValorEsq)  {
      ServoHorizontal = SENTIDO_HORARIO;
    }
    Serial.print("Servo horizontal ");
    Serial.println(ServoHorizontal);
    Horizontal.write(ServoHorizontal);
  } else {
    Horizontal.write(PARADO);
  }
 
  delay(10);   // Aguarda 0,1 segundo
}
