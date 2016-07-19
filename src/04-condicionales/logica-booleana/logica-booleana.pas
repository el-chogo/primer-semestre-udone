Program LogicaBooleana;
Begin
    WriteLn('Verdadero y Falso: ', True and False);
    WriteLn('Falso y Verdadero: ', False and True);
    WriteLn('AND logico se comporta como un producto de 1 (Verdadero) y 0 (Falso)');
    WriteLn('1 x 0 = ', 1 * 0);
    WriteLn('0 x 1 = ', 0 * 1);
    WriteLn('Verdadero y Verdadero', True and True);
    WriteLn('Falso y Falso', False and False);

    WriteLn('Verdadero o Falso: ', True or False);
    WriteLn('Falso o Verdadero: ', False or True);
    WriteLn('OR logico se comporta como una suma de 1 (Verdadero) y 0 (Falso)');
    WriteLn('1 + 0 = ', 1 + 0);
    WriteLn('0 + 1 = ', 0 + 1);
    WriteLn('Verdadero o Verdadero: ', True or True);
    WriteLn('Falso o Falso: ', False or False);
End.
