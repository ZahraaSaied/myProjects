<?php
class Person
{
    public $age;
   public function __construct($initialAge)
   {
          if($initialAge <= 0)
          {
              $this->age = 0;
              echo "Age is not valid, setting age to 0."."<br>";
          }
       else
           $this->age = $initialAge;

   }
   public  function amIOld()
   {
            if($this->age < 13)
                echo "You are young."."<br>";
            elseif($this->age >= 13 && $this->age < 18)
                echo "You are a teenager."."<br>";
            else
                echo "You are old."."<br>";

   }
   public  function yearPasses()
   {
          $this->age ++ ;
   }
   
      
}
$age_arr = array(-1, 10, 16, 18);
 for($i = 0; $i < count($age_arr); $i++){
     $age = $age_arr[$i];
     $p = new Person($age);
     $p->amIOld();
     for($j = 0; $j<3; $j++)
     {
         $p->yearPasses();
     }
     $p->amIOld();    
 }
?>