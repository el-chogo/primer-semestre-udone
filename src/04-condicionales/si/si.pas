Program Si;
Var
   nombre: String;

Begin
   Write('Introduzca un nombre: ');
   ReadLn(nombre);

   If nombre = 'Napoleon' Then
   Begin
      WriteLn('Su apellido es Bonaparte!');
   End
   Else
   Begin
       WriteLn('No se ha podido determinar su apellido');
   End;
End.
