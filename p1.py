# # C
# def encrypt(text,key):
#     result =""

#     for j in  text:
#         if j.isupper():
#             result += chr((ord(j) - 65 + key) % 26 +65)
#         else:
#             result +=j
#     return result

# def decrypt(result,key):
#     return encrypt(result,-key)

# print("Encrypted: ", encrypt("HELLO",3))
# print("Decryption: ",decrypt("KHOOR",3))
# M
# import string ,random
# alpha = list(string.ascii_uppercase)

# key = alpha.copy()
# random.shuffle(key)

# encrypt = {}
# decrypt = {}
# for j in range(len(alpha)):
#     encrypt [alpha[j]] =key[j]
#     decrypt [key[j]] =alpha[j]

# message="MAHNOOR"
# cipher ="" 
# for j in message:
#     if j.isalpha():
#         cipher += encrypt[j]
#     else:
#         cipher += j

# plain = ""
# for j in message:
#     if j.isalpha():
#         plain += decrypt[j]
#     else:
#         plain += j

# print("Plain : ",message)
# print("Encrypted : ",cipher)
# v
# def encryption(text,key):
#     cipher =""
#     key = key.upper()
#     for i,ch in enumerate(text.upper()):
#         if ch.isalpha():
#             shift = ord(key[i%len(key)]) - 65 
#             cipher += chr((ord(ch)-65+shift)%26+65)
#         else:
#             cipher += ch
#     return cipher

# def decryption(text,key):
#     decrypt =""
#     key =key.upper()
#     for i,ch in enumerate(text.upper()):
#         if ch.isalpha():
#             shift = ord(key[i%len(key)]) - 65 
#             decrypt += chr((ord(ch)-65-shift)%26+65)
#         else:
#             decrypt += ch
#     return decrypt
# print("Encrypted: ", encryption("MAHNOOR", "KEY"))
#R
# def encryptRailFence(text, key):
#     # Create the matrix filled with '\n'
#     rail = [['\n' for i in range(len(text))]
#             for j in range(key)]

#     dir_down = False
#     row, col = 0, 0

#     # Place characters in zig-zag
#     for i in range(len(text)):
#         if row == 0 or row == key - 1:
#             dir_down = not dir_down

#         rail[row][col] = text[i]
#         col += 1

#         if dir_down:
#             row = row + 1
#         else:
#             row = row - 1


#     # Construct cipher from the matrix
#     result = []
#     for i in range(key):
#         for j in range(len(text)):
#             if rail[i][j] != '\n':
#                 result.append(rail[i][j])
#     return "".join(result)


# def decryptRailFence(cipher, key):
#     # Create the matrix filled with '\n'
#     rail = [['\n' for i in range(len(cipher))]
#             for j in range(key)]

#     # Mark the zig-zag path with '*'
#     dir_down = None
#     row, col = 0, 0
#     for i in range(len(cipher)):
#         if row == 0:
#             dir_down = True
#         if row == key - 1:
#             dir_down = False

#         rail[row][col] = '*'
#         col += 1

#         if dir_down:
#             row =row + 1 
#         else:
#             row =row - 1

#     # Fill the matrix with cipher text
#     index = 0
#     for i in range(key):
#         for j in range(len(cipher)):
#             if rail[i][j] == '*' and index < len(cipher):
#                 rail[i][j] = cipher[index]
#                 index += 1

#     # Read the matrix in zig-zag manner
#     result = []
#     row, col = 0, 0
#     for i in range(len(cipher)):
#         if row == 0:
#             dir_down = True
#         if row == key - 1:
#             dir_down = False

#         if rail[row][col] != '\n':
#             result.append(rail[row][col])
#         col += 1

#         if dir_down:
#             row = row + 1 
#         else:
#             row = row - 1

#     return "".join(result)


# if __name__ == "__main__":
#     print("Encryption:")
#     enc = encryptRailFence("attack at once", 2)
#     print(enc)

#     print("\nDecryption:")
#     dec = decryptRailFence(enc, 2)
#     print(dec)
# def playfair_prepare_key(keyword):
#     """
#     Prepares 5x5 Playfair matrix from a keyword.
#     Merges I/J into a single letter.
#     """
#     alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ"  # I/J merged
#     key = ""
#     # Add unique letters from keyword
#     for ch in keyword.upper():
#         if ch not in key and ch in alphabet:
#             key += ch
#     # Add remaining letters
#     for ch in alphabet:
#         if ch not in key:
#             key += ch

#     # Create 5x5 matrix
#     matrix = []
#     for i in range(0, 25, 5):
#       row = key[i:i+5]  # Take 5 letters slice for this row
#       matrix.append(row)
#     return matrix

# def find_position(matrix, letter):
#     """Finds row and column of a letter in the matrix"""
#     for i, row in enumerate(matrix):
#         if letter in row:
#             return i, row.index(letter)
#     return None

# def preprocess_text(text):
#     """
#     Prepares text for Playfair cipher:
#     - Uppercase, replace J with I
#     - Split into digraphs
#     - Insert X between repeated letters
#     - Append X if length is odd
#     """
#     text = text.upper().replace("J", "I")
#     digraphs = []
#     i = 0
#     while i < len(text):
#         a = text[i]
#         b = ''
#         if i+1 < len(text):
#             b = text[i+1]
#         if a == b or b == '':
#             b = 'X'
#             i += 1
#         else:
#             i += 2
#         digraphs.append(a+b)

#     return digraphs

# def playfair_encrypt(plaintext, matrix):
#     ciphertext = ""
#     digraphs = preprocess_text(plaintext)
#     for pair in digraphs:
#         r1, c1 = find_position(matrix, pair[0])
#         r2, c2 = find_position(matrix, pair[1])
#         # Rule 1: Same row
#         if r1 == r2:
#             ciphertext += matrix[r1][(c1+1)%5] + matrix[r2][(c2+1)%5]
#         # Rule 2: Same column
#         elif c1 == c2:
#             ciphertext += matrix[(r1+1)%5][c1] + matrix[(r2+1)%5][c2]
#         # Rule 3: Rectangle
#         else:
#             ciphertext += matrix[r1][c2] + matrix[r2][c1]
#     return ciphertext

# def playfair_decrypt(ciphertext, matrix):
#     plaintext = ""
#     digraphs = []
#     for i in range(0, len(ciphertext), 2):
#       pair = ciphertext[i:i+2]
#       digraphs.append(pair)
      
#     for pair in digraphs:
#         r1, c1 = find_position(matrix, pair[0])
#         r2, c2 = find_position(matrix, pair[1])
#         # Rule 1: Same row
#         if r1 == r2:
#             plaintext += matrix[r1][(c1-1)%5] + matrix[r2][(c2-1)%5]
#         # Rule 2: Same column
#         elif c1 == c2:
#             plaintext += matrix[(r1-1)%5][c1] + matrix[(r2-1)%5][c2]
#         # Rule 3: Rectangle
#         else:
#             plaintext += matrix[r1][c2] + matrix[r2][c1]
#     return plaintext

# keyword = "SECURITY"
# matrix = playfair_prepare_key(keyword)
# print("Playfair Matrix:")
# for row in matrix:
#     print(row)

# plaintext = "jawadriding"
# ciphertext = playfair_encrypt(plaintext, matrix)
# decrypted = playfair_decrypt(ciphertext, matrix)

# print("\nPlaintext:", plaintext)
# print("Ciphertext:", ciphertext)
# print("Decrypted:", decrypted)