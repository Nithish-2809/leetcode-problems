class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        double angleByHourHand = 30*hour + minutes*0.5;
        double angleByMinuteHand = minutes*6;

        return min(360-abs(angleByMinuteHand-angleByHourHand),abs(angleByMinuteHand-angleByHourHand));

    }
};