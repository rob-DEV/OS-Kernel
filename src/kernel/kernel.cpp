#include "video.h"

extern "C"
void kmain(void)
{
    Video video;
    video.clear();
    video.write("Hello World! from C++");
    for(;;);
}
