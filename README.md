# Alarma de Proximidad con Arduino UNO

Proyecto desarrollado para la asignatura **Hardware Digital** de la Universidad de Valparaíso.

## Descripción del proyecto

Este proyecto consiste en un sistema de medición de distancia con indicación sonora y visual.  
Se utiliza una placa Arduino UNO junto a un sensor ultrasónico HC-SR04 para detectar la cercanía de un objeto.

Cuando la distancia medida es menor a 20 cm, el sistema enciende un LED y activa un buzzer como alarma sonora.  
Además, se incorpora un pulsador que permite activar o desactivar el buzzer sin apagar completamente el sistema.

## Integrantes

- Maria Triana
- Camila Montes
- Fernanda Godoy
- Gabriela Ovalle

## Componentes utilizados

- Arduino UNO
- Sensor ultrasónico HC-SR04
- LED
- Buzzer
- Pulsador
- Resistencia
- Protoboard
- Cables jumper

## Conexiones del circuito

| Componente | Pin Arduino |
|---|---|
| TRIG del HC-SR04 | D8 |
| ECHO del HC-SR04 | D9 |
| Buzzer | D4 |
| LED | D10 |
| Pulsador | D2 |
| VCC del HC-SR04 | 5V |
| GND | GND |

## Funcionamiento del sistema

El sensor HC-SR04 mide la distancia entre el sensor y un objeto.  
Arduino calcula esta distancia a partir del tiempo que demora la señal ultrasónica en ir y volver.

Si la distancia es mayor a 0 cm y menor a 20 cm, se activa el LED de alerta.  
Si el buzzer está habilitado, también se emite una alarma sonora.

El pulsador permite cambiar el estado del buzzer entre activado y desactivado.

## Archivos del repositorio

- `alarma_proximidad.ino`: código fuente del proyecto de alarma de proximidad en Arduino IDE.
- `Informe técnico.pdf`: informe técnico del proyecto.
- `esquema_conexiones.png`: esquema de conexión del circuito.
- `Imagen del diagrama de bloques.png`: diagrama de bloques del sistema.
- `Foto real de tu Arduino armado.jpeg`: evidencia del montaje físico.

## Pruebas realizadas

| Prueba | Resultado esperado |
|---|---|
| Objeto a más de 20 cm | LED apagado y buzzer apagado |
| Objeto a menos de 20 cm | LED encendido y buzzer activo |
| Botón presionado | Buzzer desactivado |
| Botón presionado nuevamente | Buzzer activado |
| Objeto retirado | LED apagado y buzzer apagado |

## Mejora futura

Como mejora futura, se propone incorporar un potenciómetro conectado al pin A0 para ajustar el umbral de activación mediante una lectura analógica con `analogRead()`.

Esto permitiría utilizar el conversor analógico-digital ADC del microcontrolador ATmega328P y hacer el sistema más flexible.
