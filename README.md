# taskbar-resize
A command line tool for resizing the Windows taskbar.

# Usage
    taskbar_resize.exe (-l|-r|-b|-t) new_size

Description:

`-l` - The taskbar is on the left.

`-r` - The taskbar is on the right.

`-b` - The taskbar is on the bottom.

`-t` - The taskbar is on the top.

`new_size` - The new size of the taskbar, in pixels.

__________

**NB:** for top and bottom positions, you cannot resize to 3 rows from 1 row you have to resize to 2 rows first then resize to 3 rows

the following numbers are based on the taskbar with small icons not the big ones
```batch
taskbar_resize.exe -b 60 ===> 1 row
taskbar_resize.exe -b 70 ===> 2 rows
taskbar_resize.exe -b 110 ===> 3 rows
taskbar_resize.exe -b 150 ===> 4 rows
taskbar_resize.exe -b 180 ===> 5 rows
taskbar_resize.exe -b 220 ===> 6 rows
taskbar_resize.exe -b 250 ===> 7 rows
```

to compile it for windows xp choose "Visual Studio 2013 - Windows XP (v120_xp)" in Plataform Toolset
