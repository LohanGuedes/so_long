# So_Long
So_long is a simple little game that I made in 42|RIO.
It's my first graphic project in C or in any other language.

## Goal
I believe that the goal of this project, was to imagine how to treat
bugs, how to work with libraries,  read documentation and the most
important thing: how to use GDB/Recursion.

> Yes. gdb is better than lldb.

## Install

For installing this project, refer to [minilibx](https://github.com/42Paris/minilibx-linux) and It's dependencies.
You'll also need:

1.  gcc/clang.  AKA a C compiler. which you can set under the Makefile inside this project root.
2. gnu make. For building the project.

## Maps

Maps are found inside the **Maps** folder, maps should follow some rules shown below:

1. *1's* are walls
2. *0's* are grounds
3. *P* is the player
4. *C's* are collectables
5. *E's* are exits
6. The maps files should end with a .ber extension.
7. It's required to exist a valid path to all colectables and at least one exit.
8. The map must be surrounded by walls.
9. The map must be retangular (all lines with the same length)
10. There must be only one P

If the map do not follow the rules a error will be shown in the promt.

## Usage

`./so_long <path-to-map>.ber`


## With Love

lguedes
