
public class Date {
        int year;
        int month;
        int day;
        
        public Date (){
            this.year = 2022;
            this.month = 9;
            this.day = 19;
        }
        public Date (int month, int day) {
            this.year = 2022;
            this.month = month;
            this.day = day;
        }
        public Date (int year, int month, int day) {
            this.year = year;
            this.month = month;
            this.day = day;
        }
        public static Date getDate () {
            return new Date();
        }
        public boolean isNumber (int key) {
            return key > 47 && key < 58;
        }
        public boolean isDateValid (String givenDate) {
            int i, key, len = givenDate.length(), counter = 0, MAX = 8;
            for (i = 0; i < len; i++) {
                key = givenDate.charAt(i);
                if (isNumber (key)) counter++;
            }
            if (counter == MAX) return true;
        }
    
        public static void setDate (String date) {
 
                if (isDateValid (date)) {
                        int year = Integer.parseInt(date.substring(0, 4));
                        int month = Integer.parseInt(date.substring(4, 6));
                        int day = Integer.parseInt(date.substring(6, 8));
                        Date newDate = new Date(year, month, day);
                }
        }
    
        public String modifyYear (int year) {
            String yearFormat = "";
            int temp = year;
            if (year > 10000) return Integer.toString(this.year);
            if (year < 999) {
                while (temp / 1000 == 0) {
                    yearFormat = yearFormat.concat("0");
                    temp = temp * 10;
                }
            }
            return yearFormat + Integer.toString (year);
        }
        public boolean isLeapYear (int year) {
            return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
        }
        public int daysOfMonth (int month) {
            if (month < 8 && month % 2 == 1 || month > 7 && month % 2 == 0) return 31;
            if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
            return 2;
        }
    
        public boolean isDayValid (int year, int month, int day) {
            //boolean isValid = false;
            if (month > 0 && month < 13)
                return ((month == 2 && (isLeapYear(year) && day < 30
                                    || !isLeapYear(year) && day < 29)) ||
                        (day < 31 && daysOfMonth(month) == 30)||
                        (day < 32 && daysOfMonth(month) == 31));
            return false;
        }
    
        public String modifyMonth (int month) {
            String monthFormat = "";
            if (month > 0 && month < 13) {
                if (month < 10) monthFormat = "0";
                return monthFormat + Integer.toString(month);
            } else {
                if (this.month < 10) monthFormat = "0";
                return monthFormat + Integer.toString(this.month);
            }
        }
        
        public String modifyDay (int day) {
            String dayFormat = "";
            if (day > 0 && day < 32) {
                if (day < 10) dayFormat = "0";
                return dayFormat + Integer.toString(day);
            } else {
                if (this.day < 10) dayFormat = "0";
                return dayFormat + Integer.toString(this.day);
            }
        }
    
        public String toString () {
            return modifyYear(year) + "-" + modifyMonth(month) + "-" + modifyDay(day);
        }
    
    }
    