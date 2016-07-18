Program Caso;
Var
numero: Integer;

Begin
    Write('Introduzca un numero: ');
    ReadLn(numero);

    case (numero) of
        0: WriteLn('Numero neutro con respecto a la suma');
        1: WriteLn('Numero neutro con respecto a la multiplicacion');
        2: WriteLn('Base del sistema binario');
        3: WriteLn('Lados del triangulo');
        4: WriteLn('Casas de Hogwarts');
        5: WriteLn('Puntas de una estrella');
        6: Begin
            WriteLn('Primer numero perfecto');
        End;
        7: WriteLn('Numero magico');
        else: WriteLn('Solo se imprimen resultados para numeros del 0 al 7');
    End;
End.
