#ifndef HELPERS_H
#define HELPERS_H

#ifdef LOG_LONG_INFO
    #define log(type, fmt, args...) \
            printf(type " %s %s(%d): " fmt "\n", __FILE__, __FUNCTION__, __LINE__, ##args);
#else
    #define log(type, fmt, args...) \
            printf(type " " fmt "\n", ##args);
#endif

#define logi(fmt, args...) log("INFO ", fmt, ##args)
#define loge(fmt, args...) log("ERROR", fmt, ##args)

#ifdef DEBUG
    #define logd(fmt, args...) log("DEBUG", fmt, ##args)
#else
    #define logd(fmt, args...) do {} while (0)
#endif


#define loge_and_exit(fmt, args...) \
	do { \
		loge(fmt, ##args); \
		exit(1); \
	} while (0)

void read_file_to_buffer(char *file_name, unsigned char **file_buf, long *file_size);

#endif
