// Creamos en menu donde iremos introduciendo dato a dato
// lo iremos guardando en *datos (datos[0], datos[1], etc)
void Fon_Configuracion(byte *datos)
{
  Serial.println("Establecer los parametros de configuracion del sistema");

  int numeroMenu = 0;
  boolean ver = true;

  // Mientras esta en Modo Configuracion
  while (digitalRead(conmutador_2))
  {
    // Si pulso y suelto el boton Menu incremento el numero de menu
    if (Fon_Pulsador_Soltar(pulsadorMenu))
    {
      numeroMenu++;
      if (numeroMenu > numeroElementosMenu-1)
      {
        numeroMenu = 0; 
      }
      ver = true;
    }
    // Muestro y mantengo fijos.
    if (ver)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(numeroMenu);
      lcd.print(datos1[numeroMenu]);
      lcd.setCursor(0,1);
      lcd.print(datos2[numeroMenu]);
    }
    ver = false;
    // En pantalla solo parpadea el valor a introducir
    lcd.setCursor(13,1);
    lcd.print("   ");
    lcd.setCursor(13,1);
    lcd.print(datos[numeroMenu]);
    datos[numeroMenu] = Fon_Lee_Dato(datos[numeroMenu]);



    delay(150);
  }
}


















