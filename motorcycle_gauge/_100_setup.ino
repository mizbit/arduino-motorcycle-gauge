static unsigned char zephyr_bits[] = {
   0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcf, 0x7f, 0xc0, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe7, 0x03, 0xf0,
   0xff, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc7, 0xff, 0xff, 0xff, 0x03,
   0x00, 0xfc, 0x07, 0xf8, 0x00, 0x3e, 0xf8, 0x18, 0xf0, 0xe0, 0x0f, 0xf0,
   0xff, 0x01, 0x02, 0xff, 0x00, 0x0e, 0x00, 0x1c, 0x3c, 0x08, 0x78, 0xf0,
   0x00, 0xc0, 0xff, 0xc0, 0x80, 0x0f, 0x00, 0xe3, 0x1f, 0x08, 0x1e, 0x0c,
   0x3c, 0x38, 0xfe, 0x80, 0x7f, 0x70, 0xe0, 0x03, 0xfe, 0xff, 0x3f, 0x00,
   0x0f, 0x04, 0x1e, 0xec, 0xff, 0x81, 0x3f, 0x3e, 0xf0, 0x81, 0xff, 0x83,
   0x1f, 0x80, 0x0f, 0x02, 0x0f, 0x3e, 0xfc, 0x81, 0xbf, 0x1f, 0xfc, 0xc1,
   0xfb, 0xc1, 0x0f, 0xc0, 0x00, 0x83, 0x03, 0x1f, 0xfc, 0xc1, 0xff, 0x0f,
   0xff, 0x00, 0xf8, 0xe0, 0x03, 0x01, 0x80, 0x83, 0x81, 0x0f, 0x7e, 0xe0,
   0xff, 0x87, 0xff, 0x00, 0x7c, 0x70, 0xc0, 0xe0, 0x81, 0x01, 0xc0, 0x07,
   0x0f, 0xf8, 0xff, 0xe1, 0x3f, 0xf0, 0x3f, 0x00, 0x7e, 0xf0, 0xc0, 0x61,
   0xc0, 0x03, 0x80, 0xff, 0xff, 0xf0, 0x1f, 0xfc, 0x1f, 0xf8, 0x7f, 0xf0,
   0xe0, 0x3f, 0xe0, 0x01, 0xe0, 0xff, 0x7f, 0xf8, 0x0f, 0x04, 0x1c, 0xfc,
   0x3f, 0x78, 0xe0, 0x1f, 0xf0, 0xc0, 0xc1, 0xff, 0x3f, 0xfc, 0x07, 0x00,
   0x0c, 0xfe, 0x1f, 0x38, 0xf0, 0x1f, 0x70, 0xe0, 0x07, 0xff, 0x1f, 0xff,
   0x03, 0x00, 0x86, 0xff, 0x1f, 0x3e, 0xfe, 0x0f, 0x3e, 0xf8, 0x1f, 0xfe,
   0x8f, 0xff, 0x81, 0xff, 0xff, 0xff, 0xef, 0xff, 0xff, 0xff, 0x9f, 0xff,
   0x7f, 0xf8, 0xc7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xf1, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xff, 0xcf, 0x01, 0x00, 0x00, 0xf8, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0x00, 0xf0, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff };

double drawLogo(int x,int y){
    u8g2.setDrawColor(0);
    u8g2.drawXBM(x,y,112,25,zephyr_bits);
}

double easeIn(double t){
    return t*t*t;
  }

  double easeOut(double t){
    return 1+(--t)*t*t;
  }

void setup() {
  
  
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN,HIGH);
  EEPROM.init();
  Serial.begin(9600);
  
  // Initiate u8g2 
  u8g2.begin();
  //u8g2.setContrast(5);
  SceneManager::loadState();
  Odometer::loadState();
  
  
  // Initate components

  
  Odometer::init(PB12); // Speed pin
  SceneManager::init(PB14,PA8); // buttonPin, powerPin     
  Fuelmeter::init(PA3,PB4);  // fuelpin, controlPin +5v
  Tachometer::init(PA12); // Tachometer
  

  // animate intro

  for(double i = 0;i<15;i++){

    double x = -128 + 128 * easeOut(i/14.0);
    u8g2.clearBuffer();
    drawLogo(8+x,20);
    u8g2.sendBuffer();
    delay(15);
  }
  
  delay(1000);
  
  for(double i = 0;i<15;i++){

    double x = 128 * easeIn(i/14.0);
    u8g2.clearBuffer();
    drawLogo(8+x,20);
    u8g2.sendBuffer();
    delay(15);
  }
  
  
  
  
  


  
  
}
