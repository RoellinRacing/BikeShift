# BikeShift

Creator: @carbon_gtv
Sequential Shift with a servo motor and an arduino uno.
here you can see a video:
https://www.instagram.com/reel/CwsSbrLoQdj/?utm_source=ig_web_copy_link&igsh=MzRlODBiNWFlZA==



Summary of the Project
Project: Automatic Gear Shifting with Servo Motors for a Car (without reverse gear; manual shifting)
Components:

- Arduino Uno
- PCA9685 for PWM control
- Servo Motors (150kg, 12V)
- Sequential gearbox from a Honda CBR 1000F (with neutral)
- Two buttons for the steering wheel (upshift and downshift)
- Clutch is manually operated
Connection of Components
Arduino Uno

Connect the 5V pin and GND pin of the Arduino Uno to the 5V and GND pins of the PCA9685.
Connect the SDA and SCL pins of the Arduino Uno to the SDA and SCL pins of the PCA9685.
PCA9685
A4 serves as SDA (Serial Data Line).
A5 serves as SCL (Serial Clock Line).

Connect the VCC and GND pins of the servo motor to the V+ and GND pins of the PCA9685.
Connect the signal cable of the servo motor to one of the PWM pins of the PCA9685.
Buttons

Connect one pin of each button to the GND of the Arduino.
Connect the other pin of each button to a digital pin of the Arduino (e.g., Pin 2 for upshifting and Pin 3 for downshifting).





### Arduino IDE Installation
1. If you haven't already, download the Arduino IDE from the [official website](https://www.arduino.cc/en/software) and install it.

### Adding Libraries
1. Open the Arduino IDE.
2. Go to `Sketch` -> `Include Library` -> `Manage Libraries...`.
3. In the search field, type `Adafruit PWM Servo Driver` and install the corresponding library.
4. You should also install the `Wire` library, which is usually pre-installed.

### Uploading the Code
1. Copy the [improved Arduino code](https://cpad.io/s/17d8f1be) and paste it into the Arduino IDE.
2. Select your Arduino board and port:
    - Go to `Tools` -> `Board` and choose `Arduino Uno`.
    - Go to `Tools` -> `Port` and select the port to which your Arduino is connected.
3. Click on the `Upload` button (the arrow pointing up in the IDE).
4. Wait for the message `Upload complete` to appear.


Ah, that explains a lot! Hardware issues can sometimes be challenging to diagnose. It's great that you've identified the problem.

### Calibration and Range of Values
The PWM values you can use for calibration depend on your specific servo motor. For most standard servo motors, PWM values typically range from about 150 to 600. These values usually correspond to angle positions of the servo motor.

- **150**: This is often the position for 0 degrees.
- **375**: This could be a good neutral middle position.
- **600**: This is often the position for 180 degrees.

However, these values are just guidelines and can vary depending on your specific servo motor. It's essential to perform calibration carefully to ensure that the servo motor shifts gears correctly.

### Calibration Steps
1. **Neutral Position**: Start by setting a neutral middle position. This is the value to which the servo motor returns after shifting gears.
2. **Gear Positions**: Test various PWM values to find the positions for each gear. Make a note of these values for later use in the code.
3. **Fine-Tuning**: After finding the basic values, you can begin fine-tuning to ensure reliable gear shifting.
