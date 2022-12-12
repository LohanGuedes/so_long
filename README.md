<h1 align="center">Welcome to so_long 👋</h1>
<p>🎮 The purpose of this project is to make a very small 2D game using textures, sprites, keyboard events and many others.</p>

## Goal
I believe that the goal of this project, was learn how to treat
bugs, how to work with libraries, read documentation and the most
important thing: how to use **BFS algorithms** And how to debbug Recursion in *gdb/lldb*.

## Install

For installing this project, refer to [minilibx](https://github.com/42Paris/minilibx-linux) and It's dependencies.
You'll also need:

1. C compiler(`gcc/clang`). which you can set under the Makefile inside this project root, for that change the `CC` variable inside it.
2. `gnu make`. For building the project.

## Maps

Maps are found inside the **Maps** folder, maps should follow some rules shown below:

1. **1's** are walls
2. **0's** are grounds
3. **P** is the player
4. **C's** are collectables
5. **E's** are exits
6. The maps files should end with a .ber extension.
7. It's required to exist a valid path to all colectables and at least one exit.
8. The map must be surrounded by walls.
9. The map must be retangular (all lines with the same length)
10. There must be only one P

If the map do not follow the rules a error will be shown in the promt.

The goal of those rules was to make sure the user enter the right thing into the app, bny showing helpful information.

## Usage

`./so_long <path-to-map>.ber`

## Author

👤 **Lohan Guedes**

- Github: [@lguedes](https://github.com/lohanguedes)
- LinkedIn: [@lohan-guedes](https://www.linkedin.com/in/lohan-guedes-0349b5239/)

## Show your support

Feel free to fork this project and send a pull request to it! I would love to see possible improvements :mending_heart:.
Give a ⭐️ if this project helped you!
