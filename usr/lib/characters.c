#include "../include/characters.h"

char isvowel( char c ) {

  // La funzione verifica se c è una vocale
  switch( c ) {

  case 'a' :
  case 'A' :

  case 'e' :
  case 'E' :

  case 'i' :
  case 'I' :

  case 'o' :
  case 'O' :

  case 'u' :
  case 'U' :
          return 1;
  default :
          return 0;
  }
}

unsigned int strcd( const char *s ) {

  // strcd = (str)ing (c)ount (d)igit
  // La funzione conta il numero di cifre in una stringa
  unsigned int count = 0;

  for( ; *s != '\0'; s++ ) {
          if( isdigit( *s ) ) count++;
  }
  return count;
}

unsigned int strcsp( const char *s ) {

  // strcsp = (str)ing (c)ount (sp)ace
  // La funzione conta il numero di spazi in una stringa
  unsigned int count = 0;

  for( ; *s != '\0'; s++ ) {
          if( *s == ' ' ) count++;
  }
  return count;
}
