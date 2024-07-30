//
//  Oven.h
//  KitchenOvens
//
//  Created by Aniket Sedhai on 6/17/24.
//

#ifndef Oven_h
#define Oven_h

class Oven
{
public:
    Oven();
    int GetCurrentTemperature(void) const;
    int GetSetTemperature(void) const;
    void SetSetTemperature(int target_temp);
    void TurnOn(int target_temp = 350);
    void TurnOff(void);
    bool IsOn() const;
    int GetMinimumTemperature() const;
    int GetMaximumTemperature() const;
    int GetRoomTemperature() const;
    void SimulatePassingOfTime(int minutes_to_pass);
        
private:
    int current_oven_temp;
    int set_oven_temp;
    int room_temp;
    bool my_oven_is_on;
    int max_oven_temp;
    int min_oven_temp;
};

#endif /* Oven_h */
