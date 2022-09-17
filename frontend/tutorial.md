# Download compiler (linux / wsl)

```
git clone https://github.com/emscripten-core/emsdk.git

# Enter that directory
cd emsdk

# Fetch the latest version of the emsdk (not needed the first time you clone)
git pull

# Download and install the latest SDK tools.
./emsdk install latest

# Make the "latest" SDK "active" for the current user. (writes .emscripten file)
./emsdk activate latest
```

## Compile to WASM

```
# Activate PATH and other environment variables in the current terminal
source ./emsdk_env.sh

# Compile
emcc main.c -o index.html --shell-file template.html
```

### View file 

For some reasons, it has to be hosted.

```
npm install serve

# enter the folder with index.html
serve .
```

Go to `localhost:3000`