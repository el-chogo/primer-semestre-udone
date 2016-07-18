Program Aritmetica;
Var
    a, b                      :  Real;
    suma, producto:           :  Real;
    cocienteAB, cocienteBA    :  Real;
Begin
    Write('Introduce un valor para a: ');
    Read(a);

    Write('Introduce un valor para b: ');
    Read(b);

    suma       := a + b;
    producto   := a * b;
    cocienteAB := a / b;
    cocienteBA := b / a;
    
    WriteLn('a + b = ' + suma);
    WriteLn('a * b = ' + producto);
    WriteLn('a / b = ' + cocienteAB);
    WriteLn('b / a = ' + cocienteBA);
End.
