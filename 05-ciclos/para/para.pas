Program Para;
Var
numero, contador: Integer;

Begin
    Write('Introduzca un numero: ');
    ReadLn(numero);

    For contador := 1 To numero Do
    Begin
        If contador mod 2 = 0 Then
        Begin
            WriteLn(contador, ' es un numero par!');
        End
        Else
        Begin
            WriteLn(contador, ' es un numero impar!');
        End;
    End;
End.
