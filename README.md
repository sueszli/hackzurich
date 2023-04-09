![Untitled](./readme_assets/Untitled.png)

Visualize data in real time from your Sensirion CO2 sensor!

<br><br><br>

## 🔧 Preparing the Hardware

### *1) Flashing the ESP32 microcontroller*

#### Setting up the IDE

1. Download the “Arduino IDE” for your operating system
2. Install the library (must be from Sensirion, because we are using their sensor)
    
    <img src="./readme_assets/Untitled%201.png" width="200">
    
3. Install a new board
    
    [https://www.electroniclinic.com/esp32-arduino-ide-board-manager-installation-espressif-esp32-wroom/#ESP32_Arduino_IDE_Board_Manager_URL_link](https://www.electroniclinic.com/esp32-arduino-ide-board-manager-installation-espressif-esp32-wroom/#ESP32_Arduino_IDE_Board_Manager_URL_link)
    
4. once you have that installed, you can select the "ESP32 Dev Module" under `Tools > Board > esp32 > ...`
5. Select the right board and port
    
    <img src="./readme_assets/Untitled%202.png" width="300">
    
6. Load a demo file to test it out
    
    `File > Examples > 01. Basics > BareMinumum`
    
4. Press the arrow to flash

    <img src="./readme_assets/Untitled%203.png" width="50">

As soon as you establish a connection, hold the boot button, then press the reset button once.

<br><br>

#### Connecting the sensor to the ESP32

Official tutorials:

- [https://developer.sensirion.com/sensirion-products/scd4x-co2-sensors/](https://developer.sensirion.com/sensirion-products/scd4x-co2-sensors/)

- [https://github.com/Sensirion/arduino-i2c-scd4x/blob/master/README.md](https://github.com/Sensirion/arduino-i2c-scd4x/blob/master/README.md)

Unofficial tutorial:

1. Connect ground and power pins from sensor to the ESP32
    
    <img src="./readme_assets/Untitled%204.png" width="200">
    
2. Connect the other cables to any pin you want
    
    Green cable = SDA (in our case: pin 4)
    
    Yellow cable = SCL (in our case: pin 2)

<br><br>

#### Connecting to the ESP32 from your PC after the sensor was connected to it

1. Choose `File > Examples  > Sensirion I2C SCD4x > exampleUsage`.
2. Add `Wire.begin(4, 2);` after the `while (!Serial)` loop.
3. Press the arrow in the top left corner to Upload.

As soon as you establish a connection, hold the boot button, then press the reset button once - voila!

<br><br>

### 2) Establishing a serial connection and reading the live data stream

Using terminal based tools:

- [https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/establish-serial-connection.html#check-port-on-linux-and-macos](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/establish-serial-connection.html#check-port-on-linux-and-macos)

Using a lightweight C library:
- [https://gitlab.com/Teuniz/RS-232](https://gitlab.com/Teuniz/RS-232)


<br><br><br>

## 🔧 *Running the Software*

0. Attach the ESP23 microcontroller and the sensor to your Linux PC (not Windows or MacOs, also Windows-WSL doesn't work because peripherals from the `/dev` path don't get emulated correctly).
1. You may need to update the path to your device in `backend/main.c`.
2. In the `backend` directory run the `build.sh` script and then execute the `main` executable to run the backend.
3. Then open up the `js_frontend/index.html` file.
4. Enjoy the sweet real time visualization.
