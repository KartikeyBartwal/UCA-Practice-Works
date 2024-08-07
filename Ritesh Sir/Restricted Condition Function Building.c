int invert(int x, int p, int n) {


}

int sign(int x){
  // x == 0 return 0, x < 0 return -1 , x > 0 return + 1

}


int bitwiseAnd (int x, int y){
  // x & y but only ~ and ! allowed

    // NEGATE BOTH x AND y
    int not_x = ~x;
    int not_y = ~y;

    // USE De Morgan's LAW: x & y == ~(~x | ~y)
    // FIRST NEGATE THE NEGATIONS OF x AND y, THEN OR THEM
    int not_x_or_not_y = ~not_x | ~not_y;

    // FINAL NEGATION TO GET AND RESULT
    return ~not_x_or_not_y;
}


int conditional( int x, int y, int z) {
  /*
  
if x == 0:
   return z
else:
  return y
  */
  
  // x ? y : z

  return ( ( ( !(!x)) << 31) >> 31 & y ) + ( (!x << 31) >> 31 & z );
}

int bang(int x){
  // compute !x without using ! : allowed: ^ & | + () - >> << 

  return ( (x | -x) >> 31 );
}
