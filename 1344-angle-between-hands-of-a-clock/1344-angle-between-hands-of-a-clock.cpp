class Solution {
public:
    double angleClock(int hour, int minutes) {

       double hourAngle = (hour%12)*30 + 0.5*minutes;
       double minuteAngle = minutes*6;

       double angle = abs(minuteAngle-hourAngle);

       return min(angle,360-angle);
    }
};