import java.util.Arrays;

public class Cards {
    int [] cards;
    int score;

    Cards(String dataInput) {
        String[] input = dataInput.split(" ");
        score = Integer.parseInt(input[1]);
        cards = getCardValues(input[0]);
    }

    private int [] getCardValues(String hand) {
        int counter = 1;
        char []allCards = hand.toCharArray();
        int [] returnThis = new int[6];
        int []addresses = new int[15];
        for (int x = 0; x < 15; x++) {
            addresses[x] = 0;
        }
        for (int x = 0; x < allCards.length; x++) {
            addresses[getCardValue(allCards[x])]++;
        }
        System.out.println(Arrays.toString(addresses) + " " + Arrays.toString(allCards));
        for (int x = 5; x > 0; x--) {
            for (int y = 14; y >= 0; y--) {
                if (addresses[y] == x) {
                    for (int z = 1; z <= x; z++) {
                        returnThis[counter] = y;
                        counter++;
                    }
                }
            }
        }
        return getWinningRanking(returnThis);
    }
    private int getCardValue(char value) {
        if (value == 'A') { return 14;}
        if (value == 'K') { return 13;}
        if (value == 'Q') { return 12;}
        if (value == 'J') { return 11;}
        if (value == 'T') { return 10;}
        return value - '0';
    }

    private int[] getWinningRanking(int[] cardData) {
        // Five of a Kind
        if (cardData[1] == cardData[2] && cardData[1]== cardData[3] && cardData[1] == cardData[4] && cardData[1] == cardData[5]) {
            cardData[0] = 6; return cardData;
        }
        // Four Of A Kind
        if (cardData[1] == cardData[2] && cardData[1]== cardData[3] && cardData[1] == cardData[4]) {
            cardData[0] = 5; return cardData;
        }
        // Full House
        if (cardData[1] == cardData[2] && cardData[1]== cardData[3] &&  cardData[4] == cardData[5]) {
            cardData[0] = 4; return cardData;
        }
        // Three of a kind
        if (cardData[1] == cardData[2] && cardData[1]== cardData[3]) {
            cardData[0] = 3; return cardData;
        }
        // Two Pair
        if (cardData[1] == cardData[2] && cardData[3]== cardData[4]) {
            cardData[0] = 2; return cardData;
        }
        // One Pair
        if (cardData[1] == cardData[2]) {
            cardData[0] = 1; return cardData;
        }
        // Highest number
        cardData[0] = 0; return cardData;
    }
}
