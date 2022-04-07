#include "sensor.h"

static LiquidCrystal_I2C lcd(0x27, 20, 4);
MQ135 mq135_sensor = MQ135(PIN_MQ135);
const int DHTPIN = 2;       //Đọc dữ liệu từ DHT11 ở chân 2 trên mạch Arduino
const int DHTTYPE = DHT11;  //Khai báo loại cảm biến, có 2 loại là DHT11 và DHT22
DHT dht(DHTPIN, DHTTYPE);
int purifier_state = 0;
boolean enable_led = false;

void init_lcd()
{
  dht.begin();         // Khởi động cảm biến
  lcd.init();
  lcd.backlight();
}

void display_dht()
{
  float humidity = dht.readHumidity();    //Đọc độ ẩm
  float temperature = dht.readTemperature(); //Đọc nhiệt độ
  float ppm = mq135_sensor.getPPM();
  int light_value = analogRead(PIN_LIGHT);
  lcd.setCursor(0, 0);
  lcd.print("Anh Sang: ");
  lcd.setCursor(11, 0);
  lcd.print(light_value);
  lcd.setCursor(15, 0);
  lcd.print("(Lux)");
  lcd.setCursor(0, 1);
  lcd.print("Nhiet do:");
  lcd.setCursor(11, 1);
  lcd.print(temperature);
  lcd.setCursor(15, 1);
  lcd.print("(C)");
  lcd.setCursor(0, 2);
  lcd.print("Do am:");
  lcd.setCursor(11, 2);
  lcd.print(humidity);
  lcd.setCursor(15, 2);
  lcd.print("(%)");
  lcd.setCursor(0, 3);
  lcd.print("Khong khi:");
  lcd.setCursor(11, 3);
  lcd.print(ppm);
  lcd.setCursor(15, 3);
  lcd.print("(ppm)");


  if(light_value > 500 )
  {
    ledstate = LOW;
    digitalWrite(7, ledstate);
    Serial.print("!4:LED:");
        Serial.print(ledstate);
        Serial.print("#");
  }
 

  
  Serial.print("!1:TEMP:");
  Serial.print(temperature);
  Serial.print("#!2:HUMI:");
  Serial.print(humidity);
  Serial.print("#!3:AIR:");
  Serial.print(ppm);
  Serial.println("#");
  
}
