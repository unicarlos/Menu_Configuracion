

/*-----( Importar Librerias Necesarias)-----*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/*-----( Declarar Constantes )-----*/
// Entradas del conmutador
int conmutador_1 = 4;
int conmutador_2 = 5;

// Los 3 pulsadorMenues
int pulsadorMenu = 8;

int pulsadorSubir_1 = 7;
int pulsadorSubir_10 = 6;


/*-----( Declarar Objetos )-----*/
LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27

/*-----( Declarar Variables )-----*/
// usados con el conmutador para que la pantalla permanezca sin parpadear
boolean c1 = true;
boolean c2 = true;
boolean c3 = true;

int estadopulsadorMenu = LOW;

int const numeroElementosMenu = 5;
byte datos[numeroElementosMenu];
char* datos1[numeroElementosMenu] = {
  ".- Humedad", ".- Humedad", ".- Temperatura", ".- Temperatura", ".- Numero Dias"};
char* datos2[numeroElementosMenu] = {
  "Inicial", "Final", "Inicial", "Final", "Incubacion"};

void setup()   /*----( SETUP: Se ejecuta una vez )----*/
{
  Serial.begin(9600);
  lcd.init(); // initialize the lcd
  lcd.backlight();


  pinMode(pulsadorMenu, INPUT);
  pinMode(pulsadorSubir_1, INPUT);  
  pinMode(pulsadorSubir_10, INPUT); 
  pinMode(conmutador_1, INPUT);  
  pinMode(conmutador_2, INPUT); 

}/*--(end setup )---*/


void loop()   /*----( LOOP: Ciclico )----*/
{

  if (digitalRead(conmutador_1))
  {
    if (c1)
    {
      lcd.clear();
      lcd.print("Funcionando");
      c1 = false;  
      c2 = true;
      c3 = true;
      Serial.println("Funcionando");
      lcd.setCursor(0,1);
      for (int i=0; i < numeroElementosMenu; i++)
      {
        lcd.print(datos[i]);
        lcd.print(" ");
      }
      Serial.println();
    }

  }
  else
    if (digitalRead(conmutador_2))
    {
      if (c2)
      {
        lcd.clear();
        lcd.print("Modo");
        lcd.setCursor(0,1);
        lcd.print("Configuracion");
        c2 = false;
        c1 = true;
        c3 = true;
        Serial.println("Modo Configuracion");
        Fon_Configuracion(datos);
      }


    }  
    else
    {
      if (c3)
      {
        lcd.clear();
        lcd.print("Sistema Detenido");
        c3 = false;
        c1 = true;
        c2 = true;
        Serial.println("Sistema Detenido");
      }

    }

  // delay(500);



}/* --(end main loop )-- */

/*-----( Declare User-written Functions )-----*/




/* ( THE END ) */












