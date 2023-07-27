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

```bash
# Get latest stb_image.h from https://github.com/nothings/stb
wget https://raw.githubusercontent.com/nothings/stb/master/stb_image.h -O src/stb_image.h -q

# Download a nice animated gif with transparency
# Credit: Wikipedia, License: Creative Commons Attribution-Share Alike 4.0 International
wget https://upload.wikimedia.org/wikipedia/commons/6/63/Wikipedia_logo_puzzle_globe_spins_horizontally_and_vertically%2C_revealing_the_contents_of_all_of_its_puzzle_pieces%2C_without_background.gif -O wikipedia.gif -q

# Build in release (use "make debug" for step by step debug)
make clean release
build/stb_image_gif_example wikipedia.gif
```

## Any questions or comments are welcome :bird:
If you have any comments or questions, feel free to send me an email at coolcornucopia@outlook.com :email:.

--

Peace

coolcornucopia :smile:
