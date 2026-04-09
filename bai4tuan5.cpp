#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

// ================= CARD =================
class Card {
private:
    string rank;
    string suit;
    bool faceUp;

public:
    Card(string r, string s) : rank(r), suit(s), faceUp(true) {}

    string getRank() const { return rank; }

    void show() const {
        cout << rank << " of " << suit;
    }
};

// ================= HAND =================
class Hand {
private:
    vector<Card> cards;

public:
    void addCard(Card c) {
        cards.push_back(c);
    }

    void show() {
        for (auto &c : cards) {
            c.show();
            cout << " | ";
        }
        cout << endl;
    }

    int value() {
        // đơn giản: tính tổng điểm
        int total = 0;
        for (auto &c : cards) {
            string r = c.getRank();
            if (r == "J" || r == "Q" || r == "K") total += 10;
            else if (r == "A") total += 11;
            else total += stoi(r);
        }
        return total;
    }

    void clear() {
        cards.clear();
    }
};

// ================= DECK =================
class Deck {
private:
    vector<Card> cards;

public:
    Deck() {
        string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
        string ranks[] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};

        for (auto &s : suits)
            for (auto &r : ranks)
                cards.push_back(Card(r, s));
    }

    void shuffle() {
        random_device rd;
        mt19937 g(rd());
        std::shuffle(cards.begin(), cards.end(), g);
    }

    Card deal() {
        Card c = cards.back();
        cards.pop_back();
        return c;
    }
};

// ================= PLAYER =================
class Player {
protected:
    string name;
    Hand hand;

public:
    Player(string n) : name(n) {}

    virtual void makeMove() = 0;

    void addCard(Card c) {
        hand.addCard(c);
    }

    void showHand() {
        cout << name << ": ";
        hand.show();
    }

    int getScore() {
        return hand.value();
    }

    void clearHand() {
        hand.clear();
    }

    string getName() { return name; }
};

// ================= HUMAN =================
class HumanPlayer : public Player {
public:
    HumanPlayer(string n) : Player(n) {}

    void makeMove() override {
        cout << name << " is playing...\n";
    }
};

// ================= COMPUTER =================
class ComputerPlayer : public Player {
public:
    ComputerPlayer(string n) : Player(n) {}

    void makeMove() override {
        cout << name << " (AI) is playing...\n";
    }
};

// ================= GAME =================
class PokerGame {
private:
    vector<Player*> players;
    Deck deck;

public:
    void addPlayer(Player* p) {
        players.push_back(p);
    }

    void startGame() {
        deck.shuffle();

        // chia mỗi người 2 lá
        for (int i = 0; i < 2; i++) {
            for (auto p : players) {
                p->addCard(deck.deal());
            }
        }
    }

    void playRound() {
        cout << "\n=== Players Hands ===\n";
        for (auto p : players) {
            p->showHand();
            p->makeMove();
        }

        // tìm người thắng
        Player* winner = players[0];
        for (auto p : players) {
            if (p->getScore() > winner->getScore()) {
                winner = p;
            }
        }

        cout << "\n🏆 Winner: " << winner->getName()
             << " (Score: " << winner->getScore() << ")\n";
    }
};

// ================= MAIN =================
int main() {
    PokerGame game;

    game.addPlayer(new HumanPlayer("Alice"));
    game.addPlayer(new ComputerPlayer("Bot"));

    game.startGame();
    game.playRound();

    return 0;
}