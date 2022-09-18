# CHack

# 🧑‍💻 *Team members*

Mateusz / @marzipan

Witold / @wdrz

Fred / @FredW

Yahya / @sueszli

<br><br><br>

# 📃 *Project Idea*

Reading data in real time with a sensor from “Sensirion” by implementing a serial monitor and backend in C.
This way we should have high accessibility and performance, all at once.

![Untitled](./readme_assets/Untitled.png)

<br><br><br>

# 👀 *References*

**C syntax**

- [https://learnxinyminutes.com/docs/c/](https://learnxinyminutes.com/docs/c/)

**WASM docs**

- [https://developer.mozilla.org/en-US/docs/WebAssembly/Concepts](https://developer.mozilla.org/en-US/docs/WebAssembly/Concepts)

**Emscripten (compiling C → WASM)**

- [https://wasmbyexample.dev/examples/hello-world/hello-world.c.en-us.html](https://wasmbyexample.dev/examples/hello-world/hello-world.c.en-us.html)

- [https://emscripten.org/](https://emscripten.org/)

- [https://developer.mozilla.org/en-US/docs/WebAssembly/C_to_wasm](https://developer.mozilla.org/en-US/docs/WebAssembly/C_to_wasm)

- [https://www.youtube.com/watch?v=_pHgILVlx3c](https://www.youtube.com/watch?v=_pHgILVlx3c)

- [https://thenewstack.io/how-to-compile-c-code-into-webassembly-with-emscripten/](https://the- newstack.io/how-to-compile-c-code-into-webassembly-with-emscripten/)

- [https://web.dev/emscripting-a-c-library/](https://web.dev/emscripting-a-c-library/)

- [https://marcoselvatici.github.io/WASM_tutorial/](https://marcoselvatici.github.io/WASM_tutorial/)

- (github pages script: [https://github.com/ulazy1/emscripten-test-proj](https://github.com/ulazy1/emscripten-test-proj))


**Library for portability**

- [https://justine.lol/cosmopolitan/](https://justine.lol/cosmopolitan/)

**Sensirion Github respository**

- [https://github.com/Sensirion](https://github.com/Sensirion)

<br><br><br>

# 🔧 *Preparing the Hardware*

## *1) Flashing the ESP32*

**Setting up the IDE**

1. Download the “Arduino IDE” for your operating system
2. Install the library (must be from Sensirion)
    
    ![Untitled](./readme_assets/Untitled%201.png)
    
3. Install a new board
    
    [https://www.electroniclinic.com/esp32-arduino-ide-board-manager-installation-espressif-esp32-wroom/#ESP32_Arduino_IDE_Board_Manager_URL_link](https://www.electroniclinic.com/esp32-arduino-ide-board-manager-installation-espressif-esp32-wroom/#ESP32_Arduino_IDE_Board_Manager_URL_link)
    
4. once you have that installed, you can select the ESP32 Dev Module under `Tools > Board > esp32 > ...`
5. Select the right board and port
    
    ![Untitled](./readme_assets/Untitled%202.png)
    
6. Load a demo file to test it out
    
    `File > Examples > 01. Basics > BareMinumum`
    

4. Press the arrow to flash

![Untitled](./readme_assets/Untitled%203.png)

As soon as you establish a connection, hold the boot button, then press the reset button once.

**Connecting the sensor to the esp32**

Official tutorials:

- [https://developer.sensirion.com/sensirion-products/scd4x-co2-sensors/](https://developer.sensirion.com/sensirion-products/scd4x-co2-sensors/)

- [https://github.com/Sensirion/arduino-i2c-scd4x/blob/master/README.md](https://github.com/Sensirion/arduino-i2c-scd4x/blob/master/README.md)

---

1. Connect ground and power pins from sensor to esp32
    
    ![Untitled](./readme_assets/Untitled%204.png)
    
2. Connect the other cables to any pin you want
    
    Green cable = SDA → pin 4
    
    Yellow cable = SCL → pin 2
    

**Connecting to the esp32 after the sensors were connected to it**

1. Choose `File > Examples  > Sensirion I2C SCD4x > exampleUsage`.
2. Add `Wire.begin(4, 2);` after the `while (!Serial)` loop.
3. Press the arrow in the top left corner to Upload.

As soon as you establish a connection, hold the boot button, then press the reset button once - voila!

## *2) Establishing a serial connection and reading the live data stream*

**Using terminal tools**

MacOS

- [https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/establish-serial-connection.html#check-port-on-linux-and-macos](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/establish-serial-connection.html#check-port-on-linux-and-macos)

Linux

- [https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/establish-serial-connection.html#check-port-on-linux-and-macos](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/establish-serial-connection.html#check-port-on-linux-and-macos)

Windows

- [https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/establish-serial-connection.html#check-port-on-linux-and-macos](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/establish-serial-connection.html#check-port-on-linux-and-macos)

**Using a C library**

- [https://sigrok.org/wiki/Libserialport](https://sigrok.org/wiki/Libserialport)
    
    [https://hackaday.com/2018/09/14/easy-portable-serial-ports/](https://hackaday.com/2018/09/14/easy-portable-serial-ports/)
    
- [https://github.com/wjwwood/serial](https://github.com/wjwwood/serial)
- [https://gitlab.com/Teuniz/RS-232](https://gitlab.com/Teuniz/RS-232)
- [https://sigrok.org/wiki/Libserialport](https://sigrok.org/wiki/Libserialport)

<br><br><br>

# 🔧 *Running the Software*

0. Attach the ESP23 microcontroller and the sensor to your Linux PC (not Windows or MacOs, also WSL doesn't work).
1. You may need to update the path to your device in `backend/main.c`.
2. In the `backend` directory run the `build.sh` script and then execute the `main` executable to run the backend.
3. Then open up the `js_frontend/index.html` file.
4. Enjoy the sweet real time visualization.
