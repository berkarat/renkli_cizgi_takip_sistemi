#define SensorSol_Sol 13
#define SensorSol 12
#define SensorOrta 11 // Sensör pinlerini tanımlıyoruz.
#define SensorSag 10
#define SensorSag_Sag 9
#define MotorR1  16
#define MotorR2  17
#define MotorRE  5
#define MotorL1   14
#define MotorL2   15
#define MotorLE  6

int S3 = 3;
int S2 = 2;
int outpin = 4;
int r ; // kırmızı renk
int g ;// yeşil renk
int b ;// mavi renk
int w ;// beyaz renk
unsigned int plusewidth;

char data;

void setup() {
  Serial.begin(9600);                          //Seri haberleşmeyi başlatıyoruz.
  /*---------------------------------------*/
  pinMode(SensorSol_Sol, INPUT);
  pinMode(SensorSag_Sag, INPUT);
  pinMode(SensorSol, INPUT);
  pinMode(SensorOrta, INPUT);                 //Sensörlerimizi giriş olarak tanımlıyoruz.
  pinMode(SensorSag, INPUT);
  /*---------------------------------------*/
  pinMode(MotorL1, OUTPUT);
  pinMode(MotorL2, OUTPUT);
  pinMode(MotorLE, OUTPUT);                    //Motorlarımızı çıkış olarak tanımlıyoruz.
  pinMode(MotorR1, OUTPUT);
  pinMode(MotorR2, OUTPUT);
  pinMode(MotorRE, OUTPUT);
  /*---------------------------------------*/
  pinMode(S3, OUTPUT);                        // TCS3200  sensör çıkış pinleri
  pinMode(S2, OUTPUT);
  pinMode(outpin, INPUT);                    // TCS3200 sensör giriş pini
}

void loop() {

  //  Serial.print(digitalRead(SensorSol_Sol));
  //  Serial.print(",");
  //  Serial.print(digitalRead(SensorSol));
  //  Serial.print(",");
  //  Serial.print(digitalRead(SensorOrta));
  //  Serial.print(",");
  //  Serial.print(digitalRead(SensorSag));
  //  Serial.print(",");
  //  Serial.print(digitalRead(SensorSag_Sag));
  //  Serial.println();
  //  delay(120);
  //duz_git();
  //sag_don();
  //sag_keskin_don();
  //sol_don();
  //sol_keskin_don();
  // fonks1();



  //renk_oku();
  //
  //  Serial.print("R : ");
  //  Serial.print(r);
  //  Serial.print(" G : ");
  // Serial.print(g);
  //  Serial.print(" B : ");
  //  Serial.print(b);
  //  Serial.print( " W : ");
  //  Serial.print(w);
  //  Serial.println("");


  //if ( r < g && r < b && r > w && g > b && g > w && b > w && r < 550) {
  //    Serial.println("*! RED *!");
  //
  //  }
  //
  //    else if ( r < b && r > w && g < b && g > w && b > w ) {
  //      Serial.println("*! GREEN *!");
  //
  //    }
  //  else if ( r > g && r > b && r > w && g > b && g > w && b > w  ) {
  //   Serial.println("*! BLUE *!");
  //
  // }
  //  else if (r < g && r > b && r > w && g > b && g > w && b > w ) {
  //    Serial.println("*! WHİTE *!");
  //
  // }
  // else
  //   Serial.println("!----------------------OKUNAMADI----------------------!");
  //
  //  //delay (100);












  /* -----------------Bluetooth haberleşme---------------------*/

  if (Serial.available() > 0) {

    data = Serial.read();


    switch (data)
    {
      case 'r': red(1); break;
      case 'g': green(1); break;
      case 'b': blue(1); break;
      case 'B': basla(1); break;
      case 'D': dur_1(1); break;
    }
    Serial.println(data);
  }

}
void red(int a) {
  char something;

  while (a == 1 && something != 'g' && something != 'b'&& something != 'B'&& something != 'D' ) {
    renk_oku();
    something = Serial.read();
    if ( r < g && r < b && r > w && g > b && g > w && b > w && r < 550) {
      Serial.println("*! RED *!");
      fonks1();
    }
    else {

      dur();
    }
  }
}
void green(int a) {
  char something;

  while (a == 1 && something != 'r' && something != 'b'&& something != 'B'&& something != 'D') {
    renk_oku();
    something = Serial.read();
    if ( r < b && r > w && g < b && g > w && b > w ) {
      Serial.println("*! GREEN *!");
      fonks1();
    }
    else {

      dur();
    }
  }
}
void blue(int a) {
  char something;

  while (a == 1 &&something != 'r' && something != 'g'&& something != 'B'&& something != 'D') 
  {
    renk_oku();
    something = Serial.read();
    if (  r > g && r > b && r > w && g > b && g > w && b > w ) {
      Serial.println("*! Blue *!");
      fonks1();
    }
    else {

      dur();
    }
  }
}

void dur_1(int a) {
  char something;
  while (a == 1 && something != 'B'&& something != 'r' && something != 'g'&& something != 'b') {
    something = Serial.read();

    dur();
  }
}



/*----------------------------------------------------------------------------------*/
void basla(int a) {
  char something;
  while (a == 1 && something != 'r'&& something != 'g' && something != 'b'&& something != 'B'&& something != 'D') {
    something = Serial.read();
    if (digitalRead(SensorSol_Sol) == 1 && digitalRead(SensorSol) == 1 && digitalRead(SensorOrta) == 1 && digitalRead(SensorSag) == 1 && digitalRead(SensorSag_Sag) == 0)
    {
      sag_keskin_don();
    }
    if (digitalRead(SensorSol_Sol) == 1 && digitalRead(SensorSol) == 1 && digitalRead(SensorOrta) == 1 && digitalRead(SensorSag) == 0 && digitalRead(SensorSag_Sag) == 0)
    { //sag
      sol_don();
    }
    if (digitalRead(SensorSol_Sol) == 1 && digitalRead(SensorSol) == 1 && digitalRead(SensorOrta) == 1 && digitalRead(SensorSag) == 0 && digitalRead(SensorSag_Sag) == 1)
    {
      // sag
      sol_don();
    }
    if (digitalRead(SensorSol_Sol) == 1 && digitalRead(SensorSol) == 1 && digitalRead(SensorOrta) == 0 && digitalRead(SensorSag) == 0 && digitalRead(SensorSag_Sag) == 0)
    {
      // sag
      sol_don();
    }
    if (digitalRead(SensorSol_Sol) == 0 && digitalRead(SensorSol) == 1 && digitalRead(SensorOrta) == 1 && digitalRead(SensorSag) == 1 && digitalRead(SensorSag_Sag) == 1)
    {
      //  sol
      sol_keskin_don();
    }
    if (digitalRead(SensorSol_Sol) == 0 && digitalRead(SensorSol) == 0 && digitalRead(SensorOrta) == 1 && digitalRead(SensorSag) == 1 && digitalRead(SensorSag_Sag) == 1)
    { //sol
      sag_don();
    }
    if (digitalRead(SensorSol_Sol) == 1 && digitalRead(SensorSol) == 0 && digitalRead(SensorOrta) == 1 && digitalRead(SensorSag) == 1 && digitalRead(SensorSag_Sag) == 1)
    { //sol
      sag_don();
    }
    if (digitalRead(SensorSol_Sol) == 0 && digitalRead(SensorSol) == 0 && digitalRead(SensorOrta) == 0 && digitalRead(SensorSag) == 1 && digitalRead(SensorSag_Sag) == 1)
    {
      // sol
      sol_don();
    }
    if (digitalRead(SensorSol_Sol) == 1 && digitalRead(SensorSol) == 1 && digitalRead(SensorOrta) == 0 && digitalRead(SensorSag) == 0 && digitalRead(SensorSag_Sag) == 1)
    {
      //d
      duz_git();
    }
    if (digitalRead(SensorSol_Sol) == 1 && digitalRead(SensorSol) == 0 && digitalRead(SensorOrta) == 0 && digitalRead(SensorSag) == 1 && digitalRead(SensorSag_Sag) == 1)
    { // d
      duz_git();
    }
    if (digitalRead(SensorSol_Sol) == 1 && digitalRead(SensorSol) == 1 && digitalRead(SensorOrta) == 0 && digitalRead(SensorSag) == 1 && digitalRead(SensorSag_Sag) == 1)
    {
      // d
      duz_git();
    }
    if (digitalRead(SensorSol_Sol) == 1 && digitalRead(SensorSol) == 0 && digitalRead(SensorOrta) == 0 && digitalRead(SensorSag) == 0 && digitalRead(SensorSag_Sag) == 1)
    {
      //d
      duz_git();
    }
    if (digitalRead(SensorSol_Sol) == 0 && digitalRead(SensorSol) == 0 && digitalRead(SensorOrta) == 0 && digitalRead(SensorSag) == 0 && digitalRead(SensorSag_Sag) == 0)
    {
      //  dur
      dur();

    }
    if (digitalRead(SensorSol_Sol) == 1 && digitalRead(SensorSol) == 1 && digitalRead(SensorOrta) == 1 && digitalRead(SensorSag) == 1 && digitalRead(SensorSag_Sag) == 1) // Sensörler siyah görmüyor ise
    {
      // arama
      sag_don();
    }

  }
}

void fonks1() {

  if (digitalRead(SensorSol_Sol) == 1 && digitalRead(SensorSol) == 1 && digitalRead(SensorOrta) == 1 && digitalRead(SensorSag) == 1 && digitalRead(SensorSag_Sag) == 0)
  {
    sag_keskin_don();
  }
  if (digitalRead(SensorSol_Sol) == 1 && digitalRead(SensorSol) == 1 && digitalRead(SensorOrta) == 1 && digitalRead(SensorSag) == 0 && digitalRead(SensorSag_Sag) == 0)
  { //sag
    sol_don();
  }
  if (digitalRead(SensorSol_Sol) == 1 && digitalRead(SensorSol) == 1 && digitalRead(SensorOrta) == 1 && digitalRead(SensorSag) == 0 && digitalRead(SensorSag_Sag) == 1)
  {
    // sag
    sol_don();
  }
  if (digitalRead(SensorSol_Sol) == 1 && digitalRead(SensorSol) == 1 && digitalRead(SensorOrta) == 0 && digitalRead(SensorSag) == 0 && digitalRead(SensorSag_Sag) == 0)
  {
    // sag
    sol_don();
  }
  if (digitalRead(SensorSol_Sol) == 0 && digitalRead(SensorSol) == 1 && digitalRead(SensorOrta) == 1 && digitalRead(SensorSag) == 1 && digitalRead(SensorSag_Sag) == 1)
  {
    //  sol
    sol_keskin_don();
  }
  if (digitalRead(SensorSol_Sol) == 0 && digitalRead(SensorSol) == 0 && digitalRead(SensorOrta) == 1 && digitalRead(SensorSag) == 1 && digitalRead(SensorSag_Sag) == 1)
  { //sol
    sag_don();
  }
  if (digitalRead(SensorSol_Sol) == 1 && digitalRead(SensorSol) == 0 && digitalRead(SensorOrta) == 1 && digitalRead(SensorSag) == 1 && digitalRead(SensorSag_Sag) == 1)
  { //sol
    sag_don();
  }
  if (digitalRead(SensorSol_Sol) == 0 && digitalRead(SensorSol) == 0 && digitalRead(SensorOrta) == 0 && digitalRead(SensorSag) == 1 && digitalRead(SensorSag_Sag) == 1)
  {
    // sol
    sol_don();
  }
  if (digitalRead(SensorSol_Sol) == 1 && digitalRead(SensorSol) == 1 && digitalRead(SensorOrta) == 0 && digitalRead(SensorSag) == 0 && digitalRead(SensorSag_Sag) == 1)
  {
    //d
    duz_git();
  }
  if (digitalRead(SensorSol_Sol) == 1 && digitalRead(SensorSol) == 0 && digitalRead(SensorOrta) == 0 && digitalRead(SensorSag) == 1 && digitalRead(SensorSag_Sag) == 1)
  { // d
    duz_git();
  }
  if (digitalRead(SensorSol_Sol) == 1 && digitalRead(SensorSol) == 1 && digitalRead(SensorOrta) == 0 && digitalRead(SensorSag) == 1 && digitalRead(SensorSag_Sag) == 1)
  {
    // d
    duz_git();
  }
  if (digitalRead(SensorSol_Sol) == 1 && digitalRead(SensorSol) == 0 && digitalRead(SensorOrta) == 0 && digitalRead(SensorSag) == 0 && digitalRead(SensorSag_Sag) == 1)
  {
    //d
    duz_git();
  }
  if (digitalRead(SensorSol_Sol) == 0 && digitalRead(SensorSol) == 0 && digitalRead(SensorOrta) == 0 && digitalRead(SensorSag) == 0 && digitalRead(SensorSag_Sag) == 0)
  {
    //  dur
    dur();

  }
  if (digitalRead(SensorSol_Sol) == 1 && digitalRead(SensorSol) == 1 && digitalRead(SensorOrta) == 1 && digitalRead(SensorSag) == 1 && digitalRead(SensorSag_Sag) == 1) // Sensörler siyah görmüyor ise
  {
    // arama
    sag_don();
  }

}

/*---------------------------------- MOTOR HAREKET KODLARI BAŞLANGIÇ-------------------------------------*/

void sag_motor(String dir, int spd)// sağ motor kontrolü
{ // yön(dir) ve hız(spd) için değişkenler.
  if ( dir == "ileri")             // düz komutu ileri hareket için.
  {
    digitalWrite(MotorR1, HIGH);
    digitalWrite(MotorR2, LOW);
    analogWrite(MotorRE, spd);
  }

  if ( dir == "geri")           //BACKWARD komutu geriye hareket için.
  {
    digitalWrite(MotorR1, LOW);
    digitalWrite(MotorR2, HIGH);
    analogWrite(MotorRE, spd);
  }

  if ( dir == "dur")             // STOP komutu motorun durması için.
  {
    digitalWrite(MotorR1, LOW);
    digitalWrite(MotorR2, LOW);
    analogWrite(MotorRE, spd);
  }
}

void sol_motor(String dir, int spd)// sağ motor kontrolü
{ // yön(dir) ve hız(spd) için değişkenler.
  if ( dir == "ileri")             // düz komutu ileri hareket için.
  {
    digitalWrite(MotorL1, HIGH);
    digitalWrite(MotorL2, LOW);
    analogWrite(MotorLE, spd);
  }

  if ( dir == "geri")           //BACKWARD komutu geriye hareket için.
  {
    digitalWrite(MotorL1, LOW);
    digitalWrite(MotorL2, HIGH);
    analogWrite(MotorLE, spd);
  }

  if ( dir == "dur")             // STOP komutu motorun durması için.
  {
    digitalWrite(MotorL1, LOW);
    digitalWrite(MotorL2, LOW);
    analogWrite(MotorLE, spd);
  }
}
/*---------------------------------- MOTOR HAREKET KODLARI BİTİŞ-------------------------------------*/
/*---------------------------------- YÖNLENDİRME KODLARI BAŞLANGIÇ-------------------------------------*/

void duz_git()
{
  sag_motor("ileri", 120);
  sol_motor("ileri", 120);
}
void sag_don()
{
  sag_motor("ileri", 100);
  sol_motor("dur", 0);
}
void sag_keskin_don()
{
  sag_motor("geri", 100);
  sol_motor("ileri", 100);
}
void sol_don()
{
  sag_motor("dur", 0);
  sol_motor("ileri", 100);
}
void sol_keskin_don() // Robot ileri gitsin.
{
  sag_motor("ileri", 100);
  sol_motor("geri", 100);
}
void dur() {
  sag_motor("dur", 0);
  sol_motor("dur", 0);
}

/*---------------------------------- YÖNLENDİRME KODLARI BİTİŞ-------------------------------------*/

/*---------------------------------- RENK OKUMA KODLARI BAŞLANGIÇ-------------------------------------*/

void renk_oku() { // renk algılama kodu

  // kırımızı renk için okuma işlemi
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  r = pulseIn(outpin, LOW);
  //  r = plusewidth / 400. - 1;
  //  r = (255 - r);
  /*----------------------*/

  //yeşil renk için okuma işlemi
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  g = pulseIn(outpin, LOW);
  // g = plusewidth / 400. - 1;
  //    g = (255 - g);

  /*----------------------*/

  //mavi renk için okuma işlemi
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  b = pulseIn(outpin, LOW);
  //   b = plusewidth / 400. - 1;
  //  b = (255 - b);

  /*----------------------*/

  //beyaz renk için okuma işlemi
  digitalWrite(S2, HIGH);
  digitalWrite(S3, LOW);
  w = pulseIn(outpin, LOW);
  //
  //    w = (255 - w);
}
/*---------------------------------- RENK OKUMA KODLARI BİTİŞ-------------------------------------*/
