# SmartCity - Arduino

Este es el repository del proyecto final de la materia de **Sistemas Autoadaptables** de la especialización en Desarrollo de Software de la Universidad EAFIT en el año 2024. La materia trata sobre tecnologias relacionadas con IoT y systemas embebidos utilizando Arduino.

El proyecto busca darle funcionalidades a una maqueta que simula una ciudad inteligente o SmartCity como se muestra a continuación:

![SmartCity](smart-city-labels.png)

## Objetivos:

El proyecto busca responder 3 retos relacionados con los niveles de complejida y estrategia asociados a sistemas autoadaptables, clasificados por generaciones que van de la 0 a la 2, para el alcance de este proyecto, como se describe a continuación:

- **Generación 0**: Sistemas regulados por control de lazo cerrado cuyos setpoints son predeterminados. No pueden gestionar cambios durante su operación. Su funcionalidad y arquitectura no cambian y no optimizan su comportamiento. Ejemplo: un Sistema de iluminación con sensores tradicional.

- **Generación 1**: Tienen sistemas de control de lazo cerrado y pueden modificar sus setpoints de acuerdo a las condiciones del entorno (auto-ajuste y conciencia del contexto). Los procesos de adaptación los llevan a cabo a través de cambios en los modos de operación del sistema (SOM). Esto les permite una operación más eficiente.

- **Generación 2**: Tienen autoconcienciencia y autoadaptación. Entiende su rol en un sistema de sistemas. Aprende de su propia experiencia y optimiza su comportamiento de acuerdo a ello. La capacidad de autoadaptación le permite cambiar sus settings e incluso introducir cambios estructurales y operacionales en el sistema.

## Desarrollo:

La aproximaciòn para darle solución a los retos esta inspirada en un diseño modular, donde toda la lógica esta organizada en 4 módulos programados sobre c++ y cada módulo tiene una responsabilidad específica:

1) Client: se responsabiliza de las comunicaciones.
2) Components: se encarga de las funcionalidades asociadas a la medición de los sensores y la lectura del estado de actuadores.
3) Controllers: se encarga de utilizar y controlar los sensores y actuadores.
4) Utils: provee las constantes.

La ejecución se realiza sobre Arduino en los archivos .ino llamando a las funcionalidades que atienden cada generación.

Los casos de uso que se definieron en 2 tipos:

1) Alerta: son mensajes sobre cambios en los sensores de la maqueta.
2) Simulación del control de tráfico: es una simulación sobre cambios en los tiempos que pasan de rojo a verde para los semáforos de la maqueta.

Se usaron los elementos de la maqueta para atender dichos tipos de caso de uso de la siguiente manera:

- Sensores de luz: dependiendo de un límite de medición se encargarían de prender o a pagar las luces de las calles en la ciudad.
- Botones laterales de los semáforos: simulan abilitación del paro del tráfico cuándo hay personas con discapcidad visual que necesitan pasar la calle.
- Sensor de CO2: dependiendo de un límite alerta sobre el nivel de contaminación del aire.
- Sensor de próximidad: alerta sobre el estancamiento del tráfico cuando un cuerpo se aproxima a uno de los sensores.


