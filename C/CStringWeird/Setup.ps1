function {
  param ($M);
  if((Test-Path -literalpath ".\Numgen.exe") -eq $False){echo 'Rebuild Numgen';cc ho.c -o Numgen.exe;}
  if((Test-Path -literalpath ".\Parser.exe") -eq $False){echo 'Rebuild Parser';cc StringtoBin.c -o Parser.exe;}
  if (!$M) {
    $M = "ABCD";
  }
  $tmp_Setup=$M|.\Numgen.exe;
  .\Parser.exe $tmp_Setup
}
