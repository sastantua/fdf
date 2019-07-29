# FDF

Fdf is the first project to manipulate a graphic library.
Here we use the mlx, (warning, bugs and leaks are courtesy of the staff).

In this project i parse the map, check that input data are valid and then store theses data in a int**.
Then I iterate on this double int table, check the values and set the pixel to the corresponding color.
Each pixel is set in a char* (the image i'll give to mlx_new_image() function)
I use bresenham algorithm to ensure that line looks smooth and I've also implemented event handling, rotation matrix, zoom, distortion, shape and grid colors.