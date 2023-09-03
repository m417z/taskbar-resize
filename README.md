# taskbar-resize
A command line tool for resizing the Windows taskbar.

## Usage
    taskbar_resize.exe (-l|-r|-b|-t) new_size

Description:

`-l` - The taskbar is on the left.

`-r` - The taskbar is on the right.

`-b` - The taskbar is on the bottom.

`-t` - The taskbar is on the top.

`new_size` - The new size of the taskbar, in pixels.

**NB:** for top and bottom positions, you cannot resize to 3 rows from 1 row, you have to resize to 2 rows first then resize to 3 rows.

The following numbers are based on the taskbar with small icons (not the big ones):
```batch
taskbar_resize.exe -b 60 ===> 1 row
taskbar_resize.exe -b 70 ===> 2 rows
taskbar_resize.exe -b 110 ===> 3 rows
taskbar_resize.exe -b 150 ===> 4 rows
taskbar_resize.exe -b 180 ===> 5 rows
taskbar_resize.exe -b 220 ===> 6 rows
taskbar_resize.exe -b 250 ===> 7 rows
```

## Support
Windows versions before Windows 11 are supported. Windows 11 isn't supported. For Windows 11, check out the [Taskbar height and icon size](https://windhawk.net/mods/taskbar-icon-size) Windhawk mod.

## Compilation
* You can use Visual Studio 2019 or another version.
* The 32-bit version works with 64-bit Windows, no need to compile both the 64-bit version as well.
* To compile for windows XP choose a Windows XP platform toolset, for example "Visual Studio 2017 - Windows XP (v141_xp)".
