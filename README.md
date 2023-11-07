# Edge Computing | Sprint 4

# Objetivo
O objetivo desta tarefa é finalizar o desenvolvimento de uma arquitetura para uma aplicação loT e realizar sua aplicação prática por meio de uma PoC (Proof of Concept) capaz de receber e transmitir dados provenientes de dispositivos conectados.

# Resumo do projeto
Nosso projeto, <b>"Rota Sustentável"</b>, tem como objetivo principal incentivar a reciclagem de lixo dentro da cidade de São Paulo. Como produto principal temos um site que traz diversas informações sobre reciclagem, como um mapa interativo onde o usuário consegue ver qual o ponto mais próximo onde ele pode reciclar determinado tipo de lixo, além de tutoriais, artigos e reportagens que conscientizem o cidadão sobre os benefícios da reciclagem e incentive o mesmo a fortalecer essa prática. 

Além disso, pretendemos desenvolver uma máquina apelidada de "GreenMachine", um tipo de reverse vending machine que irá ser instalada em locais públicos estratégicos. Nosso usuário poderá levar tipos selecionados de lixo reciclável (como vidro, alumínio, óleo e pilhas), inserir nessa máquina, e, através do seu cadastro, a máquina irá avaliar e depositar pontos para o usuário de acordo com a quantidade de material depositado. Esses pontos depois poderão ser trocados por benefícios, como crédito no Bilhete Único, desconto na conta de luz ou água, entre outros. 

# Arquitetura do projeto

### Dispositivo IoT

- **GreenMachine:** A máquina conterá um circuito baseado no Arduino que medirá o peso dos objetos depositados. Este dispositivo se comunicará pela internet com um banco de dados, onde os dados do usuário serão acessados, e o histórico de objetos pesados e os pontos gerados serão armazenados.

### Back-end

- **Pesagem:** O microcontrolador Arduino coletará informações do sensor de peso e converterá esses dados para gramas.
- **Comunicação:** O dispositivo IoT coletará dados do sensor da máquina e os enviará para um servidor ou banco de dados.
- **Banco de Dados:** Todas as informações coletadas na máquina serão vinculadas ao registro ou cadastro do usuário e armazenadas em um banco de dados.
- **Conversão:** Os dados em gramas serão convertidos em pontos para o usuário, levando em consideração o peso e o tipo de material.

### Front-end

- **Site:** Um site para web/mobile permitirá que os usuários acessem seus cadastros, verifiquem seus saldos de pontos, resgatem benefícios e acessem mapas e conteúdos relacionados à reciclagem.
- **Display:** Um display conectado à **GreenMachine** exibirá informações importantes para o usuário.

## Recursos Necessários / Implementação

### Dispositivo IoT

- **GreenMachine:** Utilizará o microcontrolador Arduino Uno R3, bem como componentes como sensor de peso, conversor A/D, display LCD e placa/módulo Wi-Fi ESP32 para comunicação com o servidor.

### Back-end

- **Tago:** Utilizaremos a plataforma online Tago.io para coletar os dados enviados pelo dispositivo IoT.
- **Banco de Dados:** Para construir o banco de dados, precisaremos de um protocolo de comunicação, um sistema de gerenciamento de banco de dados como o MySQL, linguagens de programação como Python e JavaScript, além de APIs.

### Front-end

- **Site:** O site será desenvolvido usando o framework React, com aplicação de HTML, CSS e JavaScript.

## Instruções de Uso e Dependências

- Para que o sistema funcione, é necessário montar o circuito com o Arduino, balança e display, e integrar esse circuito ao módulo Wi-Fi. Em seguida, carregue o código correspondente em suas memórias.
- Para que o código funcione corretamente, é preciso instalar e declarar as seguintes bibliotecas no início do código:

```c
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Arduino.h"
#include "WiFi.h"
#include "HTTPClient.h"
```

# Grupo
- André Lambert
- Bryan Willian
- Lucas Feijó
- Vitor Maia
