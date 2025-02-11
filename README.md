# Controle de Servo Motor e LED com Raspberry Pi Pico

Este projeto implementa o controle de um **servo motor** e de um **LED** usando o **Raspberry Pi Pico (RP2040)**. O servo motor é movido para diferentes ângulos, enquanto o LED exibe um efeito de **fade in/fade out** utilizando interrupções de **PWM**.

## 📌 Funcionalidades
- Controle do **ângulo do servo motor** (0° a 180°).
- **Efeito de fade** no LED utilizando interrupções de PWM.
- Movimento **suave e progressivo** do servo motor.
- Mensagens de depuração via **`printf`**.

## 🛠️ Tecnologias Utilizadas
- **Linguagem C**
- **Raspberry Pi Pico SDK**
- **PWM (Pulse Width Modulation)**
- **Interrupções de Hardware**
- **Simulação no Wokwi**

## 🖥️ Requisitos
- **Wokwi** para simulação
- Placa Raspberry Pi Pico (na simulação, componente virtual)
- Servomotor compatível com **PWM** (na simulação, um modelo virtual)
- LED e resistor de **330Ω** (na simulação, componentes virtuais)
- **SDK do Raspberry Pi Pico** corretamente configurado (caso seja usado em hardware real)

### 2️⃣ Clonar este repositório
```sh
git clone https://github.com/camillerodriguees/ServoMotor.git
```

## 🎯 Como Funciona
✅ **Servo Motor:** Controlado pelo PWM no **pino 22**.
✅ **LED:** PWM no **pino 12** com **interrupções** para criar o efeito de fade.
✅ **Interrupção de PWM:** Atualiza o brilho do LED dinamicamente.
✅ **Simulado no Wokwi**, sem necessidade de hardware físico.

## 📖 Link do vídeo da Explicação
```sh
https://drive.google.com/file/d/1QLLstPu26DEA8J5xqBtMbfh-yDkYSrrR/view?usp=sharing
```

