/***************************************
 * Wayne Mack                          *
 * Advent Of Code - Day 9              *
 * ----------------------------------- *
 * Written in: Java                    *
 * Only part one successful            *
 ***************************************/

import java.lang.Math.*;
import java.nio.file.attribute.GroupPrincipal;

import static java.lang.Math.abs;
enum Direction { DOWN,UP,LEFT,RIGHT };

public class Rope {
    protected int xPosition;
    protected int yPosition;
    private int segmentNumber;
    Rope next;
    RopeTrail ropeTrail;
    RopeTrail lastRopeTrail;

    // Blank Constructor
    public Rope(int numSegments) {
        segmentNumber = numSegments;
        xPosition = yPosition = 0;
        ropeTrail = new RopeTrail();
        if (numSegments > 1) {
            next = new Rope(numSegments - 1);

        }
        else {
            next = null;
        }
    }

    public void move (Direction direction, int numberOfSteps) { // This is for the head only
        for (int i = 0; i < numberOfSteps; i++ ) {
            switch (direction) {
                case UP: {
                    yPosition++;
                    break;
                }
                case DOWN: {
                    yPosition--;
                    break;
                }
                case LEFT: {
                    xPosition++;
                    break;
                }
                case RIGHT: {
                    xPosition--;
                    break;
                }
            }
            if (next != null) {
                next.move(xPosition,yPosition);
            }
            ropeTrail.add(xPosition,yPosition);
            displayChain();
            System.out.println();
        }

    }
    private void move(int leadingX, int leadingY) { // This is for trailing sections only
        int xDeviation = leadingX - xPosition;
        int yDeviation = leadingY - yPosition;
        if (xDeviation > 1) {
            xPosition++;
            if (yDeviation > 0) {
                yPosition++;
            }
            else if (yDeviation < 0) {
                yPosition--;
            }
        }
        else if (xDeviation < -1) {
            xPosition--;
            if (yDeviation > 0) {
                yPosition++;
            }
            else if (yDeviation < 0) {
                yPosition--;
            }
        }
        else if (yDeviation > 1) {
            yPosition++;
            if (xDeviation > 0) {
                xPosition++;
            }
            else if (xDeviation < 0) {
                xPosition--;
            }
        }
        else if (yDeviation < -1) {
            yPosition--;
            if (xDeviation > 0) {
                xPosition++;
            }
            else if (xDeviation < 0) {
                xPosition--;
            }
        }
        if (next != null) {
            next.move(xPosition, yPosition);
        }
        ropeTrail.add(xPosition,yPosition);
    }
    public void displayChain() {
        System.out.print("(" + xPosition + " , " + yPosition + ") ");
        if (next != null) {
            next.displayChain();
        }
    }
    private RopeTrail getLastRopeTrail() {
        if (next == null) {
            return ropeTrail;
        }
        else {
            return next.getLastRopeTrail();
        }
    }
    public int getAllTally() {
        lastRopeTrail = getLastRopeTrail();
        return ropeTrail.getAllInCount(lastRopeTrail);
    }

}
