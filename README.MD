# LED Visualizer
This quick unmaintened project allows to do a simple visualizer using addressible LEDs. It can be controlled by a host computer over the serial port.
## Requirements :
### Arduino :
The libraries [ArduinoJson](https://arduinojson.org/) and [FastLED](https://github.com/FastLED/FastLED) are required in order to compile the Arduino sketch.
Make sure to use a 5V Microcontroller (ie: genuine Arduino Nano) if you want to control WS2812 LEDs, or use a Logic Level Converter between your µC and the LEDs to ensure proper voltage.
### Python :
The provided python example requires the pyserial library.
## Controlling the Arduino
The Arduino expects JSON dictionnaries, where the key indicates the command, and the value its parameter.
| Command | Description | Parameter | 
|--|--|--|
| R[n] | Sets the Red channel of the n'th LED | 0 to 255 |
| G[n] | Sets the Green channel of the n'th LED | 0 to 255 |
| B[n] | Sets the Blue channel of the n'th LED | 0 to 255 |
| brightness | Sets the strip's general brightness  | 0 to 255 |
| fadeall | Fade every LEDs to Black | 0 to 255, the lower the darker. |
| clear | Sets every LEDs to Black | any | 

**Example :** 
`{"R1":100,"G2":150,"B3":200,"fadeall":220}` Will set the first 3 LEDs to red, green and blue, and fade every led a bit to black.
