var globalvar1 = "Global Value"

function foo1() {

  var var1 = "pokemon";
  var let1 = "pikachu";

  console.log(" the value of var1 is: " , var1);
  console.log(" The value of let1 is: " , let1);

  if( true ) {

    var var1 = "pokemon_master";
    var let1 = "pikachuuuuuuu";

    console.log(" the value of var1 inside is: " , var1);
    console.log(" The value of let1 inside is: " , let1);

  }
  
      console.log(" the value of var1 inside is: " , var1);
    console.log(" The value of let1 inside is: " , let1);
}


foo1();
