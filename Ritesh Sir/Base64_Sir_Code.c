////////////////////////// ENCODER /////////////////////////////////////////////

lookup = [A, B, C, ..... Z, a, b, ...... z, 0, ...... 9 , +, /];

s = "ab&*cdefgh";

char *base64( char *s, int length) {

int n = 0;
int i = 0;

while( true) {
  
  int n1 = s[i++];
  
  int n2 = s[i++] << 8;

  int n3 = s[i++];

  n = n1 | n2 | n3;

  char c = lookup[ ( n >> 18 ) & 63  ];

  char c2 = lookup[ ( n >> 12 ) & 63 ];

  char c3 = lookup[ ( n >> 6 ) & 63 ];

  char c4 = lookup[ (n) & 63 ];

  out[j++] = c;
  out[j++] = c2;
  out[j++] = c3;
  out[j++] = c4;

  1 += 3;
}

  length % 3; === 0 no = to be added 

  == 1 append == at the end of out
  == 2 append = at the end

  return out;
}




////////////////////////// DECODER /////////////////////////////////////////////


reverse_lookup = [-1, -1, -1  ....... ( 43 ) 62     63(48) 52, 53       (65) 0, 1, 2, 3, 4, 5 , 6/                   
   (97)  26, 27, 28, 29...... -1 - 1 -1 -1 -1 ]

int i;
c = ""


while c != "=" || i >= length{

  int n = reverse_lookup[ s[i++] ] << 10;
      n = 
}


  



