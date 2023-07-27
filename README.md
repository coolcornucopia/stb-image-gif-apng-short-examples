# stb image gif & apng short examples :sunrise_over_mountains: :film_projector:
This repo contains short source code examples in C language using the awesone [stb image](https://github.com/nothings/stb/blob/master/stb_image.h) :thumbsup: for decoding animated GIF & PNG image files.

[stb image](https://github.com/nothings/stb/blob/master/stb_image.h) is part of the great [stb library](https://github.com/nothings/stb) :star_struck: from [nothings](https://github.com/nothings).

Enjoy!

---

**Table of contents**

<!-- @import "[TOC]" {cmd="toc" depthFrom=2 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [TL;DR](#tldr)
- [Animated GIF short example](#animated-gif-short-example)
- [Animated PNG short example (APNG)](#animated-png-short-example-apng)
- [Any questions or comments are welcome :bird:](#any-questions-or-comments-are-welcome-bird)

<!-- /code_chunk_output -->

## TL;DR
* **gif** I did not find a way for decoding animated gif **frame by frame** with [stb image](https://github.com/nothings/stb/blob/master/stb_image.h), that is an issue for big animated gif (too long time before displaying the first frame + too much memory consumption).
* **apng** [stb image](https://github.com/nothings/stb/blob/master/stb_image.h) does not support animated png (apng). I thought apng was supported after the read of the [jcredmond/stb_image-apng.c](https://gist.github.com/jcredmond/9ef711b406e42a250daa3797ce96fd26) gist but this code requires a patch on top of stb image. You may use instead several png files.
* **mjpeg** [stb image](https://github.com/nothings/stb/blob/master/stb_image.h) does not support mjpeg. You may use instead several jpeg files or search inside your mjpeg buffer each jpeg EOI before calling the decoder (idea from [Creating a Videoplayer for ESP32](https://www.appelsiini.net/2020/esp32-mjpeg-video-player/)).
* **gif** If you encounter a "segmentation fault" with a given gif, you can re-encode it with gifsicle (see [stb image issue 1504](https://github.com/nothings/stb/issues/1504) for details).
  ```bash
  gifsicle -O3 gif_creating_seg_fault_with_stb_image.gif -o gif_ok_with_stb_image.gif
  ```

Despite above comments, I really like the awesome [stb library](https://github.com/nothings/stb):smile:.

## Animated GIF short example
[stb image](https://github.com/nothings/stb/blob/master/stb_image.h) is easy to use for decoding an animated gif. After reading the entire gif file in a memory buffer (fopen/fread/fclose for instance, see [src/helpers.c](https://github.com/coolcornucopia/stb-image-gif-apng-short-examples/blob/main/src/helpers.c#L8)), give this buffer to the stbi function ***stbi_load_gif_from_memory()*** that will return a buffer containing on uncompressed gif (see [stb_image_gif_example.c](https://github.com/coolcornucopia/stb-image-gif-apng-short-examples/blob/main/src/stb_image_gif_example.c#L37)).

To build and test this example, use following instructions:

```bash
# Get latest stb_image.h from https://github.com/nothings/stb
wget https://raw.githubusercontent.com/nothings/stb/master/stb_image.h -O src/stb_image.h -q

# Download nice animated gif with transparency
# From https://commons.wikimedia.org/wiki/File:Wikipedia_logo_puzzle_globe_spins_horizontally_and_vertically,_revealing_the_contents_of_all_of_its_puzzle_pieces,_without_background.gif
# Credit: Wikipedia, License: Creative Commons Attribution-Share Alike 4.0 International
wget https://upload.wikimedia.org/wikipedia/commons/6/63/Wikipedia_logo_puzzle_globe_spins_horizontally_and_vertically%2C_revealing_the_contents_of_all_of_its_puzzle_pieces%2C_without_background.gif -O wikipedia_logo_puzzle_globe_without_background.gif -q
# From https://commons.wikimedia.org/wiki/File:Rotating_earth_(large)_transparent.gif
# Credit: Wikipedia, License: Creative Commons Attribution-Share Alike 3.0 International
wget https://upload.wikimedia.org/wikipedia/commons/a/a9/Rotating_earth_%28large%29_transparent.gif -O wikipedia_rotating_earth_transparent.gif  -q

# Build in release (use "make debug" for step by step debug)
make clean release
build/stb_image_gif_example wikipedia_logo_puzzle_globe_without_background.gif
build/stb_image_gif_example wikipedia_rotating_earth_transparent.gif
```


## Animated PNG short example (APNG)
**IMPORTANT** [stb image](https://github.com/nothings/stb/blob/master/stb_image.h) does not support animated png (apng). I thought apng was supported after the read of the [jcredmond/stb_image-apng.c](https://gist.github.com/jcredmond/9ef711b406e42a250daa3797ce96fd26) gist but this code requires a patch on top of stb image. You may use instead several png files. Ie, in the [stb_image_png_example.c](https://github.com/coolcornucopia/stb-image-gif-apng-short-examples/blob/main/src/stb_image_png_example.c), only the first png frame will be decoded and displayed.

To build and test this example, use following instructions:
```bash
# Get latest stb_image.h from https://github.com/nothings/stb
wget https://raw.githubusercontent.com/nothings/stb/master/stb_image.h -O src/stb_image.h -q

# Download nice animated png with transparency
# From https://commons.wikimedia.org/wiki/File:Animated_PNG_example_bouncing_beach_ball.png
# Credit: Holger Will, License: Public domain
wget https://upload.wikimedia.org/wikipedia/commons/1/14/Animated_PNG_example_bouncing_beach_ball.png -O wikipedia_bouncing_beach_ball.png -q


# Build in release (use "make debug" for step by step debug)
make clean release
build/stb_image_png_example wikipedia_bouncing_beach_ball.png
```

## Any questions or comments are welcome :bird:
If you have any comments or questions, feel free to send me an email at coolcornucopia@outlook.com :email:.

--

Peace

coolcornucopia :smile:
