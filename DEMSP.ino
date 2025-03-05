int cambien = 0; //Chân cảm biến nối chân số 1 Arduino

int giatri;
int gtmacdinh = 1;
int dem;

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); //LCD 16x02, địa chỉ I2C là 0X27

void setup() 
{
  Serial.begin(9600);

  pinMode(cambien, INPUT); 

  lcd.init(); //Khởi động LCD
  lcd.backlight(); //Bật đèn nền
  
  lcd.setCursor(0,0); //Cột 0, hàng 0
  lcd.print("TSP:"); 
  lcd.setCursor(0,1); //Cột 0, hàng 1
  lcd.print("R:   B:   G:   "); 

}

void loop() 
{
  giatri = digitalRead(cambien); //Đọc giá trị digital từ cảm biến và gán vào biến giatri

  if (giatri != gtmacdinh) //gia trị đọc từ cảm biến khác giá trị mặc định
  {
    if (giatri == 0) //Nếu giá trị = 0
      {
        dem++; //Biến đếm cộng 1
      }
    gtmacdinh = giatri; //giá trị mặc định = giá trị
  }

  Serial.print("Giá trị cảm biến là: ");
  Serial.print(giatri);
  Serial.print("      ");
  Serial.print("Số đếm: ");
  Serial.println(dem);
  Serial.println("      ");
  
  lcd.setCursor(14,0); //Cột 14, hàng 0
  lcd.print(dem); 
  
  delay(200);

}


// TCS 3200
// Định nghĩa các chân nối
//#define S0 9
//#define S1 10
//#define S2 11
//#define S3 12
//#define sensorOut 13
//
//// Các tần số được đọc bởi các màu
//int redFrequency = 0;
//int greenFrequency = 0;
//int blueFrequency = 0;
//
//void setup() {
//  // Cấu hình chân 
//  pinMode(S0, OUTPUT);
//  pinMode(S1, OUTPUT);
//  pinMode(S2, OUTPUT);
//  pinMode(S3, OUTPUT);
//  
//  // sensorOut là input
//  pinMode(sensorOut, INPUT);
//  
//  // Thang đo tần số là  20%
//  digitalWrite(S0,HIGH);
//  digitalWrite(S1,LOW);
//  
//   // Begins serial communication 
//  Serial.begin(9600);
//}
//void loop() {
//  // Chọn đọc photodiodes đỏ (RED)
//  digitalWrite(S2,LOW);
//  digitalWrite(S3,LOW);
//  
//  // Đọc tần số
//  redFrequency = pulseIn(sensorOut, LOW);
//  
//   // Ghi ra Serial
//  Serial.print("R = ");
//  Serial.print(redFrequency);
//  delay(100);
//  
//  // Chọn đọc photodiodes xanh (GREEN)
//  digitalWrite(S2,HIGH);
//  digitalWrite(S3,HIGH);
//  
//  // Đọc tần số
//  greenFrequency = pulseIn(sensorOut, LOW);
//  
//  // in ra GREEN (G)
//  Serial.print(" G = ");
//  Serial.print(greenFrequency);
//  delay(100);
// 
//  // Chọn đọc photodiodes BLUE
//  digitalWrite(S2,LOW);
//  digitalWrite(S3,HIGH);
//  
//   // Đọc tần số
//  blueFrequency = pulseIn(sensorOut, LOW);
//  
//  // In ra giá trị BLUE (B)
//  Serial.print(" B = ");
//  Serial.println(blueFrequency);
//  delay(100);
//}

//Ban phim

//#include <Keypad.h>
//
//const byte ROWS = 4; //four rows
//const byte COLS = 3; //four columns
//
//char keys[ROWS][COLS] = {
//  {'1','2','3'},
//  {'4','5','6'},
//  {'7','8','9'},
//  {'*','0','#'}
//};
//
//byte rowPins[ROWS] = {8, 7, 6, 5}; //connect to the row pinouts of the keypad
//byte colPins[COLS] = {4, 3, 2}; //connect to the column pinouts of the keypad
//
////Create an object of keypad
//Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
//
//void setup(){
//  Serial.begin(9600);
//}
//  
//void loop(){
//  char key = keypad.getKey();// Read the key
//
//  // Print if key pressed
//  if (key){
//    Serial.print("SSP: ");
//    Serial.println(key);
//  }
//}
