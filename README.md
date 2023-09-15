# Edge Computing | Sprint 3 | Desenvolvimento da arquitetura para uma aplicação IoT

# Objetivo
O objetivo desta tarefa é desenvolver a arquitetura inicial de uma aplicação IoT capaz de receber e transmitir dados
provenientes de dispositivos conectados.

# Resumo do projeto
Nosso projeto, ***"TheGreenProject"***, tem como objetivo principal incentivar a reciclagem de lixo dentro da cidade de São Paulo. Como produto principal temos um site que traz diversas informações sobre reciclagem, como um mapa interativo onde o usuário consegue ver qual o ponto mais próximo onde ele pode reciclar determinado tipo de lixo, além de tutoriais, artigos e reportagens que conscientizem o cidadão sobre os benefícios da reciclagem e incentive o mesmo a fortalecer essa prática. 

Além disso, pretendemos desenvolver uma máquina apelidada de ***"GreenMachine"***, um tipo de reverse vending machine que irá ser instalada em locais públicos estratégicos. Nosso usuário poderá levar tipos selecionados de lixo reciclável (como vidro, alumínio, óleo e pilhas), inserir nessa máquina, e, através do seu cadastro, a máquina irá avaliar e depositar pontos para o usuário de acordo com a quantidade de material depositado. Esses pontos depois poderão ser trocados por benefícios, como crédito no Bilhete Único, desconto na conta de luz ou água, entre outros. 

# Arquitetura do projeto

### Dispositivo IoT

<li><b>GreenMachine:</b> A máquina irá conter, no seu interior, um circuito utilizando Arduino que irá fazer a medição de peso do objeto depositado. Esse disposito vai se comunicar via internet com um banco de dados que irá acessar o cadastro do usuário, armazenar o seu histórico de objetos pesados e pontos gerados.</li>

### Back-end

<li><b>Pesagem:</b> O microcontrolador Arduino irá obter informações do sensor de peso e fazer a conversão para unidade de gramas.</li>
<li><b>Comunicação:</b> O dispositivo IoT irá fazer a coleta de dados do sensor da máquina e enviar os mesmos para o servidor/banco de dados.</li>
<li><b>Banco de dados:</b> Todas as informações captadas na máquina serão linkadas a um registro/cadastro do usuário e salvas num banco de dados.</li>
<li><b>Conversão:</b> Os dados em gramas serão convertidos para pontos para o usuário, de acordo com o peso e o tipo de material.</li>

### Front-end

<li><b>Site:</b> Site para web/mobile onde os usuários conseguem acessar seu cadastro, ver seu saldo de pontos, efetuar resgate de benefícios, além de acessar mapas e conteúdos sobre reciclagem.</li>
<li><b>Display:</b> O display conectado à <b>GreenMachine</b> poderá exibir informações importantes ao usuário</li>

# Recursos necessários / Implementação

### Dispositivo IoT
<li><b>GreenMachine:</b> Irá utilizar o microcontrolador Arduino Uno R3, além de componentes como sensor de peso, conversor A/D, display LCD, e placa/módulo Wi-Fi ESP32 para fazer a comunicação com servidor.</li>

### Back-end
<li><b>Tago:</b> Iremos utilizar a plataforma online Tago.io para realizar coleta dos dados enviados pelo dispositivo IoT.</li>
<li><b>Banco de dados:</b> Para construirmos o banco de dados iremos precisar de um protocolo de comunicação, um sistema de gerenciamento como MySQL, uma linguagem de programação como Python e JavaScript, além de APIs. </li>  

### Front-end
<li><b>Site:</b> O site será construído utilizando o framework React e aplicando HTML, CSS e JavaScript.</li>  

# Instruções de uso, dependências

<li>Para fazer o sistema funcionar, precisamos montar o circuito com o Arduino, balança e display. Depois, integrar esse circuito ao módulo Wi-Fi. Então, carregar cada respectivo código em suas memórias.</li>
<li>Para o código funcionar corretamente, é preciso instalarmos e declararmos no começo do código as seguintes libraries:</li>

```c
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Arduino.h"
#include "WiFi.h"
#include "HTTPClient.h"
```

# Requisitos de entrega

### Entrega 1 - Vídeo Explicativo (60 pontos)
Criar um vídeo de até 3 minutos e disponibilizá-lo publicamente por meio de um link (por exemplo, YouTube, Vimeo, etc.), abordando os seguintes pontos:

<details>
  <summary>Introdução (20 pontos):</summary>

  <br>

  <li>Explicar os conceitos envolvidos na Internet das Coisas (IoT) e a importância dessa tecnologia.</li>
  <li>Apresentar a arquitetura adotada para a aplicação IoT, destacando os componentes principais e como eles interagem entre si.</li>
</details>

<details>
  <summary>Desenvolvimento (20 pontos):</summary>

  <br>
  
  <li>Demonstrar a instalação de uma plataforma de IoT em um CSP (Cloud Service Provider) ou VM (Virtual Machine) local.</li>
  <li>Explicar os passos necessários para configurar a plataforma de IoT, como a criação de dispositivos virtuais, definição de
  protocolos de comunicação e outras configurações relevantes.</li>
  <li>Especificar corretamente o hardware a ser utilizado com base nos requisitos do projeto.</li>
</details>

<details>  
  <summary>Demonstração (20 pontos):</summary>

  <br>
  
  <li>Executar uma collection básica, demonstrando o funcionamento da plataforma de IoT.</li>
  <li>Incluir um health check para verificar o status da aplicação.</li>
  <li>Mostrar a criação de uma entidade lógica de dispositivo IoT, destacando as informações necessárias e como esses dispositivos
  serão usados na aplicação.</li>
</details>  

### Entrega 2 - Repositório GitHub (40 pontos)
Disponibilizar um repositório GitHub contendo os seguintes itens:

<details>
  <summary>Arquivo README (30 pontos):</summary>

  <br>
  
  <li>Elaborar um README completo e bem estruturado, descrevendo detalhes do projeto.</li>
  <li>Incluir um draft da arquitetura proposta para a solução IoT, envolvendo IoT devices, back-end e front-end.</li>
  <li>Descrever os recursos necessários para implementar a solução, considerando os dispositivos IoT, o back-end e o front-end.</li>
  <li>Apresentar instruções de uso, requisitos, dependências e demais informações relevantes.</li>
</details>

<details>
  <summary>Códigos Fonte (10 pontos):</summary>

  <br>
  
  <li>Incluir os códigos desenvolvidos e os arquivos necessários para o funcionamento da aplicação e sua replicação.</li>
</details>
