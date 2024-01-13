function {
  param ($M);
  cc ho.c;
  if (!$M) {
    $M = "TEST";
  }
  $M|.\a.exe| python .\Parseho.py;
}
