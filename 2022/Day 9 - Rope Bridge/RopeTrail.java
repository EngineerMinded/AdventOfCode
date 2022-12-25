/***************************************
 * Wayne Mack                          *
 * Advent Of Code - Day 9              *
 * ----------------------------------- *
 * Written in: Java                    *
 * Only part one successful            *
 ***************************************/

public class RopeTrail {
    int x,y;
    RopeTrail next;
    boolean hasBeenRead;

    public RopeTrail () {
        this.x = 0;
        this.y = 0;
        next = null;
        hasBeenRead = false;
    }
    private RopeTrail(int x , int y) {
        this.x = x;
        this.y = y;
        next = null;
        hasBeenRead = false;
    }



    public void add(int xInput, int yInput) {
        if ((x == xInput) && (y == yInput)) {
            // DON'T ADD!
        }
        else {
            if (next != null) {
                next.add(xInput,yInput);
            }
            else {
                next = new RopeTrail( xInput , yInput );
            }
        }

     }
     public int getTrailCount() {
        if (next != null) {
            return 1 + next.getTrailCount();
        }
        else {
            return 1;
        }
     }
     public int getAllInCount (RopeTrail toCompare) {
        int tally = 0;
        if (toCompare.exists( x, y)) {
            System.out.println("( "+ x + " , " + y + " )");
            tally = 1;
        }
        if (next != null) {
            tally = tally +  next.getAllInCount(toCompare);
        }
        return tally;
     }
     /*****************REWRITE AS LOOP ************************/
     private boolean exists (int xFind, int yFind) {
         if ((x == xFind) && (y == yFind)) {
             return true;
         }
         if (next == null) {
             return false;
         }
         return next.exists(xFind, yFind);
     }
     public void displayAll(){
        System.out.println(x + " , " + y);
        if (next != null) {
            next.displayAll();
        }
     }
}



