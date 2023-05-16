#include <iostream>
using namespace std;

struct Card {
    int suit, rank;
    Card();
    Card(int s, int r);
};

Card::Card() {
    suit = 0; rank = 0;
}

Card::Card(int s, int r) {
    suit = s; rank = r;
}

bool equals(Card c1, Card c2) {
    return (c1.rank == c2.rank && c1.suit == c2.suit);
}

int main() {
    Card aceHeart(2,1);
    Card oneHeart(2,1);
    Card aceDiamond(1,1);
    if (equals(aceHeart, oneHeart)) {
        cout << "AceHeart equals OneHeart" << endl;
    }
    if (!(equals(aceHeart, aceDiamond))) {
        cout << "AceHeart does not equal AceDiamond" << endl;
    }
}