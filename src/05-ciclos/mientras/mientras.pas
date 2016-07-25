Program Mientras
Var
   numero, resultado, potencia: Integer;

Begin
   Write('Introduzca un numero: ');
   ReadLn(numero);

   Write('Introduzca una potencia: ');
   ReadLn(potencia);

   resultado := 1;

   While potencia > 0 Do
   Begin
      resultado := resultado * numero;
      potencia := potencia - 1;
   End;

   WriteLn(resultado);
End.
