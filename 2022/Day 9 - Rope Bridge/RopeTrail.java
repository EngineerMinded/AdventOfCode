/***************************************
 * Wayne Mack                          *
 * Advent Of Code - Day 9              *
 * ----------------------------------- *
 * Written in: Java                    *
 * Only part one successful            *
 ***************************************/

public class RopeTrail {
    int x, y;
    RopeTrail next;
    boolean hasBeenRead;

    public RopeTrail() {
        this.x = 0;
        this.y = 0;
        next = null;
        hasBeenRead = false;
    }

    private RopeTrail(int x, int y) {
        this.x = x;
        this.y = y;
        next = null;
        hasBeenRead = false;
    }

    public void add(int xInput, int yInput) {
        if ((x == xInput) && (y == yInput)) {
            // DON'T ADD!
        } else {
            if (next != null) {
                next.add(xInput, yInput);
            } else {
                next = new RopeTrail(xInput, yInput);
            }
        }
    }

    public int getTrailCount(RopeTrail toCount) {
        if (toCount.next != null) {
            return 1 + getTrailCount(toCount.next);
        } else {
            return 1;
        }
    }
}



