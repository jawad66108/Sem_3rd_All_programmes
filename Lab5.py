# def cr(text, key):
#     result = ""
#     for m in text:
#         if m.isupper():
#             result += chr((ord(m) - 65 + key) % 26 + 65)
#         else:
#             result += m
#     return result

# def dcr(text, key):
#     return cr(text, -key)

# # Encrypt and decrypt
# encrypted = cr("JAWAD", 3)
# print("Encrypted:", encrypted)

# decrypted = dcr(encrypted, 3)
# print("Decrypted:", decrypted)



# import string, random

# alphabet = list(string.ascii_uppercase) 
# print(alphabet)
# key = alphabet.copy()
# random.shuffle(key) 
# print(key)

# encrypt_map = {}
# decrypt_map = {}


# for i in range(len(alphabet)):
#     encrypt_map[alphabet[i]] = key[i]
#     decrypt_map[key[i]] = alphabet[i]

# message = "jawad"

# cipher = ""
# for letter in message:
#     if letter.isalpha():
#         cipher += encrypt_map[letter.upper()]
#     else:
#         cipher += letter

# plain=""
# for letter in message:
#     if letter.isalpha():
#         plain += decrypt_map[letter.upper()]
#     else:
#         plain += letter

# print("Plain text: ",message)
# print("Encrypted: ",cipher)
# print("Decrypted: ",plain)


# def vig_encr(text,key):
#     chipher =""
#     key =key.upper()

#     for i,ch in enumerate(text.upper()):
#         if ch.isalpha():
#             shift = ord(key[i%len(key)]) -65

#             chipher += chr(((ord(ch)- 65 +shift) % 26 ) + 65)
#         else:
#             chipher += ch

#     return chipher

# def vig_dencr(text,key):
#     plain =""
#     key =key.upper()

#     for i,ch in enumerate(text.upper()):
#         if ch.isalpha():
#             shift = ord(key[i%len(key)]) -65

#             plain += chr(((ord(ch)- 65 -shift) % 26) + 65)
#         else:
#             plain += ch

#     return plain
# a=vig_encr("jawad", "let")
# b=vig_dencr(a, "let")
# print("Encrypted:", a)
# print("Decrypted:", b)




# message = input("Enter your message: ")
# key = int(input("Enter numeric key: "))


# cipher = ""
# for ch in message:
#     if ch.isalpha():
#         base = ord('A') if ch.isupper() else ord('a')
#         cipher += chr((ord(ch) - base + key) % 26 + base)
#     else:
#         cipher += ch

# print("Encrypted message:", cipher)

# plain = ""
# for ch in cipher:
#     if ch.isalpha():
#         base = ord('A') if ch.isupper() else ord('a')
#         plain += chr((ord(ch) - base - key) % 26 + base)
#     else:
#         plain += ch

# print("Decrypted message:", plain)

import random
import string

letters = list(string.ascii_uppercase)

shuffled = letters.copy()
random.shuffle(shuffled)


enc_map = dict(zip(letters, shuffled))
dec_map = {v: k for k, v in enc_map.items()}


print("Encryption Mapping:")
for k, v in enc_map.items():
    print(f"{k} -> {v}")


message = input("\nEnter your message: ")


cipher = ""
for ch in message:
    if ch.isalpha():
        cipher += enc_map[ch.upper()]
    else:
        cipher += ch
print("\nEncrypted message:", cipher)


plain = ""
for ch in cipher:
    if ch.isalpha():
        plain += dec_map[ch]
    else:
        plain += ch
print("Decrypted message:", plain)
