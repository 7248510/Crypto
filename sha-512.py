#I'm familiar with hashes, but I wanted to see how they work in DB'S/crypto
#SHA-512 is insecure for passwords. Regardless here's an example of password authentication via hashes
#https://developer.okta.com/blog/2021/03/05/ultimate-guide-to-password-hashing-in-okta
#http://oliviertech.com/python/generate-SHA512-hash-from-a-String/
import hashlib
import base64
inputString = input()
password = "test"
#okta
bytesHashed = hashlib.sha512(bytes(password, 'utf-8'))
inputHashed = hashlib.sha512(bytes(inputString, 'utf-8'))
#otech
defaultString = hashlib.sha512(str("test").encode("utf-8")).hexdigest()
inputString = hashlib.sha512(str(inputString).encode("utf-8")).hexdigest()

# Base64 encoded
testValComp = base64.b64encode(bytesHashed.digest()).decode("ascii")
inputValComp = base64.b64encode(inputHashed.digest()).decode("ascii")
print("Hashes are not encoded")
print("HASHED VAL:" ,defaultString)
print("INPUT VAL:",inputString)

if (defaultString == inputString):
    print("You've got a match\nCorrect password!")
else:
    print("No match")

print("Hashes are encoded")
print("HASHED VAL:" , testValComp)
print("INPUT VAL:", inputValComp)
if (testValComp == inputValComp):
    print("You've got a match\nCorrect password!")
else:
    print("No match")