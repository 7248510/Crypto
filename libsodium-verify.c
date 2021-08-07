//Method to install libsodium
//Install VCPKG
//Install libsodium
//Copy the folder C:\vcpkg\packages\libsodium_x86-windows
//Compile the solution without the IDE
//Like to boost I'll paste the compile flags
//cl /EHsc /sdl /W4 libsodium.c /I H:\Code\Github\Crypto\crypto\sodium\libsodium_x86-windows\include /link H:\Code\Github\Crypto\crypto\sodium\libsodium_x86-windows\lib\libsodium.lib
//cl /EHsc /sdl /W4 libsodium.c /I includeFolder /link libraryLocation
/*
Directory structure
libsodium-verify.c
libsodium.dll
libsodium_x86-windows(From vcpkg)
To build libsodium all you need is the correct command line arguments
To run the libsodium executable you need to place the dll file
*/
//Flags = /W4 Max warning levels, /sdl secure development life cycle, EHsc (formatting), /I Include directory, /link library location
#define __STDC_WANT_LIB_EXT1__ 1 //get_s
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sodium.h>
/*
This is an example of verification of password without the values encoded in the file.(Cleartext)
Reverse engineering binaries and cracking hashes has made me more aware of what's needed in software.
OWASP recommends Argon2
https://cheatsheetseries.owasp.org/cheatsheets/Password_Storage_Cheat_Sheet.html#argon2id
*/
int main(void) {
    int status = 0;
    //const char* password1 = "testPassword";
    printf("\nStarting libsodium!\n");
    if (sodium_init() < 0) {
        printf("Error! \nExiting.");
        status = EXIT_FAILURE;
        exit(status);
        /* panic! the library couldn't be initialized, it is not safe to use */
    }
    //char hashed_password[crypto_pwhash_STRBYTES];
    //if (crypto_pwhash_str(hashed_password, password1, strlen(password1), crypto_pwhash_OPSLIMIT_SENSITIVE, crypto_pwhash_MEMLIMIT_SENSITIVE) != 0) {
    //    printf("Out of memory");
    //    status = EXIT_FAILURE;
    //    return status;
        /* out of memory */
    //}
    //^ will create a new hash of testPassword. The hashes that are being used in the verify method are something I generated and wrote to a file. Both hashes evaluate to testPassword
    //This is an example of two different hashes same value. One right and another wrong
    int verify = crypto_pwhash_str_verify("$argon2id$v=19$m=1048576,t=4,p=1$rU5M0fp0WHMgFNTh1gNqWQ$Qk6x4OHY0PABK+MG6vAYcCPZllsSBpCOn71Jop1dGXo", "testPasswordalt", strlen("testPasswordalt"));
    int verify2 = crypto_pwhash_str_verify("$argon2id$v=19$m=1048576,t=4,p=1$U/QdhFjP2XMbZdbPw4uGcw$F4cUb1fyElFFHmdousjHjfhAKK7Tut6nTyF+F0qNXRY", "testPassword", strlen("testPassword"));
    if (verify == -1) {
        printf("Wrong password\nYou entered %s\n", "testPassword");
    }
    if (verify == 0) {
        printf("Correct password entered");
    }
    if (verify2 == -1) {
        printf("Wrong password\nYou entered %s", "testPassword");
    }
    if (verify2 == 0) {
        printf("Correct password!");
    }
    return status;
}
