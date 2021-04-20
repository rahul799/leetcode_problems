Clock Angle
Question 185 of 978
Given a clock time with hour and integer minutes, determine the smaller angle between the hour and the minute hands and floor it to the nearest integer.

Note that the hour hand moves too.

Bonus: When, during the course of a day, will the angle be zero?

Constraints

0 ≤ hour ≤ 23
0 ≤ minutes ≤ 59
Example 1
Input
hour = 12
minutes = 22




int solve(int hour, int minutes) {

         if (hour >= 12)
            hour -= 12;

        double h = ((double) hour * 360) / 12 + ((double) minutes * 360) / (12 * 60);
        double m = ((double) minutes * 360) / (60);
        //System.out.println(h + " " + m);
        double angle = abs(h - m);
        //System.out.println(angle);

        if (angle > 180) {
            angle = 360 - angle;
        }

        return (int) angle;
    }
    
