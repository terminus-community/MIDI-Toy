/*
 * C example.
 * Uses CURL library: https://curl.haxx.se/
 * Built using gcc version 7.5.0, tested on Ubuntu 18.04.5.
 *
 * TODO: cleanup callbacks / hide ACK response.
 *
 * Building
 * gcc tutorial.c -lcurl -o tutorial
 */

#include <unistd.h>
#include <stdio.h>
#include <curl/curl.h>

// Performs an HTTP request to play or stop a note
void note_req(CURL *curl, char * mode, int note, int velocity) {
    char url_buffer [128];
    sprintf(
        url_buffer,
        "http://192.168.4.1/%s?pitch=%d&velocity=%d",
        mode,
        note,
        velocity
        );
    curl_easy_setopt(curl, CURLOPT_URL, url_buffer);
    curl_easy_perform(curl);
}

int main(int argc, char * argv []) {
    const int VELOCITY = 60;
    int note;
    CURL *curl;
    CURLcode res;
    // Init CURL
    curl = curl_easy_init();
    // Iterate the notes
    if (curl) {
        for (note = 22; note < 107; note++) {
            note_req(curl, "on", note, VELOCITY);
            usleep(1000);
            note_req(curl, "off", note, VELOCITY);
            usleep(1000);
            printf("\nNote: %d \n", note);
        }
        curl_easy_cleanup(curl);
    }
    return 0;
}
