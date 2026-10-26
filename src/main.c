#include <stdio.h>
#include <curl/curl.h>
#include <stdlib.h>
#include "http.h"

static size_t discard_body(void *ptr, size_t size, size_t nmemb, void *userdata) {
    (void)ptr; (void)userdata;
    return size * nmemb;
}

int main(){
    curl_global_init(CURL_GLOBAL_DEFAULT);

    long status = http_get_status("http://example.com");

    printf("Status: %ld\n", status);

    curl_global_cleanup();

    return EXIT_SUCCESS;
}
