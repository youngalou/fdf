**Fdf**
=======


## Overview
For this project, I was tasked with making a wireframe display program that can take a formatted text file holding a topographical map, and display it as a 3D rendering in the form of a wireframe. Unsatisfied with a simple 3D display, I went ahead and implemented a few extra functionalities to make the program a lot more interesting:
1. Precise Controls
>- 360 degree rotation for any view angle.
>- Zoom to see smaller details or the bigger picture.
>- Translation through the wireframe.
2. Color Scheme
>- 10 color schemes to choose from.
3. Optimization
>- Image placement of all pixels *after* individual calculations as opposed to placement with each step.


## Install
- <i class="icon-folder-open"></i> Navigate to the desired directory and run in your shell:
`git clone https://github.com/youngalou/fdf.git`
- <i class="icon-folder-open"></i> Enter the repository you just cloned and run:
`make`


## Controls
- **Color Scheme**
Each of the buttons on the numpad <kbd>0</kbd>-<kbd>9</kbd> will set the display to a unique color scheme.

- **Rotation**
Use the arrow keys <kbd>&uarr;</kbd><kbd>&larr;</kbd><kbd>&darr;</kbd><kbd>&rarr;</kbd> to rotate the display about the y-axis and x-axis.

- **Zoom**
Use the <kbd>+</kbd> and <kbd>-</kbd> keys to zoom in and out respectively. (Note that the further you zoom in, the more load will be put on the computer.)

- **Translation**
Use the <kbd>w</kbd><kbd>a</kbd><kbd>s</kbd><kbd>d</kbd> keys to translate the display in their respective directions.

- **Reset**
Hit the <kbd>tab</kbd> key to reset the display to its initial position. This will not reset the color scheme.
