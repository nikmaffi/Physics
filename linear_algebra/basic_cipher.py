import numpy as np

N = 32

def key_gen(n):
    #Male male!
    #Brutto brutto!
    K = np.array([0], dtype=int)

    while np.linalg.matrix_rank(K) != n:
        K = np.random.randint(0x0, 0x10FFFF, size=(n, n))

    return K

def translate_i(text, n):
    M = []

    for r in range(n):
        M.append([])

        for c in range(n):
            M[r].append(ord(text[r * n + c]))

    return np.array(M, dtype=int)

def translate_o(M):
    text = ""

    for r in range(M.shape[0]):
        for c in range(M.shape[1]):
            text += chr(int(M[r][c]))

    return text

def encrypt(M, K):
    return np.matmul(M, K)

def decrypt(M, K):
    K_i = np.linalg.inv(K)

    return np.round(np.matmul(M, K_i))

def main():
    text = input("Message: ").ljust(N*N)

    M_0 = translate_i(text, N)

    K = key_gen(N)

    M_1 = encrypt(M_0, K)
    M_2 = decrypt(M_1, K)

    text = translate_o(M_2).strip()
    print(text)

    print(f"\nKey:\n{K}")

if __name__ == "__main__":
    main()
