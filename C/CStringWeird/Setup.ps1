function {
  param ($M);
  cc ho.c -o Numgen.exe;
  cc StringtoBin.c -o Parser.exe;
  if (!$M) {
    $M = "ABCD";
  }
  $tmp_Setup=$M|.\Numgen.exe;
  .\Parser.exe $tmp_Setup
}
