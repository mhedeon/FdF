# fdf
```
  This project is about creating a simplified graphic “wireframe” (“fils de fer” in french,
hence the name of the project) representation of a relief landscape linking various points
(x, y, z) via segments. The coordinates of this landscape are stored in a file passed as
a parameter to the program.
```
    
Download:
```
  git clone https://github.com/mhedeon/FdF && cd FdF
```

Compile:
```
  make
```

Delete:
```
  make fclean
```

Usage:
```
  ./fdf [filename]
```
    
Files are located at:
```
  ./maps/
```

Filename looks like this:
```
  42.fdf
```

Controls:

```
Help menu: H [on/off]

Move: ARROWS

Zoom: +, -

Change size: <, >

Rotate around x coordinate: X

Rotate around y coordinate: Y

Rotate around z coordinate: Z

Blur: ENTER [on/off]

Exit: ESc
```
    
Files looks like this:
![file](https://github.com/mhedeon/FdF/blob/master/Img/file.png)

How it looks at program:
![file](https://github.com/mhedeon/FdF/blob/master/Img/42.png)
![file](https://github.com/mhedeon/FdF/blob/master/Img/pylone.png)
![file](https://github.com/mhedeon/FdF/blob/master/Img/map.png)
