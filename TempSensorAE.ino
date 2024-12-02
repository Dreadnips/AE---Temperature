#include <LiquidCrystal.h>

// Configuração dos pinos do LCD (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int potPin = A0;    // Pino do potenciômetro conectado ao pino A0
int contrastPin = 4; 

void setup() {
    // Configura o pino de contraste como saída
  pinMode(contrastPin, OUTPUT);

  // Define o valor fixo de contraste (170 de 0 a 255)
  //analogWrite(contrastPin, 0);

  // Inicializa o display LCD com 16 colunas e 2 linhas
  lcd.begin(16, 2);

  // Mensagem inicial no LCD
  lcd.print("Potenciometro:");
}

void loop() {

    // Aqui você pode variar o contraste dinamicamente
  for (int i = 0; i <= 255; i += 5) {
    analogWrite(contrastPin, i); // Ajusta o contraste
    delay(100);
  }
  for (int i = 255; i >= 0; i -= 5) {
    analogWrite(contrastPin, i); // Ajusta o contraste
    delay(100);
  }

  // Lê o valor do potenciômetro (entre 0 e 1023)
  int potValue = analogRead(potPin);

  // Exibe o valor na segunda linha do LCD
  lcd.setCursor(0, 1); // Coluna 0, linha 1
  lcd.print("Valor: ");
  lcd.print(potValue);
  lcd.print("    "); // Apaga dígitos antigos

  delay(200); // Atualiza a leitura a cada 200ms
}
