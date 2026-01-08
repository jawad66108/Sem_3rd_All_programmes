from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
import base64

# Generate random key and IV (16 bytes each for AES-128)
key = get_random_bytes(16)
iv = get_random_bytes(16)

plain_text = "My name is jawad"

# Padding function to make text length a multiple of 16
def pad(text):
    while len(text) % 16 != 0:
        text += ' '
    return text

# Encrypt
cipher = AES.new(key, AES.MODE_CBC, iv)
padded_text = pad(plain_text).encode('utf-8')
cipher_text = cipher.encrypt(padded_text)

# Encode ciphertext in Base64 for readability
cipher_text_base64 = base64.b64encode(cipher_text).decode('utf-8')
print("Encrypted Text:", cipher_text_base64)

# Decrypt
cipher_decrypt = AES.new(key, AES.MODE_CBC, iv)
decrypted_text = cipher_decrypt.decrypt(cipher_text).decode('utf-8').strip()
print("Decrypted Text:", decrypted_text)
