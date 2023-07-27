/* TODO add more channels support */
/* TODO add transparency management */
/* TODO add others color formats */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <SDL2/SDL.h>

#include "helpers.h"

/***** THE NEXT 3 LINES are important *****/
#define STBI_ONLY_PNG
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("Usage: %s filename.png\n", argv[0]);
		exit(1);
	}

	char *img_filename;
	unsigned char *img_file_buf = NULL;
	long img_file_buf_len;
	int img_w, img_h, img_channels, img_frames, img_fb_pitch, img_fb_size;
	unsigned char *img_fb;

	img_filename = argv[1];

	read_file_to_buffer(img_filename, &img_file_buf, &img_file_buf_len);

	/***** THE NEXT SINGLE LINE is important (single function call to decode all frames) *****/
	img_fb = stbi_load_from_memory(img_file_buf, img_file_buf_len, &img_w, &img_h, &img_channels, 4);

	if (img_fb == NULL)
		loge_and_exit("File \"%s\" not found, not correct or not a png!", img_filename);

	img_fb_pitch = img_w * img_channels;
	img_fb_size = img_fb_pitch * img_h;
	logd("Image %d x %d pixels, %d channels, %d frames, filename \"%s\"",
			img_w, img_h, img_channels, img_frames, img_filename);
	logd("img_fb_pitch %d, img_fb_size %d", img_fb_pitch, img_fb_size);
	free(img_file_buf);


	/* SDL part - only for demonstrating the stb image animation decoder works fine */
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *win_texture;
	SDL_Event event;
	int win_w, win_h, win_fb_pitch;
	void *win_fb;

	win_w = img_w;
	win_h = img_h;
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(win_w, win_h, 0, &window, &renderer);
	win_texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ABGR8888,
			SDL_TEXTUREACCESS_STREAMING, win_w, win_h);

	int y, frames;
	unsigned int img_addr, fb_addr;
	bool waiting = true;
	frames = 0;

	while (waiting) {
		SDL_LockTexture(win_texture, NULL, &win_fb, &win_fb_pitch);
		fb_addr = 0;
		img_addr = img_fb_size * frames;


		/***** THIS FOR LOOP IS IMPORTANT *****/
		for (y = 0; y < img_h; y++) {
			memcpy((void *)win_fb + fb_addr, (void *)img_fb + img_addr, img_fb_pitch);
			fb_addr += win_fb_pitch;
			img_addr += img_fb_pitch;
		}

		frames++;
		if (frames >= img_frames)
			frames = 0;

		SDL_UnlockTexture(win_texture);
		SDL_RenderCopy(renderer, win_texture , NULL, NULL);
		SDL_RenderPresent(renderer);

		if (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT: /* The user closed the window */
					waiting = false;
					break;
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym) {
						case SDLK_ESCAPE: /* Escape to close the window */
							waiting = false;
							break;
						default:
							break;
					}
				default:
					break;
			}
		} else
			SDL_Delay(1000/25); /* Short delay, avoiding consuming cpu for nothing */
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	/* Do not forget to free the buffer before leaving... */
	stbi_image_free(img_fb);

	return EXIT_SUCCESS;
}
