![Untitled](./readme_assets/Untitled.png)

Visualize data in real time from your Sensirion CO2 sensor!

## 🔧 Preparing the Hardware

1. Download the “Arduino IDE”
2. Install the Sensirion library called "Sensirion I2C SCD4x"
3. [Install a new board](https://www.electroniclinic.com/esp32-arduino-ide-board-manager-installation-espressif-esp32-wroom/#ESP32_Arduino_IDE_Board_Manager_URL_link) 
4. Select the "ESP32 Dev Module": `Tools > Board > esp32 > ...`
5. Select the right port of your board
    
    <img src="./readme_assets/Untitled%202.png" width="300">
    
6. Load a demo file to test it out: `File > Examples > 01. Basics > BareMinumum`
    
4. Press the arrow to flash your ESP32. As soon as you establish a connection, hold the boot button, then press the reset button once.

    <img src="./readme_assets/Untitled%203.png" width="50">

5. Connect the sensor to the ESP32 as shown [here](https://developer.sensirion.com/sensirion-products/scd4x-co2-sensors/) or [here](https://github.com/Sensirion/arduino-i2c-scd4x/blob/master/README.md):

    First connect ground and power pins from sensor to the ESP32 and then connect the other cables to any pin you want. 
    
    The green cable is the SDA (in the image below we have chosen pin 4) and the yellow cable is the SCL (in our case we have chosen pin 2).

    <img src="./readme_assets/Untitled%204.png" width="100">
        
6. Connect to the ESP32 from your PC after the sensor was connected to it

    i. - Choose `File > Examples  > Sensirion I2C SCD4x > exampleUsage`. <br>
    ii. - Add `Wire.begin(4, 2);` after the `while (!Serial)` loop. <br>
    iii. - Press the arrow in the top left corner to Upload. <br>
    iv. - As soon as you establish a connection, hold the boot button, then press the reset button once - voila!

7. Establish a serial connection and read the live data stream [using terminal based tools](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/establish-serial-connection.html#check-port-on-linux-and-macos) or [a lightweight C library](https://gitlab.com/Teuniz/RS-232).

## 🔧 Running the Software

0. Attach the ESP23 microcontroller and the sensor to your Linux PC (not Windows or MacOs, also Windows-WSL doesn't work because peripherals from the `/dev` path don't get emulated correctly).
1. You may need to update the path to your device in `backend/main.c`.
2. In the `backend` directory run the `build.sh` script and then execute the `main` executable to run the backend.
3. Then open up the `js_frontend/index.html` file and enjoy the sweet real time visualization!
