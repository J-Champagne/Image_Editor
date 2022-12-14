# Image Editor
## Introduction
This C++ CLI software can edit images from your terminal.

Uses low-level manipulations with no additional libraries.

Although only copying, converting to grayscale, and brightness adjustments are available,
efforts were made to make this software modular. Additional functionalities can be added with relative ease.

To run this software, simply type `make` in your terminal followed by `./img_editor.exe` with by the appropriate commands.
An image for testing 'bmp_24.bmp' has been added for convenience.

## Manual
```
Usage: img_editor.exe     [-h | --help] [-v | --version] [-f | —file <path>]
                          [-o | --output <path>] [-c | --copy] [-g | --grey | --gray]
                          [-b | --brightness <value>]

These are common commands used in various situations:

-v —-version       Shows current version.
-f —-file          Indicate image file to use. Must be followed by a path to the desired file.
-o --output        Indicate name to use for copy of image. Must be followed by a path for the newly created file.
                   By default, '(copy)' is appended between the image name and it's format. Ex. image.bmp -> image(copy).bmp
-c --copy          Copies the specified image.
-g --grey --gray   Converts image to grayscale. Automatically creates a copy of the image. *Only 24 bit BMP images supported*
-b --brightness    Adjusts the brightness. Must be followed by an integral. A + value will make the image brighter, 
                   while a negative value will make it darker. Brightness values range from 0 (Black) to 255 (White).

```

## Credit
Julien Champagne
