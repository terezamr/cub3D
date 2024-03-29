## Cub3d

The goal of cub3d is to create a realistic 3D graphical environment from a first-person perspective, inspired in Wolfenstein 3D. The Ray-Casting principles must be used. This project is written in c using mini-libx library. Co-developed in July 2023 with Rafael Coias.

Implemented features: 4 different wall textures, according to the direction (present in ``inc/textures/``), movement in the 4 directions + rotation.

### Usage

```shell
./cub3D <map.cub>
```

 KEY           | Action        |
| ------------- |:-------------:|
| `A`           | move right     |
| `D`           | move left    |
| `W`           | move forward  |
| `S`           | move backward |
| `→`           | rotate left |
| `←`           | rotate right   |


### Rules

- Use miniLibX. Use of images of the minilibX is strongly recommended
- The management of your window must remain smooth: changing to another window, minimizing, etc.
- Display different wall textures that vary depending on which side the wall is facing (North, South, East, West)
- Set the floor and ceiling colors to two different ones
- Pressing ESC or clicking on the red cross on the window’s frame must close the window and quit the program cleanly
- The program takes as a first argument a scene description file with the .cub extension
- .cub file rules
   - Defines 6 elements (North, South, West and East textures + floor and ceiling colors)
  - Textures elements are defined as followed (identifier + path to the texture):   ``NO ./path_to_the_north_texture``
  - Color elements are defined as followed (identifier + RGB colors in range [0, 255]):   ``F 220,100,0``
  - The map content if defined after the elements (elements can be set in any order, but the map contente has to be the last)
  - Except from the map content, elements can be separated by lines or spaces; 
- Map rules
  - composed of only 6 possible characters: N, S, E or W (player’s start position and orientation), 0 or 1 (empty space and wall)
  - surrounded by walls

 
### Screenshots

<p float="left">
  <img src="https://github.com/terezamr/cub3D/assets/80223858/3af94175-6466-4a4f-9de3-6823b42bb7f4" width="500" />
  <img src="https://github.com/terezamr/cub3D/assets/80223858/59dfc775-f59d-40df-8270-46f6eab077d6" width="500" /> 
</p>

### References
- http://users.atw.hu/wolf3d/
- https://lodev.org/cgtutor/raycasting.html
