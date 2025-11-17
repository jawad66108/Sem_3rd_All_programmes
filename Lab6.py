def playfair_prepare_key(keyword):
    """
    Prepares 5x5 Playfair matrix from a keyword.
    Merges I/J into a single letter.
    """
    alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ"  # I/J merged
    key = ""
    # Add unique letters from keyword
    for ch in keyword.upper():
        if ch not in key and ch in alphabet:
            key += ch
    # Add remaining letters
    for ch in alphabet:
        if ch not in key:
            key += ch

    # Create 5x5 matrix
    matrix = []
    for i in range(0, 25, 5):
      row = key[i:i+5]  # Take 5 letters slice for this row
      matrix.append(row)
    return matrix

def find_position(matrix, letter):
    """Finds row and column of a letter in the matrix"""
    for i, row in enumerate(matrix):
        if letter in row:
            return i, row.index(letter)
    return None

def preprocess_text(text):
    """
    Prepares text for Playfair cipher:
    - Uppercase, replace J with I
    - Split into digraphs
    - Insert X between repeated letters
    - Append X if length is odd
    """
    text = text.upper().replace("J", "I")
    digraphs = []
    i = 0
    while i < len(text):
        a = text[i]
        b = ''
        if i+1 < len(text):
            b = text[i+1]
        if a == b or b == '':
            b = 'X'
            i += 1
        else:
            i += 2
        digraphs.append(a+b)

    return digraphs

def playfair_encrypt(plaintext, matrix):
    ciphertext = ""
    digraphs = preprocess_text(plaintext)
    for pair in digraphs:
        r1, c1 = find_position(matrix, pair[0])
        r2, c2 = find_position(matrix, pair[1])
        # Rule 1: Same row
        if r1 == r2:
            ciphertext += matrix[r1][(c1+1)%5] + matrix[r2][(c2+1)%5]
        # Rule 2: Same column
        elif c1 == c2:
            ciphertext += matrix[(r1+1)%5][c1] + matrix[(r2+1)%5][c2]
        # Rule 3: Rectangle
        else:
            ciphertext += matrix[r1][c2] + matrix[r2][c1]
    return ciphertext

def playfair_decrypt(ciphertext, matrix):
    plaintext = ""
    digraphs = []
    for i in range(0, len(ciphertext), 2):
      pair = ciphertext[i:i+2]
      digraphs.append(pair)
      
    for pair in digraphs:
        r1, c1 = find_position(matrix, pair[0])
        r2, c2 = find_position(matrix, pair[1])
        # Rule 1: Same row
        if r1 == r2:
            plaintext += matrix[r1][(c1-1)%5] + matrix[r2][(c2-1)%5]
        # Rule 2: Same column
        elif c1 == c2:
            plaintext += matrix[(r1-1)%5][c1] + matrix[(r2-1)%5][c2]
        # Rule 3: Rectangle
        else:
            plaintext += matrix[r1][c2] + matrix[r2][c1]
    return plaintext

# ------------------- Example Usage -------------------


keyword = "SECURITY"
matrix = playfair_prepare_key(keyword)
print("Playfair Matrix:")
for row in matrix:
    print(row)

plaintext = "jawadriding"
ciphertext = playfair_encrypt(plaintext, matrix)
decrypted = playfair_decrypt(ciphertext, matrix)

print("\nPlaintext:", plaintext)
print("Ciphertext:", ciphertext)
print("Decrypted:", decrypted)

