#ifndef MOBIUS_WINDOWS_LOG_H
#define MOBIUS_WINDOWS_LOG_H

#include <cstdio>

#if defined(WIN32)

#if defined(ENABLE_DEBUG_LOG)
#define LOGD(msg, ...) fprintf(stdout, "D: [%s:%d] " msg "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
#define LOGD(...)
#endif // ENABLE_DEBUG_LOG

#define LOGI(msg, ...) fprintf(stdout, "I: [%s:%d] " msg "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define LOGW(msg, ...) fprintf(stdout, "W: [%s:%d] " msg "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define LOGE(msg, ...) fprintf(stderr, "E: [%s:%d] " msg "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__)

#else

#if defined(ENABLE_DEBUG_LOG)
#define LOGD(format, ...) printf("D: " format "\n", ##__VA_ARGS__)
#else
#define LOGD(...)
#endif // ENABLE_DEBUG_LOG

#define LOGI(format, ...) printf("I: " format "\n", ##__VA_ARGS__)
#define LOGW(format, ...) printf("W: " format "\n", ##__VA_ARGS__)
#define LOGE(format, ...) printf("E: " format "\n", ##__VA_ARGS__)

#endif // ANDROID

#endif //MOBIUS_WINDOWS_LOG_H
