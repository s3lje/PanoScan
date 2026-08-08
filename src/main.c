#include <stdio.h>
#include <curl/curl.h>
#include <stdlib.h>

static size_t discard_body(void *ptr, size_t size, size_t nmemb, void *userdata) {
    (void)ptr; (void)userdata;
    return size * nmemb;
}

int main(){
    curl_global_init(CURL_GLOBAL_DEFAULT);
    CURL* curl = curl_easy_init();

    if (!curl){
        fprintf(stderr, "curl initialization failed...\n");
        return EXIT_FAILURE;
    }

    curl_easy_setopt(curl, CURLOPT_URL, "http://example.com");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, discard_body);
    curl_easy_setopt(curl, CURLOPT_NOBODY, 0L);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);

    CURLcode res = curl_easy_perform(curl);
    if (res == CURLE_OK){
        long status;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &status);
        printf("Status: %ld\n", status);
    } else {
        fprintf(stderr, "Request failed: %s", curl_easy_strerror(res));
    }

    curl_easy_cleanup(curl); 
    curl_global_cleanup();

    return EXIT_SUCCESS;
}
