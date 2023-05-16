#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum Suit {CLUBS, DIAMONDS, HEARTS, SPADES};
enum Rank {ACE=1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};


struct Card
{
    Rank rank;
    Suit suit;
    Card(int s, int r);
    Card();
    bool equals(const Card& c2) const;
    string to_string();
    void print();
};

Card::Card(int s, int r) {
    rank=Rank(r);
    suit=Suit(s);
}
Card::Card() {
    rank=Rank(1);
    suit=Suit(0);
}

string Card::to_string() {
    string mystring="";
    switch(rank) {
        case ACE: mystring += "Ace"; break;
        case TWO: mystring += "Two"; break;
        case THREE: mystring += "Three"; break;
        case FOUR: mystring += "Four"; break;
        case FIVE: mystring += "Five"; break;
        case SIX: mystring += "Six"; break;
        case SEVEN: mystring += "Seven"; break;
        case EIGHT: mystring += "Eight"; break;
        case NINE: mystring += "Nine"; break;
        case TEN: mystring += "Ten"; break;
        case JACK: mystring += "Jack"; break;
        case QUEEN: mystring += "Queen"; break;
        case KING: mystring += "King"; break;
        default: mystring += "Not a valid rank"; break;
    }
    mystring += " of ";
    switch(suit) {
        case CLUBS: mystring += "Clubs"; break;
        case DIAMONDS: mystring += "Diamonds"; break;
        case HEARTS: mystring += "Hearts"; break;
        case SPADES: mystring += "Spades"; break;
        default: mystring += "Not a valid suit"; break;
    }
    return mystring;
}


void Card::print() {
    cout << to_string() << endl;
}

bool Card::equals(const Card& c2) const
{
    return (rank == c2.rank && suit == c2.suit);
}

struct Deck {
    int size;
    vector<Card> cards;
    Deck(int n);
    Deck();
    void print() const;
    int find_card(const Card& card);
    void swap_cards(int c1, int c2);
    int find_lowest(int l, int h);
    void print();
    void sort();
    Deck merge(const Deck& d) const;
    Deck merge_sort() const;
};

Deck::Deck(int mysize)
{
    vector<Card> temp(mysize);
    cards = temp;
    size=mysize;
}
Deck::Deck()
{
    vector<Card> temp(52);
    size=52;
    cards = temp;
    int i = 0;
    for (Suit suit = CLUBS; suit <= SPADES; suit = Suit(suit+1)) {
        for (Rank rank = ACE; rank <= KING; rank = Rank(rank+1)) {
            cards[i].suit = suit;
            cards[i].rank = rank;
            i++;
        }
    }
}

void Deck::swap_cards(int c1, int c2) {
    Card strg = cards[c1];
    cards[c1] = cards[c2];
    cards[c2] = strg;
}

vector<Card> build_deck()
{
    vector<Card> deck(52);
    int i = 0;
    for (Suit suit = CLUBS; suit <= SPADES; suit = Suit(suit+1)) {
        for (Rank rank = ACE; rank <= KING; rank = Rank(rank+1)) {
            deck[i].suit = suit;
            deck[i].rank = rank;
            i++;
        }
    }
    return deck;
}

int Deck::find_card(const Card& card) {
    for (int i = 0; i < size; i++) {
        if (cards[i].equals(card)) return i;
    }
    return -1;
}

int Deck::find_lowest(int l, int h) {
    int lowest=l;
    int i;
    for (i=l;i<h+1;i++) {
        if (cards[i].rank<cards[lowest].rank) {
            lowest=i;
        }
    }
    return lowest;
}

void Deck::print() {
    for (int i = 0; i < size; i++) {
        cards[i].print();
    }
}

void Deck::sort() {
    for (int i = 0; i < size; i++) {
        // find the lowest card at or to the right of i
        swap_cards(i,find_lowest(i,size-1));
        // swap the ith card and the lowest card
    }
}

Deck Deck::merge(const Deck& d) const
{
    // creates a new deck big enough for all the cards
    Deck result(size+d.size);

    // use index i for place in first deck, j for place in second deck
    int i = 0;
    int j = 0;

    // k traverses the result deck
    for (int k = 0; k < result.size; k++) {
        // if this is empty, d wins, if d is empty, this wins;
        if (i==size) {
            result.cards[k]=d.cards[j];
            j++;
        } else if (j==d.size) {
            result.cards[k]=cards[i];
            i++;
        } else if (cards[i].rank>d.cards[j].rank) {
            result.cards[k]=d.cards[j];
            j++;
        } else {
            result.cards[k]=cards[i];
            i++;
        }
        // otherwise, compare the two cards on top

        // add winner to the new deck
    }
    return result;
}
Deck Deck::merge_sort() const
{
    Deck deck1(size/2);
    Deck deck2(size-deck1.size);
    for (int i=0;i<size;i++) {
        if (i>=deck1.size) {
            deck2.cards[i-deck1.size+1]=cards[i];
        } else {
            deck1.cards[i]=cards[i];
        }
    }
    deck1.sort();
    deck2.sort();
    return deck1.merge(deck2);
}