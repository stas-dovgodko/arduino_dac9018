<?php


function convBase($numberInput, $fromBaseInput, $toBaseInput)
{
    if ($fromBaseInput==$toBaseInput) return $numberInput;
    $fromBase = str_split($fromBaseInput,1);
    $toBase = str_split($toBaseInput,1);
    $number = str_split($numberInput,1);
    $fromLen=strlen($fromBaseInput);
    $toLen=strlen($toBaseInput);
    $numberLen=strlen($numberInput);
    $retval='';
    if ($toBaseInput == '0123456789')
    {
        $retval=0;
        for ($i = 1;$i <= $numberLen; $i++)
            $retval = bcadd($retval, bcmul(array_search($number[$i-1], $fromBase),bcpow($fromLen,$numberLen-$i)));
        return $retval;
    }
    if ($fromBaseInput != '0123456789')
        $base10=convBase($numberInput, $fromBaseInput, '0123456789');
    else
        $base10 = $numberInput;
    if ($base10<strlen($toBaseInput))
        return $toBase[$base10];
    while($base10 != '0')
    {
        $retval = $toBase[bcmod($base10,$toLen)].$retval;
        $base10 = bcdiv($base10,$toLen,0);
    }
    return $retval;
}

$v_x = "1073741823";

$v1 = "2147483647"; $b = 0;

$def = [];

$index = 0;
for ($l = 0; $l <= 12; $l+=0.1) {
    //$v = bcpow_('10', $l / 20, 10);
    //$v = bcpow("1.22", $l, 10);

    //if ($l > 0) {

        $n = pow(1.122, $l);
        //$n = pow(1.26, $l);

        $v2 = bcdiv($v1, $n, 8);

        $v2_bin = str_pad(convBase($v2, '0123456789', '01'), 32, '0', STR_PAD_LEFT);

        $bytes = str_split($v2_bin, 8);




        /*echo $l . ': ' . "\n";
        echo ' ' . convBase($v1, '0123456789', '01') . "\n";
        echo ' ';*/

        $def_bytes = [];
        foreach($bytes as $i => $byte) {

            //$def_bytes[] = sprintf('mtrim[%d][%d] = B%s;',$index,$i,$byte);
            $def_bytes[] = 'B'.$byte;
        }
        $index++;
        //$def[] = sprintf('%s // -%.2fdb (%s times)',implode(' ', $def_bytes), $l, bcdiv($v1, $v2, 3));
        $def[] = sprintf('  {%s}, // -%.2fdb (%s times)',implode(',', $def_bytes), $l, bcdiv($v1, $v2, 3));

        //echo "\n";

        //echo ' ' . bcdiv($v1, $v2, 3) . "\n";
        //echo ' ' . bcdiv($v1, $v_x, 3) . "\n";
        //echo "\n";
    //}
}

//echo 'bytes: '.$b."\n";
//echo '----------------'."\n";
echo 'const PROGMEM  byte mastertrim[120][4] = {'."\n";
echo implode("\n", $def);
echo '}'."\n";