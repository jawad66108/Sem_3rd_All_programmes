# 1. GCD function
def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a


# 2. Modular Inverse
def modInverse(e, phi):
    for d in range(2, phi):
        if (e * d) % phi == 1:
            return d
    return -1


# 3. RSA Key Generation
def generateKeys():
    p = 61
    q = 53

    n = p * q
    phi = (p - 1) * (q - 1)

    for e in range(2, phi):
        if gcd(e, phi) == 1:
            break

    d = modInverse(e, phi)
    return e, d, n


# 4. Encryption
def encrypt(m, e, n):
    return pow(m, e, n)


# 5. Decryption
def decrypt(c, d, n):
    return pow(c, d, n)


# 6. Key Generation
e, d, n = generateKeys()

print(f"Public Key (e, n): ({e}, {n})")
print(f"Private Key (d, n): ({d}, {n})")


# 7. Text Message
text = "jawad"
print("Original Text:", text)

# 8. Convert text to ASCII
ascii_values = [ord(char) for char in text]
print("ASCII Values:", ascii_values)

# 9. Encrypt ASCII values
encrypted_text = [encrypt(val, e, n) for val in ascii_values]
print("Encrypted Text:", encrypted_text)

# 10. Decrypt ASCII values
decrypted_ascii = [decrypt(val, d, n) for val in encrypted_text]

# 11. Convert ASCII back to text
decrypted_text = ''.join(chr(val) for val in decrypted_ascii)
print("Decrypted Text:", decrypted_text)


# # 1. Diffie-Hellman Key Exchange

# # 1.1 Agree on public values
# p = 101        # Prime number
# g = 108       # Generator

# # 1.2 Choose private keys
# xa = 15       # Alice's private key
# xb = 22      # Bob's private key

# # 1.3 Compute public keys
# ya = pow(g, xa, p)   # Alice's public key
# yb = pow(g, xb, p)   # Bob's public key

# print(f"Alice's public key: {ya}")
# print(f"Bob's public key: {yb}")

# # 1.4 Compute shared secret keys
# k_alice = pow(yb, xa, p)   # Alice computes shared key
# k_bob = pow(ya, xb, p)     # Bob computes shared key

# print(f"Alice's calculated shared secret: {k_alice}")
# print(f"Bob's calculated shared secret: {k_bob}")
