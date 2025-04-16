#include "log.h"
#include "error.h"

#define TAG "main"

int main(void) {
    LOG(TAG, "Hello, %s!", "world");
    LOGE(TAG, ERROR_OK);
}
