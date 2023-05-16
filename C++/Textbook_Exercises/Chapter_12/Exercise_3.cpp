#include <iostream>
#include <string>
#include <vector>
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
    suit = s;
    rank = r;
    if (r==1) {
        rank = 14;
    }
}

bool equals(Card c1, Card c2) {
    return (c1.rank == c2.rank && c1.suit == c2.suit);
}

int main() {
    Card AceHeart(2,1);
    Card TwoHeart(2,2);
    Card KingDiamond(1,13);
    cout << AceHeart.rank << endl;
    cout << TwoHeart.rank << endl;
    cout << KingDiamond.rank << endl;
    return 0;
}