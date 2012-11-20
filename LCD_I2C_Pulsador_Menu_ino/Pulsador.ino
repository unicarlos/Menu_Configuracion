// Incrementa en 1 y se queda en un bucle sin hacer nada hasta que se suelt
int Fon_Pulsador_Soltar(int pulsador)
{
  if (digitalRead(pulsador))
  {
    while (digitalRead(pulsador)) ; 
    return 1; 
  }
  return 0;
}

// incrementa el contador mientras se mantiene pulsado.
int Fon_Pulsador_Mantenido(int pulsador, int contador, int incremento)
{
  if (digitalRead(pulsador))
  {
    contador = contador + incremento; 
  }
  if (contador > 100)
  {
    contador = 0;
  }
  return contador;
}

// Lee un dato mediante los pulsadores
int Fon_Lee_Dato(int valorElegido)
{
  valorElegido = Fon_Pulsador_Mantenido(pulsadorSubir_1, valorElegido,1);
  valorElegido = Fon_Pulsador_Mantenido(pulsadorSubir_10, valorElegido,10);
  //delay(100);
  return valorElegido;
}


