import java.util.Arrays;

public class Deck {
    Cards cardHand;
    Deck next;

    Deck() {
        cardHand = null;
        next = null;
    }
    Deck (Cards heyAddMe){
        this.cardHand = heyAddMe;
        next = null;
    }
    void rank(Cards checkMe) {
        if (theNewDeckIsHigher(checkMe)) {
            if (next == null) {
                next = new Deck(checkMe);
            }
            else {
                next.rank(checkMe);
            }
        }
        else {
            if (next == null) {
                next = new Deck(cardHand);
                this.cardHand = checkMe;
            }
            else {
                Deck insert = next;
                next = new Deck (this.cardHand);
                this.cardHand = checkMe;
                next.next = insert;

            }
        }
    }
    private boolean theNewDeckIsHigher(Cards toTest) {
        for (int x = 0; x < cardHand.cards.length; x++) {
            if (cardHand.cards[x] < toTest.cards[x]) {
                return true;
            }
            else if (cardHand.cards[x] > toTest.cards[x]) {
                return false;
            }
        }
        // if it is the same deck the default answer is true;
        return true;
    }

    void printAll() {
        System.out.println(Arrays.toString(cardHand.cards) + " " + cardHand.score);
        if (next != null) {
            next.printAll();
        }
    }

    int partOneAnswer() {
        return partOneAnswer(1);
    }
    int partOneAnswer(int multiplier) {
        int returnThis = cardHand.score * multiplier;
        if (next != null) {
            return returnThis + next.partOneAnswer(multiplier + 1);
        }
        else {
            return returnThis;
        }
    }
}
