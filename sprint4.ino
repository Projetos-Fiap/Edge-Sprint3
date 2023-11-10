
// Adicionamos as bibliotecas que serão utilizadas
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "ArduinoJson.h"
#include "EspMQTTClient.h"

// MQTT Configuracoes
EspMQTTClient client{
  "Wokwi-GUEST", //SSID do WiFi
  "",     // Senha do wifi
  "mqtt.tago.io",  // Endereço do servidor
  "Default",       // Usuario
  "2d563834-26ce-44f0-9a58-bd97c7dcccf7",         // Token do device
  "esp",           // Nome do device
  1883             // Porta de comunicação
};

// Endereço e dimensões do LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); 

// Variáveis para o potenciômetr
int valor_pot = 0; 
int valor_anterior = -1;

// Variáveis para o LED e Buzzer
const int ledPin = 25;
const int buzzerPin = 33;

// Variável para controle do tempo de acionamento do buzzer
unsigned long buzzerStartTime = 0;

// Variáveis para o botão, com ciclo de 3 ações
int buttonPin = 4;
int buttonState = HIGH;
int lastButtonState = HIGH;
int numActions = 3;
int action = numActions - 1;

void setup() {
// Inicialização do Display LCD  
lcd.init();
lcd.backlight();
  
// Definição dos pinos
pinMode(ledPin, OUTPUT);
pinMode(buzzerPin, OUTPUT);
pinMode(buttonPin, INPUT);

// Comunicação serial
Serial.begin(9600);
Serial.println("Conectando WiFi");
while (!client.isWifiConnected()) {
  Serial.print('.'); client.loop(); delay(1000);
  }
  Serial.println("WiFi Conectado");
  Serial.println("Conectando com Servidor MQTT");
while (!client.isMqttConnected()) {
    Serial.print('.'); client.loop(); delay(1000);
  }
Serial.println("MQTT Conectado");
}

// Callback da EspMQTTClient
void onConnectionEstablished()
{}
char bufferJson[100];

void loop() {
  valor_pot = analogRead(34);  // Leia o valor do potenciômetro
  int valor_mapeado = map(valor_pot, 0, 4095, 0, 1000);  // Mapeie o valor lido para a faixa desejada (0 a 1000g)
  
  buttonState = digitalRead(buttonPin);

  if (valor_mapeado != valor_anterior) {
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Peso: ");
    lcd.print(valor_mapeado);
    lcd.print("g");
    valor_anterior = valor_mapeado;

    if (valor_mapeado >= 1000) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("LIMITE DE PESO");
      lcd.setCursor(0, 1);
      lcd.print("ATINGIDO");

      while (valor_mapeado >= 1000) {
        digitalWrite(ledPin, HIGH);
        tone(buzzerPin, 1000);
        delay(2000);
        noTone(buzzerPin);
        delay(1000);
        valor_pot = analogRead(34);
        valor_mapeado = map(valor_pot, 0, 4095, 0, 1000);
      }
    } else {
      digitalWrite(ledPin, LOW);
      noTone(buzzerPin);
    }
  }
  // Lógica do botão
  if (buttonState != lastButtonState && buttonState == LOW) {
    action = (action + 1) % numActions;  // Incrementa a ação do botão
  }
  //lcd.setCursor(0, 0);
  //lcd.print("                ");  // Limpa completamente a linha

  lcd.setCursor(0, 0);
  // Exibe o texto do botão de acordo com a ação atual
  switch (action) {
    case 0:
      lcd.print("Tipo: Aluminio     ");
      break;
    case 1:
      lcd.print("Tipo: Plastico     ");
      break;
    case 2:
      lcd.print("Tipo: Vidro         ");
      break;
    // Adicione mais cases para ações adicionais, se necessário

    default:
      break;
  }

  lastButtonState = buttonState;  // Armazena o estado atual do botão

 // Enviando para TagoIO

  StaticJsonDocument<300> documentoJson;
  documentoJson["variable"] = "peso";
  documentoJson["value"] = valor_mapeado;
  documentoJson["unit"] = "gramas";
  documentoJson["type"] = getType(action);
  serializeJson(documentoJson, bufferJson);
  Serial.println(bufferJson);
  client.publish("topicoTDSPI", bufferJson);
  delay(5000);
  client.loop();
}

String getType(int action) {
  switch (action) {
    case 0:
      return "Alumínio";
    case 1:
      return "Plástico";
    case 2:
      return "Vidro";
    // Adicione mais cases conforme necessário

    default:
      return ""; // Retorne uma string vazia para casos não tratados
  }
}