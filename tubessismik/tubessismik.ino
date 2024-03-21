#include <TimerOne.h>
#include <LiquidCrystal_I2C.h>

// Setup lcd
LiquidCrystal_I2C lcd(0x27,16,2);

// Counter millis dan total waktu
volatile int count = 0, waktu = 0;

// Variabel buat display jam, menit detik
volatile int hari = 0, jam = 0, menit = 0, detik = 0;

// list hari
char day[][3] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

 //Menunjukkan mode
int layar = 1;

void satuMili(){
  count++;
  //Adder buat stopwatch

  //Adder buat jam
  if(count == 1000){
    count = 0;

    // Nambah detik reset, kalo udah nol lagi
    waktu++;
    updateWaktu();
    // Mengurangi timer kalo on

    // Menyalakan buzzzer kalo waktu udah sama alarm
  }
}

void updateWaktu(){
  // Nambah menit
  detik = waktu % 60;
  menit = int(waktu / 60);
  jam = int(waktu / 3600);

  // Rada ribet nambah tanggal, bulan, taun
}

void setup() {
  // put your setup code here, to run once:
  Timer1.initialize(1000);
  Timer1.attachInterrupt(satuMili);
  lcd.init();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(layar == 1){
    display();
  }
}

void display(){
  //Output jam-nya
  char displayWaktu[8];
  lcd.setCursor(0, 0);
  sprintf(displayWaktu, "%02d:%02d:%02d", jam, menit, detik);
  lcd.print(displayWaktu);
  
  /*
  lcd.setCursor(0, 1);
  lcd.print(day[hari]);
  */
  
  // Mematikan buzzer

  // Pindah layar
}