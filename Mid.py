def CS_Encrypt(plaintext, key):
    result = ""
    for i in plaintext:
            ap = chr((ord(i) - 65 + key) % 26 + 65) 
            if ap == 'Q':
                ap = 'E'
            result += ap

    return result

def CS_Decrypt(ciphertext, key):
    result = ""
    for i in ciphertext:
            alp = chr((ord(i) - 65 - key) % 26 + 65) 

            if alp == 'E':
                alp = 'Q'
            result += alp

    return result

vowels = ['A', 'E', 'I', 'O', 'U']
while True:
    skey = input("Enter key: ").upper()
    if skey in vowels:
        print("Valid key accepted:", skey)
        break
    else:
        print("Invalid key")

while True:
    Ptext = input("Enter Plain text: ").upper()
    if Ptext.isalpha():
        print("Valid plain text:", Ptext)
        break
    else:
        print("Invalid plain text")

key = ord(skey)-65

print(" key:",key)
encrypted= CS_Encrypt(Ptext, key)
decrypted= CS_Decrypt(encrypted, key)
print("Encrypttext:", encrypted)
print("Decryp text:", decrypted)
