//
//  Oven.cpp
//  KitchenOvens
//
//  Created by Aniket Sedhai on 6/17/24.
//

#include <stdio.h>
#include "Oven.h"
#include <thread>
#include <chrono>
#include <iostream>

Oven::Oven() : current_oven_temp(72), room_temp(72), set_oven_temp(350), my_oven_is_on(false), max_oven_temp(550), min_oven_temp(200)
{
    //Nothing here
}

int Oven::GetCurrentTemperature() const
{
    return current_oven_temp;
}

int Oven::GetSetTemperature() const
{
    return set_oven_temp;
}

void Oven::SetSetTemperature(int target_temp)
{
    if (target_temp > max_oven_temp)
        set_oven_temp = max_oven_temp;
    else if (target_temp < min_oven_temp)
        set_oven_temp = min_oven_temp;
    else
    {
        set_oven_temp = target_temp;
    }
    
    return;
}

void Oven::TurnOn(int target_temp)
{
    set_oven_temp = target_temp;
    my_oven_is_on = true;
    
    return;
}

void Oven::TurnOff()
{
    my_oven_is_on = false;
    
    return;
}

bool Oven::IsOn() const
{
    return my_oven_is_on;
}

int Oven::GetMaximumTemperature() const
{
    return max_oven_temp;
}

int Oven::GetMinimumTemperature() const
{
    return min_oven_temp;
}

int Oven::GetRoomTemperature() const
{
    return room_temp;
}

void Oven::SimulatePassingOfTime(int minutes_to_pass)
{
    for (int i = 0; i < minutes_to_pass; ++i)
    {
        std::this_thread::sleep_for(std::chrono::minutes(1));
        
        if (my_oven_is_on == true)
        {
            if (current_oven_temp < set_oven_temp)
            {
                current_oven_temp += 25;
                if (current_oven_temp >= set_oven_temp)
                {
                    current_oven_temp = set_oven_temp;
                    return;
                }
            }
            else if (current_oven_temp > set_oven_temp)
            {
                current_oven_temp -= 15;
                if (current_oven_temp <= set_oven_temp)
                {
                    current_oven_temp = set_oven_temp;
                    return;
                }
            }
        }
        else
        {
            if (current_oven_temp > room_temp)
            {
                current_oven_temp -= 15;
                if (current_oven_temp <= room_temp)
                {
                    current_oven_temp = room_temp;
                    return;
                }
            }
        }
    }
    return;
}
