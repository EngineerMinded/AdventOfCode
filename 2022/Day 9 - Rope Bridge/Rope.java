/***************************************
 * Wayne Mack                          *
 * Advent Of Code - Day 9              *
 * ----------------------------------- *
 * Written in: Java                    *
 * Only part one successful            *
 ***************************************/

import java.lang.Math.*;
import static java.lang.Math.abs;
public class Rope {
    protected int xPosition;
    protected int yPosition;
    private int tailXPosition, tailYPosition;
    protected int intersecting;
    protected int chainIntersecting;
    boolean tailSkipTurn;
    Trail head, tail;
    TailChain tailChain;

    // Blank Constructor
    Rope() {
        xPosition = yPosition = 0;
        tailYPosition = tailXPosition = 0;
        intersecting = 1;
        tailSkipTurn = true;
        head = new Trail();
        tail = new Trail();
        tailChain = new TailChain();
    }
    // Move by instruction
    public void Move(String input) {
        //System.out.println("Command: " +input);
        String direction = input.split(" ")[0];
        int paces = Integer.parseInt(input.split(" ")[1]);
        for (int i = 1; i <= paces; i++ ) {
            switch (direction) {
                case "U": {
                    yPosition = yPosition + 1;
                    break;
                }
                case "D": {
                    yPosition = yPosition - 1;
                    break;
                }
                case "L": {
                    xPosition = xPosition - 1;
                    break;
                }
                case "R": {
                    xPosition = xPosition + 1;
                    break;
                }

            }
            head.append(xPosition,yPosition);
            if (!tailSkipTurn) {
                follow();

                if (thePointsVisited()) {
                    tailSkipTurn = true;
                }
            }
            else {
                tailSkipTurn = false;
            }
            System.out.println(" Head: "+ xPosition +" ,"+ yPosition +
                    " Tail: " + tailXPosition + " , " + tailYPosition);
        }
    }
    private void follow() {

        if ((abs(tailXPosition - xPosition) > 1 ) || (abs(tailYPosition - yPosition) > 1)) {
            if (tailXPosition  < xPosition) {
                tailXPosition++;
            }
            else if (tailXPosition > xPosition) {
                tailXPosition--;
            }
            if (tailYPosition  < yPosition) {
                tailYPosition++;
            }
            else if (tailYPosition > yPosition) {
                tailYPosition--;
            }
        }
        else if ((abs(tailXPosition - xPosition)) == 1 || (abs(tailYPosition - yPosition)) == 1) {
            return;
        }
        else if (tailXPosition  < xPosition) {
            tailXPosition++;
        }
        else if (tailXPosition > xPosition) {
            tailXPosition--;
        }
        else if (tailYPosition  < yPosition) {
            tailYPosition++;
        }
        else if (tailYPosition > yPosition) {
            tailYPosition--;
        }
        if (head.isTrail(tailXPosition, tailYPosition) && !tail.isTrail(tailXPosition,tailYPosition)) {
            intersecting++;
            //chainIntersecting = tailChain
            tailChain.append();
            System.out.println("ADD :" + tailXPosition + " " + tailYPosition);
            tail.append(tailXPosition,tailYPosition);
        }
    }
    private boolean thePointsVisited() {
        return ((xPosition == tailXPosition) && (yPosition == tailYPosition));
    }
}
class Trail {
    int x;
    int y;
    Trail next;
    Trail() {
        this.x = 0;
        this.y = 0;
        next = null;
    }
    Trail(int x, int y) {
        this.x = x;
        this.y = y;
        next = null;
    }
    public void append(int newX,int newY) {
        if ((newX == x) && (newY == y) ) {
            return;
        }
        if (next == null) {
            next = new Trail(newX,newY);
        }
        else {
            next.append(newX,newY);
        }
    }
    public boolean isTrail(int xSearch, int ySearch) {
        if ((xSearch == x) && (ySearch == y)) {
            return true;
        }
        else if (next == null) {
            return false;
        }
        else {
            return next.isTrail(xSearch, ySearch);
        }
    }
}
class TailChain {
    int count;
    TailChain next;

    public TailChain () {
        count = 1;
        next = null;
    }
    public void append() {
        if (next == null) {
            if (count > 0) {
                count++;
            }
            if (count >= 10) {
                count = 0;
            }
            next = new TailChain();
        }
        else {
            if (count > 0) {
                count++;
            }
            if (count >= 10) {
                count = 0;
            }
            next.append();
        }
    }
    public int getCount () {
        if (next != null) {
            return count + next.getCount();
        }
        else {
            return count;
        }
    }
}

