var studentObject1 = {

  firstName : "fName" , 
  lastName : "lname" , 
  rollno : 1234454353,
  collegeName: "Chitakra University",

};


var in_string = JSON.stringify( studentObject1 );

console.log( in_string.substring( 0 , 23) );


var parsed_object = JSON.parse( in_string );

console.log( parsed_object )
