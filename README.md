# arduino-projects-book

# Prerequisites

Arduino UNO, etc...

Install the `arduino-cli`. Either download and place in `/usr/loccal/bin` or install with Homebrew

```
brew install arduino-cli
```

Install the core for the UNO board

```
arduino core install arduino:avr
```

See the [arduino-cli](https://arduino.github.io/arduino-cli/) docs for more information on how to use the CLI

# Compile projects for Arduino UNO

```
make compile PROJECT=<PROJECT_NAME>
```

# Deploy projects to Arduino UNO

```
make deploy PROJECT=<PROJECT_NAME>
```

NB. This recompiles the project if necessary first

# Listen to serial output from Arduino UNO

```
make listen
```

# Compile, deploy then listen in one go

```
make all PROJECT=<PROJECT_NAME>
```
