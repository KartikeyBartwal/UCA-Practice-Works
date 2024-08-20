#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
typedef pair<ll,ll> pp;


unordered_map< string, int > Card_Value_Mappings = {
    { "Ace" , 1},
    { "2" , 2},
    { "3" , 3},
    { "4" , 4},
    { "5" , 5},
    { "6" , 6},
    { "7" , 7},
    { "8" , 8},
    { "9" , 9},
    { "Jack" , 10},
    { "Queen" , 11},
    { "King" , 12},
};

unordered_map< string, int > Card_Suit_Mappings = {

    { "diamond" , 0 },
    { "spades" , 1 },
    { "heart" , 2 },
    { "diamond" , 3 },
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
        // For getting input from inputs.txt
        freopen("inputs.txt", "r", stdin);
        // For writing output to outputs.txt
        freopen("outputs.txt", "w", stdout);
    #endif

    string first_card;
    
    string second_card;

    cin >> first_card >> second_card;


    int first_card_value = Get_Card_Value( first_card );

    int first_card_suit = Get_Card_Suit( first_card );


    int second_card_value = Get_Card_Value( second_card );

    int second_card_suit = Get_Card_Suit( second_card );



    // WHICH IS THE HIGHER VALUE CARD

    if( first_card_value > second_card_value ) {

        cout << "First card has higher value" << endl;
    }

    else if( second_card_value > first_card_value ) {

        cout << "Second card has higher value" << endl;
    }

    else{

        cout << "Both cards have equal value" << endl;
    }


    // ARE THEY THE SAME SUIT

    if( first_card_suit == second_card_suit ) {

        cout << "Same suit" << endl;
    }
    else{

        cout << "Different suits" << endl;
    }



    return 0;
}









