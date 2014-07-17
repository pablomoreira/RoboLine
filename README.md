RobotLine
========

Line follower robot with Arduino. The line is marked in white board using a black marker


![Imagen][id]

Introducción
-------------

El robot fue desarrollado por el grupo de robótica de la Facultad Regional Concordia de la Universidad Tecnológica Nacional para el Museo Interactivo de Ciencia (MIC) de la CAFEGS Concordia. Está Construido con 2 servomotores trucados, es decir se le ha posibilitado girar en ambos sentidos indefinidamente (los servomotores standard solo pueden recorrer un arco que no supera los 210º dependiendo del fabricante).
Consta también de dos sensores de reflexión CNY70 que incorpora internamente un emisor de luz infrarroja y de su respectivo receptor y como sistema de control  una placa clon de un microcontrolador Arduino UNO.
En la parte frontal se ubican los dos  sensores CNY70 que permiten detectar la intensidad de la luz infrarroja que se refleja  de la superficie (siendo esta mayor  cuando la superficie es blanca y caso contrario cuando la superficie es  opaca o negra) . Utilizando un marcador negro de pizarra se puede dibujar un camino para que el vehículo lo siga por medio de los sensores de reflexión y un programa de control adecuado almacenado previamente en el Arduino Uno.


Sensor infrarrojo
-----------------

En la imagen 1 el rebote de la luz infrarroja es mayor que en la imagen 2 debido al color de la superficie. 

![Imagen][sen]

Funcionamiento
--------------
Si ambos sensores están sobre una superficie blanca el robot seguirá derecho.

![Imagen][seg]  

Cuando un sensor detecta la linea los motores deben corregir el rumbo aumentando la velocidad del motor contrario o disminuyendo la velocidad del motor relacionado al sensor que detectó el cambio de contraste en superficie.

![Imagen][dob]

Fenómeno Físico
---------------

La luz infrarroja, como así la visible, puede ser reflejada, absorbida o refractada. Las superficies blancas son capaces de reflejar mas luz que las oscuras o negras.

El sensor infrarrojo utiliza este fenómeno para determinar la ubicación de la linea negra sobre la superficie blanca. Utiliza un led que emite luz infrarroja y un fototransistor capaz de detectarla. 


EL fenómeno se aplica en los controles remotos de los electrodomésticos que utilizan la luz infrarroja para enviar y recibir información.


Agradecimientos
---------------
* Ing. Mario Chury.
* Ing. Carlos Blanc.
* Ing. Jorge Penco.
* Tec. Matias Vallejos.



Vídeo demostración
------------------
 
[![RobotLine Video demostracion](http://img.youtube.com/vi/SeZ32AWF-9Q/0.jpg)](http://www.youtube.com/watch?v=SeZ32AWF-9Q)

Foto en el museo
-----------------
![Imagen][ex3]

Autor: Pablo Moreira <pablolokekieran@gmail.com>

[sen]: https://raw.githubusercontent.com/pablomoreira/RoboLine/master/img/ex2.png "Sensor"
[seg]: https://raw.githubusercontent.com/pablomoreira/RoboLine/master/img/ex0.png "Seguir"
[dob]: https://raw.githubusercontent.com/pablomoreira/RoboLine/master/img/ex1.png "Doblar"
[id]: https://raw.githubusercontent.com/pablomoreira/RoboLine/master/img/roboline.jpg " "
[ex3]: https://raw.githubusercontent.com/pablomoreira/RoboLine/master/img/ex3.jpg " "
