 
## Clock Angle

### Description
This project involves implementing a program using class inheritance to calculate the angle between the hour and minute hands of a clock. It includes two classes: 'Clock' and 'Clock_angle'. 'Clock' class stores the minutes, hour, and meridiem, while 'Clock_angle' inherits from 'Clock' and calculates the clock angle.

### Classes and Methods
#### Clock Class
Attributes:
- Minutes
- Hour
- Meridiem

Methods:
- `display_time()`: Displays the time in 'hh:mm' format.

#### Clock_angle Class
Attributes:
- Angle

Methods:
- `calculate_clock_angle()`: Calculates the angle between the hour and minute hands of the clock.
- `display_time()`: Displays the time in 24-hour format 'XXXX hrs'.

### Usage
1. Create an instance of the 'Clock' class.
2. Set the minutes, hour, and meridiem using setters.
3. Call the `display_time()` function to display the time.
4. Create an instance of the 'Clock_angle' class, inheriting from 'Clock'.
5. Set the minutes, hour, meridiem, and angle using setters.
6. Call the `display_time()` function to display the time.
7. Call the `calculate_clock_angle()` function to calculate the clock angle.

### Note
Assume all angles are positive and consider the smaller of the two possible angles between the hands.

