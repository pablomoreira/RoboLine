RobotLine
========

Line follower robot with Arduino. The line is marked in white board using a black marker


![Imagen][id]

El robot fue desarrollado por el grupo de robótica de la Facultad Regional Concordia de UTN para el Museo Interactivo de Ciencia de La CAFEGS Concordia.
Está Construido con 2 servomotores trucados, 2 CNY70 y  una placa clon de un Arduino UNO.

Funcionamiento:
---------------
El robot en la parte frontal tiene 2 sensores CNY70 que permiten detectar la intensidad de la luz infrarroja, cuando la superficie es blanca el reflejo es mayor, cuando la superficie es opaca o negra la cantidad de luz infrarroja recibida es menor.
Marcando una linea negra sobre una superficie oscura y colocando dos sensores frontales a ambos lados de esta se puede diseñar un mecanismo o robot capaz de seguir un circuito.

Si ambos sensores están sobre una superficie blanca el robot seguirá derecho.
![Imagen][id0]  

Agradecimientos:
----------------
* Ing. Mario Chury.
* Ing. Carlos Blanc.
* Ing Jorge Penco.
* Matias Vallejos.


El siguiente vídeo es una demostración de su funcionamiento.
 
[![RobotLine Video demostracion](http://img.youtube.com/vi/SeZ32AWF-9Q/0.jpg)](http://www.youtube.com/watch?v=SeZ32AWF-9Q)

[id0]: https://raw.githubusercontent.com/pablomoreira/RoboLine/master/img/ex0.jpg ""
[id1]: https://raw.githubusercontent.com/pablomoreira/RoboLine/master/img/ex1.jpg ""
[id]: https://raw.githubusercontent.com/pablomoreira/RoboLine/master/img/roboline.jpg " "
