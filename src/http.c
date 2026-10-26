#include "http.h"
 
long http_get_status(char* url){
    CURL* curl_handle = curl_easy_init();
    long status;

    curl_easy_setopt(curl_handle, CURLOPT_URL, url);
    curl_easy_setopt(curl_handle, CURLOPT_NOBODY, 0L);
    curl_easy_setopt(curl_handle, CURLOPT_TIMEOUT, 5L);

    CURLcode res = curl_easy_perform(curl_handle);
    curl_easy_getinfo(curl_handle, CURLINFO_RESPONSE_CODE, status);
    
    return status; 
}
