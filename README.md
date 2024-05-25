# SmartCity - Arduino

Este es el repositorio del proyecto final de la materia de **Sistemas Autoadaptables** de la especialización en Desarrollo de Software de la Universidad EAFIT en el año 2024. La materia trata sobre tecnologias relacionadas con IoT y systemas embebidos utilizando Arduino.

El proyecto busca darle funcionalidades a una maqueta que simula una ciudad inteligente o SmartCity.

La maqueta esta configurada de la siguiente manera:

![SmartCity](smart-city-labels.png)

## Objetivos:

El proyecto esta conformado por 3 retos relacionados con los niveles de complejida y estrategia asociados a sistemas autoadaptables.

 El alcance de este proyecto cubre las generaciones que van de la 0 a la 2, como se describe a continuación:

1. **Generación 0**: Sistemas regulados por control de lazo cerrado cuyos setpoints son predeterminados. No pueden gestionar cambios durante su operación. Su funcionalidad y arquitectura no cambian y no optimizan su comportamiento. Ejemplo: un Sistema de iluminación con sensores tradicional.

2. **Generación 1**: Tienen sistemas de control de lazo cerrado y pueden modificar sus setpoints de acuerdo a las condiciones del entorno (auto-ajuste y conciencia del contexto). Los procesos de adaptación los llevan a cabo a través de cambios en los modos de operación del sistema (SOM). Esto les permite una operación más eficiente.

3. **Generación 2**: Tienen autoconcienciencia y autoadaptación. Entiende su rol en un sistema de sistemas. Aprende de su propia experiencia y optimiza su comportamiento de acuerdo a ello. La capacidad de autoadaptación le permite cambiar sus settings e incluso introducir cambios estructurales y operacionales en el sistema.

## Estructura del Proyecto:

La aproximación para darle solución a los retos esta inspirada en un diseño modular, donde toda la lógica esta organizada en 4 módulos programados sobre c++ y cada módulo tiene una responsabilidad específica:

1) Client: se responsabiliza de las comunicaciones.
2) Components: se encarga de las funcionalidades asociadas a la medición de los sensores y la lectura del estado de actuadores.
3) Controllers: se encarga de utilizar y controlar los sensores y actuadores.
4) Utils: provee las constantes y el mapeo de los pines que envian y reciben señales de cada elemento de la maqueta.

La ejecución se realiza sobre Arduino en los archivos .ino.

## Casos de uso identificados:

Los casos de uso se definieron en 2 tipos:

1) Alerta

Son mensajes sobre cambios en los sensores de la maqueta que incluirían:

- Botones laterales de los semáforos: alerta sobre la solicitud del paro del tráfico cuándo hay personas con discapcidad visual que necesitan pasar la calle.
- Sensor de CO2: dependiendo de un límite alerta sobre el nivel de contaminación del aire.
- Sensor de próximidad: alerta sobre el estancamiento del tráfico cuando un cuerpo se aproxima a uno de los sensores.

2) Simulación del control de tráfico y la iluminación

- Semáforos: es una simulación sobre cambios en los tiempos que pasan de rojo a verde para los semáforos de la maqueta.
- Sensores de luz: dependiendo de un límite de medición se encargarían de prender o a pagar las luces de las calles en la ciudad.

## Comunicaciones:

Las comunicaciones entre Arduino y la máquina o computador conectado via USB, se gestionan por generación de la siguiente manera:

- Generación 0: 

No aplica, debido a que es solo pruebas de las funcionalidades.

- Generación 1: 

Se trata de una comunicación de Arduino hacia la máquina o computador, para facilitar la salida de los mensajes en Arduino hacia la red, como se explica a continuación:

Arduino envia menajes de alerta y a tráves de python con la libreria Flask, se publican en el localhost las alertas. La carpeta "MonitorAlerts" contiene la lógica de python.

- Generación2: 

Consiste en la comunicación de la máquina hacia Arduino para simular variables externas, cómo alto o bajo flujo vehícular, resolviendose de la siguiente manera:

Desde la máquina utilizando python se envian comandos a Arduino y este dependeniendo del valor del comando ejecuta una acción. La carpeta "TrafficSimulator" contiene la lógica de python.





