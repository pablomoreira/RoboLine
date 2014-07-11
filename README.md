RobotLine
========

Line follower robot with Arduino. The line is marked in white board using a black marker


![Imagen][id]

Introducción

---------------
El robot fue desarrollado por el grupo de robótica de la Facultad Regional Concordia de UTN para el Museo Interactivo de Ciencia de La CAFEGS Concordia.
Está Construido con 2 servomotores trucados, 2 CNY70 y  una placa clon de un Arduino UNO.

En la parte frontal tiene 2 sensores CNY70 que permiten detectar la intensidad de la luz infrarroja, cuando la superficie es blanca el reflejo es mayor, cuando la superficie es opaca o negra la cantidad de luz infrarroja recibida es menor.
Marcando una linea negra sobre una superficie oscura y colocando dos sensores frontales a ambos lados de esta se puede diseñar un mecanismo o robot capaz de seguir un circuito.

Sensor infrarrojo.
-------------------------------------------------------------
En la imagen 1 el rebote de la luz infrarroja es mayor que en la imagen 2 debido al color de la superficie. 

![Imagen][sen]

Si ambos sensores están sobre una superficie blanca el robot seguirá derecho.

![Imagen][seg]  

Cuando un sensor detecta la linea los motores deben corregir el rumbo aumentando la velocidad del motor contrario o disminuyendo la velocidad del motor relacionado al sensor que detectó el cambio de contraste en superficie.

![Imagen][dob]

Fenómeno Físico
---------------
La luz infrarroja, como así la visible, puede ser reflejada, absorbida o refractada. Las superficies blancas son capaces de reflejar mas luz que las oscuras o negra.
El sensor infrarrojo utiliza este fenómeno para determinar la ubicación de la linea negra sobre la superficie blanca. Utiliza un led que emite luz infrarroja y un foto diodo capaz de detectarla. 
Los controles remotos de los electrodomésticos utilizan el mismo método para su funcionamiento.  


   
Agradecimientos:
----------------
* Ing. Mario Chury.
* Ing. Carlos Blanc.
* Ing. Jorge Penco.
* Tec. Matias Vallejos.



Vídeo demostración.
-------------------
 
[![RobotLine Video demostracion](http://img.youtube.com/vi/SeZ32AWF-9Q/0.jpg)](http://www.youtube.com/watch?v=SeZ32AWF-9Q)

Autor: Pablo Moreira <pablolokekieran@gmail.com>

[sen]: https://raw.githubusercontent.com/pablomoreira/RoboLine/master/img/ex2.png "Sensor"
[seg]: https://raw.githubusercontent.com/pablomoreira/RoboLine/master/img/ex0.png "Seguir"
[dob]: https://raw.githubusercontent.com/pablomoreira/RoboLine/master/img/ex1.png "Doblar"
[id]: https://raw.githubusercontent.com/pablomoreira/RoboLine/master/img/roboline.jpg " "
