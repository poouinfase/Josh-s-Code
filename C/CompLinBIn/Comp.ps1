$Srch="C:\Users\catte\OneDrive\Documents\My\FUqaround\C\CompLinBIn\Srch.exe";
$fil= "C:\Users\catte\OneDrive\Documents\My\FUqaround\C\CompLinBIn\fil.exe";
if ((Test-Path -path $Srch ) -eq $False) { gcc BinVerLin.c -O2 -o Srch.exe; } #Complie if No executable found
if ((Test-Path -path $fil ) -eq $False) { gcc filter.c -O2 -o fil.exe; } #Complie if No executable found
echo ''>Timings.txt
foreach ($algonum in '1','2') {
  # echo $algonum
  $lim = [uint64] 1 -shl 43-1
  $Siz=[uint64] 1
  for ($Siz ; $Siz -lt ($lim); $Siz =$Siz -shl 1) {
    echo $Siz;
    $Tim=time{ $algonum|.\Srch.exe $Siz }
    $D=.\fil.exe $Tim
    # echo $algonum
    echo "$algonum $Siz $D" >>Timings.txt
     }
}
python Stats.py
