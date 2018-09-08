<?php

$n = 439; //639 439 874
$binrep = decbin($n);
echo $binrep;
$rep = str_split($binrep);
echo "<pre>";
print_r ($rep);
echo "<pre>";
$s = count($rep);
$rep[] = 0;
$numOfConsOnes = 1;
for ($i = 0; $i < $s ; $i++)
{
    if($rep[$i+1] == 1 && $rep[$i] == 1 )
    {
    	$numOfConsOnes ++;
    }
    if($rep[$i+1] == 0 && $rep[$i] == 1)
    {
    	if ($numOfConsOnes != 2) 
    	{
    		$num  = $numOfConsOnes ++;
    	}
    	if ($numOfConsOnes = 2) 
    	{
    		$num  = $numOfConsOnes;
    	}

    	$numOfConsOnes = 0;
    }
}
if ($numOfConsOnes > $num) 
{
	echo $numOfConsOnes;
}
else 
	echo $num;
?>