# Carrinho Motorizado

Este é um projeto de um carrinho motorizado controlado via Bluetooth utilizando um ESP32 e um controle de PS4. O objetivo do projeto é criar um veículo controlado remotamente, com funcionalidades de movimento e direção, explorando a integração de hardware e software.

## Índice

- [Visão Geral](#visão-geral)
- [Componentes](#componentes)
- [Circuito](#circuito)
- [Instalação](#instalação)
- [Uso](#uso)
- [Licença](#licença)

## Visão Geral

O projeto utiliza um ESP32 para controlar os motores do carrinho e receber comandos de um controle de PS4 via Bluetooth. A arquitetura é projetada para ser modular, permitindo a fácil substituição de componentes ou a adição de novas funcionalidades.

## Componentes

- **ESP32**: Microcontrolador principal que gerencia os motores e a comunicação Bluetooth.
- **Controle PS4**: Utilizado para enviar comandos de direção e velocidade ao ESP32.
- **Motor DC**: Responsável pelo movimento do carrinho.
- **Servo Motor**: Usado para controlar a direção das rodas.
- **Módulo L298N**: Driver de motor para controle de motores DC.
- **Bateria**: Fonte de alimentação do carrinho.

## Circuito

O circuito é montado conectando os pinos do ESP32 ao driver de motor L298N, ao motor DC e ao servo motor. O controle PS4 se conecta ao ESP32 via Bluetooth.

### Esquema de Conexão

- **Motor DC**: Conectado ao módulo L298N.
- **Servo Motor**: Conectado diretamente ao ESP32.
- **L298N**: Controlado pelo ESP32 para gerenciar o motor DC.
- **ESP32**: Configurado para receber comandos via Bluetooth do controle PS4.

## Instalação

1. **Clonar o repositório**:
   ```bash
   git clone https://github.com/seu-usuario/carrinho-motorizado.git
   cd carrinho-motorizado
