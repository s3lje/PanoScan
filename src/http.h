#ifndef __HTTP_H
#define __HTTP_H

#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long status;
} curl_response_t;

long http_get_status(char *url);


#endif
