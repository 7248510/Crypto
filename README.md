# Crypto
Cryptography code

# Libsodium
Instructions are written in the example comments for now. I will convert them into the readme later.
## Motivations
Originally I was going to use OpenSSL for password hashing, but OWASP recommends the Argon2 protocol.<br>
Even if I did not use Argon2(SHA'S/MD5) I could not ensure safe code using OpenSSL.<br> 
Between Stackoverflow Q&A and random blog posts the majority of code samples lacked error checking.<br>
Libsodium offers understandable documentation and error checking within the example.
