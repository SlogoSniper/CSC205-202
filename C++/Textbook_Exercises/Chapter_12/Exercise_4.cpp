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
}

bool equals(Card c1, Card c2) {
    return (c1.rank == c2.rank && c1.suit == c2.suit);
}

vector<Card> build_deck() {
    vector<Card> deck(52);
    int i = 0;
    for (int suit = 0; suit <= 3; suit++) {
        for (int rank = 1; rank <= 13; rank++) {
            deck[i].suit = suit;
            deck[i].rank = rank;
            i++;
        }
    }
    return deck;
}

int main() {
    vector<Card> mydeck = build_deck();
    cout << mydeck[1].rank << endl;
    cout << mydeck[2].rank << endl;
    cout << mydeck[50].rank << endl;
    return 0;
}