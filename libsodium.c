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
libsodium.c
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
//Place the lib sodium DLL in the running directory.
int main(void) {
    int status = 0;
    const char* password1 = "testPassword";
    char inputVal[50];
    size_t length = sizeof(inputVal);
    printf("Please enter a password:\n");
    if (gets_s(inputVal, length) == NULL) {
        printf("ERROR\nInvalid input");
        status = EXIT_FAILURE;
        exit(status);
        //Cert & MSDN
    }
    const char* password2 = inputVal;
    printf("\n%s\n", password2);
    printf("\nStarting libsodium!\n");
    if (sodium_init() < 0) {
        printf("Error! \nExiting.");
        status = EXIT_FAILURE;
        exit(status);
        /* panic! the library couldn't be initialized, it is not safe to use */
    }
    char hashed_password[crypto_pwhash_STRBYTES];
    if (crypto_pwhash_str(hashed_password, password1, strlen(password1), crypto_pwhash_OPSLIMIT_SENSITIVE, crypto_pwhash_MEMLIMIT_SENSITIVE) != 0) {
        printf("Out of memory");
        status = EXIT_FAILURE;
        return status;
        /* out of memory */
    }
    if (crypto_pwhash_str_verify(hashed_password, password2, strlen(password2)) != 0) {
        printf("Wrong password\nYou entered %s", password2);
        status = EXIT_FAILURE;
        return status;
    }
    else {
        printf("Correct password entered");
    }
    return status;
}
