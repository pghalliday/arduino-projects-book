.PHONY: all compile deploy listen client all-client

all: deploy listen

all-client: deploy client

${PROJECT}/${PROJECT}.arduino.avr.uno.elf: ${PROJECT}/${PROJECT}.ino
	arduino-cli compile --fqbn arduino:avr:uno ${PROJECT}

compile: ${PROJECT}/${PROJECT}.arduino.avr.uno.elf

deploy: compile
	arduino-cli upload -p /dev/cu.usbmodem14201 --fqbn arduino:avr:uno ${PROJECT}

listen:
	stty -f /dev/cu.usbmodem14201 9600
	cat /dev/cu.usbmodem14201

client:
	processing-java --sketch=${CURDIR}/${PROJECT}/client --output=${CURDIR}/${PROJECT}/client/build --force --run
