
# My_radar

## Description

2D visualization panel showing a simulation of air traffic.

### Rules
- Aircraft flies from a point A to a point B at a given speed
- If an aircraft collides with another one, the two aircrafts disappear
- Control towers don’t move and have control areas
- Control areas allow aircrafts to collide with each other without being destroyed

![](https://github.com/Krapaince/my_radar/blob/master/resources/my_radar.gif)

## Graphical explanation

### Sprite
 - ![Aircraft_sprite](https://github.com/Krapaince/my_radar/blob/master/resources/aircraft.png) Aircraft
 - ![Tower_sprite](https://github.com/Krapaince/my_radar/blob/master/resources/radar.png) Control tower

### Shapes
- The rectangle grid represents a quadtree
- The square represents the aircraft
- The red circle represents control tower area

  The colors of the aircraft and the rectangle grid indicate the depth of the element in the quadtree

| Depth | Color   |
|-------|---------|
| 0     | Green   |
| 1     | Cyan    |
| 2     | Blue    |
| 3     | Magenta |
| 4     | Orange  |

## Features
### USER INTERACTIONS: (available every second)
    'L'         enable/disabled hitboxes and areas
    'S'         enable/disabled sprites
    'B'         enable/disabled background

|L -   Hitboxes and areas | tower | aircraft    | quadtree |  S - Sprites  | tower   | aircraft |  B  - Background |
|:-----------------------:|:-----:|:-----------:|:--------:|:-------------:|:-------:|:--------:|:----------------:|
|             0           |    ON |             |          |      0        |         |          |        ON        |
|             1           |    ON |             |   ON     |     1         |  ON     |          |        OFF       |
|             2           |    ON |    ON       |          |     2         |         |   ON     |
|             3           |       |    ON       |          |   3 - Default |  ON     |   ON     |
|             4           |       |    ON       |   ON     |
|             5           |       |             |   ON     |
|             6           |       |             |          |
|             7 - Default |  ON   |    ON       |   ON     |
### When

This project was done in 2018 during my first school year.

## Prerequisites
- CSFML
- LIBC
## Usage

```
git clone https://github.com/Krapaince/my_radar.git
cd my_radar
make
make generator
./generator -h
./my_radar -h
./my_radar input_map
```
