public class Gnome {
        // instance variables
        public String name;
        public int age;
        public Gnome gnomeBuddy;
        private boolean magical = false;
        protected double height = 2.6;
        public static final int MAX_HEIGHT = 3; // maximum height
        // constructors
        Gnome (String nm, int ag, Gnome bud, double hgt) { //fully parameterized
                name = nm;
                age = ag;
                gnomeBuddy = bud;
                height = hgt;
        }
        Gnome() {
                name = "Rumple";
                age = 204;
                gnomeBuddy = null;
                height = 2.1;
        }
        // methods
        public static void makeKing (Gnome h) {
                h.name = "King " + h.getRealName();
                h.magical = true; // only the Gnome class can reference this field
        }
        public void makeMeKing () {
                name = "King" + getRealName();
                magical = true;
        }
        public boolean isMagical() { return magical; }
        public void setHeight (int newHeight) { height = newHeight; }
        public String getName () { return "I won't tell!"; }
        public String getRealName() { return name; }
        public void renameGnome(String s) { name = s; }
}


/*
 *  ENUM TYPES : only allowed to take on values tat come form a specified set of names
 *      SAMPLE -> public enum Day { MON, TUE, WED, THU, FRI, SAT, SUN };
 */
// ABSTRACT CODE EXAMPLE 
// public abstract void setHeight (double newHeight);
// CONSTRUCTOR CODE EXAMPLE
// public Fish (int w, String n){
//         weight = w; 
//         name = n;
// }
