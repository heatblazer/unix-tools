brightness-level
================

Manipulate backlight of the machine

## Build

    $ cd ramfs-mount
    $ qmake
    $ make install

## Usage
    recommended to add in a wrapper script to produce this:

    $ brightness-level /sys/class/backlight/*/brightness <1000 - 3000>
    
Enjoy :)
