Program Funciones;

Function Capitalizar(nombre: String) : String; Forward;
Procedure Saludar(nombre : String);
Begin
    WriteLn('Hola ' + Capitalizar(nombre) + '!');
End;

Function Capitalizar(nombre: String) : String;
Var
capitalizarActual: Boolean;
indice: Integer;
caracterActual: Char;
Begin
    indice := 1;
    capitalizarActual := True;

    For caracterActual In nombre Do
    Begin
        If capitalizarActual and (caracterActual <> ' ') Then
        Begin
            nombre[indice] := Upcase(caracterActual);
            capitalizarActual := False;
        End;

        If caracterActual = ' ' Then
        Begin
            capitalizarActual := True;
        End;

        indice := indice + 1;
    End;

    Capitalizar := nombre;
End;

Var
nombre: String;
Begin
    Write('Ingrese su nombre completo: ');
    ReadLn(nombre);
    Saludar(nombre);
End.
