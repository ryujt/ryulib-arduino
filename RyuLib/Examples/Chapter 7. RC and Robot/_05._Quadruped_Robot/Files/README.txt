                   .:                     :,                                          
,:::::::: ::`      :::                   :::                                          
,:::::::: ::`      :::                   :::                                          
.,,:::,,, ::`.:,   ... .. .:,     .:. ..`... ..`   ..   .:,    .. ::  .::,     .:,`   
   ,::    :::::::  ::, :::::::  `:::::::.,:: :::  ::: .::::::  ::::: ::::::  .::::::  
   ,::    :::::::: ::, :::::::: ::::::::.,:: :::  ::: :::,:::, ::::: ::::::, :::::::: 
   ,::    :::  ::: ::, :::  :::`::.  :::.,::  ::,`::`:::   ::: :::  `::,`   :::   ::: 
   ,::    ::.  ::: ::, ::`  :::.::    ::.,::  :::::: ::::::::: ::`   :::::: ::::::::: 
   ,::    ::.  ::: ::, ::`  :::.::    ::.,::  .::::: ::::::::: ::`    ::::::::::::::: 
   ,::    ::.  ::: ::, ::`  ::: ::: `:::.,::   ::::  :::`  ,,, ::`  .::  :::.::.  ,,, 
   ,::    ::.  ::: ::, ::`  ::: ::::::::.,::   ::::   :::::::` ::`   ::::::: :::::::. 
   ,::    ::.  ::: ::, ::`  :::  :::::::`,::    ::.    :::::`  ::`   ::::::   :::::.  
                                ::,  ,::                               ``             
                                ::::::::                                              
                                 ::::::                                               
                                  `,,`


http://www.thingiverse.com/thing:1596784
 CubeBot - Quadruped Robot 8 DOF by hkucs-makerlab is licensed under the Creative Commons - Attribution license.
http://creativecommons.org/licenses/by/3.0/

# Summary

This is low building cost 8 DOF quadruped robot using [cheap tower pro  9g servo](http://goo.gl/nzu8qV).  The body is the chamber for holding 2 of 18650 lithium batteries.  The implementation shown on [video demo](https://youtu.be/8AihaEQxQWQ) is using Arduino Nano with this [holder](http://www.thingiverse.com/thing:1531611). Parts are joined using M3x8 and M2x6 screws.

The arduino code can be download [here](https://github.com/hkucs-makerlab/cubebot). The program assumes that all servos should be set default to [90 degree](http://makerlab.cs.hku.hk/index.php/en/adjusting-a-rc-servo-to-90-degree), see the drawing for the posure. The servos are connected to Arduino pins D2-D9 wiring as following
D2 ->leg0A servo
D3 ->leg0B servo
D4 ->leg1A servo
D5 ->leg1B servo
D6 ->leg2A servo
D7 ->leg2B servo
D8 ->leg3A servo
D9 ->leg3B servo

****An updated version is in [project home page](http://makerlab.cs.hku.hk/index.php/en/making-cubebot), see this video demo https://youtu.be/CPVZC3gLzEo

# Print Settings

Printer Brand: RepRap
Printer: prusa i3
Rafts: Doesn't Matter
Supports: Yes
Resolution: 0.2mm
Infill: 30%