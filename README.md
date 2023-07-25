# stb-image-gif-apng-short-examples :sunrise_over_mountains::film_projector:
This repo contains short source code examples in C language using the awesone [stb image](https://github.com/nothings/stb/blob/master/stb_image.h):thumbsup: for decoding animated GIF & PNG (APNG) image files. [stb image](https://github.com/nothings/stb/blob/master/stb_image.h) is part of the great [stb library](https://github.com/nothings/stb):star_struck: from [nothings](https://github.com/nothings). Enjoy!

---

**Table of contents**

<!-- @import "[TOC]" {cmd="toc" depthFrom=2 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [Animated GIF short example](#animated-gif-short-example)
- [Any questions or comments are welcome :bird:](#any-questions-or-comments-are-welcome-bird)

<!-- /code_chunk_output -->


## Animated GIF short example

```bash
# Get latest stb_image.h from https://github.com/nothings/stb
wget https://raw.githubusercontent.com/nothings/stb/master/stb_image.h -O src/stb_image.h -q
# Download a nice animated gif with transparency
# Credit: Wikipedia, License: Creative Commons Attribution-Share Alike 4.0 International
wget https://upload.wikimedia.org/wikipedia/commons/6/63/Wikipedia_logo_puzzle_globe_spins_horizontally_and_vertically%2C_revealing_the_contents_of_all_of_its_puzzle_pieces%2C_without_background.gif -O wikipedia.gif -q
make clean all
build/stb_image_gif_example wikipedia.gif
```

## Any questions or comments are welcome :bird:
If you have any comments or questions, feel free to send me an email at coolcornucopia@outlook.com :email:.

--

Peace

coolcornucopia :smile:
