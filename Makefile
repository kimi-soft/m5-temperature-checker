compile:
	arduino-cli compile -b esp32:esp32:m5stack-core-esp32 --output-dir build temperature-checker

clean:
	rm -rf ./build

upload:
	arduino-cli upload --port $(COMPORT) -b esp32:esp32:m5stack-core-esp32 -i build/temperature-checker.ino.bin

add_board:
	arduino-cli config add board_manager.additional_urls https://dl.espressif.com/dl/package_esp32_index.json

install_core:
	arduino-cli core update-index
	arduino-cli core install esp32:esp32

install_lib:
	arduino-cli lib update-index
	arduino-cli lib install M5Stack
	arduino-cli lib install --git-url https://github.com/adafruit/Adafruit-MLX90614-Library
