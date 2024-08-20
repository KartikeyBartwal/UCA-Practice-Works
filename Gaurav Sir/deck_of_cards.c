#define suit_mask 48;

bool somesuit( char char1, char card2 ) {

    return !( ( card1 & suit_mask) ^  ( card2 & suit_mask) );
    
}
