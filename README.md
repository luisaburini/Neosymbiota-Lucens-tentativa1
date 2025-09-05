# Neosymbiota Lucens tentativa 1

Instruções de montagem para o trabalho Neosymbiota Lucens tentativa 1

Essa parte do trabalho (do rastreador de luz) foi montado a partir da [ref 1](https://www.usinainfo.com.br/blog/rastreador-solar-com-arduino-um-seguidor-solar-atraves-de-ldr/?srsltid=AfmBOopmhUIaa4iWFgExYoY_OMAmqnunysOihkISRG3wj58gcAvz8ka0).
O rastreador usa LDR (Light Dependent Resistor, isto é, resistores variáveis com a luz) para detectar a presença de luz em 4 quadrantes divididos por uma altura, de modo que faça sombra nos demais LDRs quando não está alinhado com a fonte de luz.
Para ajustar a posição do circuito de modo a se alinhar com a fonte de luz, foram usados 2 servo motores MG966R, que são motores servo de rotação CONTÍNUA. Um motor gira entre esquerda e direita na horizontal, e o outro gira para cima e para baixo, na vertical, perpendicular ao outro motor.
```
            |   
     A2     |     A0    
------------|-------------
     A3     |     A1
            |
```

O algoritmo funciona a partir da diferença entre a luz percebida entre os LDRs (conectados em A0, A1, A2, A3). Quando a luz tem mais intensidade:
- A direita, o motor horizontal gira no sentido ANTI HORARIO
- A esquerda, o motor horizontal gira no sentido HORARIO
- Acima, o motor vertical gira no sentido ANTI HORARIO
- Abaixo, o motor vertical gira no sentido HORARIO

## *UMA OBSERVAÇÃO IMPORTANTE*

O servo motor utilizado é de rotação contínua, então, apesar das conexões serem idênticas ao do motor servo de passo, o motor de rotação contínua gira 360 graus. Também, a escrita nele não indica quantos graus o motor virará, na verdade, ele usa 
- 0 para rotação no sentido HORARIO
- 90 para PARAR
- 180 para rotação no sentido ANTI HORARIO

![Diagrama do projeto](./imgs/rastreador.jpg)
Créditos da imagem para [ref 1](https://www.usinainfo.com.br/blog/rastreador-solar-com-arduino-um-seguidor-solar-atraves-de-ldr/?srsltid=AfmBOopmhUIaa4iWFgExYoY_OMAmqnunysOihkISRG3wj58gcAvz8ka0)

## Funcionalidades

Integração do Arduino UNO com

* Rastreador de luz [ref 1](https://www.usinainfo.com.br/blog/rastreador-solar-com-arduino-um-seguidor-solar-atraves-de-ldr/?srsltid=AfmBOopmhUIaa4iWFgExYoY_OMAmqnunysOihkISRG3wj58gcAvz8ka0)
* Placa solar: [ref 2](https://www.paraisodosbits.com.br/2016/11/09/usando-o-arduino-com-painel-solar/), [ref 3](https://www.instructables.com/Self-Sufficient-Arduino-Board/), [ref 4](https://docs.arduino.cc/learn/electronics/power-pins/)
* Bomba aquática submersível: [ref 5](https://www.youtube.com/watch?v=HBGYIuBC3BQ), [ref 6](https://www.youtube.com/watch?v=yZqnqxHI59Q)



## Componentes

Proposta de conexões com 2 motores servo e o circuito com 4 LDR para detectar a direção da luz

* Bomba
* Placa solar
* Bateria 9V recarregável
* 4 LDR
* 4 resistores 220 ohm
* 2 servo motores