#include <M5Stack.h>
#include <Adafruit_MLX90614.h> // https://github.com/adafruit/Adafruit-MLX90614-Library

Adafruit_MLX90614 _mlx = Adafruit_MLX90614();

int _xpos;
int _ypos;
char _buffer[20];

void setup()
{
    M5.begin();
    M5.Power.begin();
    M5.Lcd.setTextSize(7);
    M5.Lcd.setTextDatum(4);

    _xpos = M5.Lcd.width() / 2;
    _ypos = M5.Lcd.height() / 2;

    _mlx.begin();
}

void loop()
{
    snprintf(_buffer, sizeof(_buffer), "%4.2lf", _mlx.readObjectTempC());
    M5.Lcd.drawString(_buffer, _xpos, _ypos, 1);

    delay(300);
}
