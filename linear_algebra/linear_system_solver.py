import copy

def laplace(M, n, row):
    if n == 1:
        return M[0][0]

    det_M = 0
    for col in range(n):
        m = []
        m_row = 0

        for r in range(n):
            if r == row:
                continue

            for c in range(n):
                if c == col:
                    continue

                m.append([])
                m[m_row].append(M[r][c])

            m_row += 1

        det_M += (-1)**(row + col + 2) * M[row][col] * laplace(m, n - 1, row)

    return det_M

def transpose(M, n):
    M_t = copy.deepcopy(M)

    for r in range(n):
        for c in range(n):
            M_t[c][r] = M[r][c]

    return M_t

def cofactors(M, n):
    M_cf = copy.deepcopy(M)

    for r in range(n):
        for c in range(n):
            m = []
            m_row = 0

            for i in range(n):
                if i == r:
                    continue

                for j in range(n):
                    if j == c:
                        continue

                    m.append([])
                    m[m_row].append(M[i][j])

                m_row += 1

            M_cf[r][c] = (-1)**(r + c + 2) * laplace(m, n - 1, 0)

    return M_cf

def scalar_product(M, n, s):
    M_sp = copy.deepcopy(M)

    for r in range(n):
        for c in range(n):
            M_sp[r][c] *= s

    return M_sp

def inverse(M, n):
    M_i = copy.deepcopy(M)

    det_M = laplace(M, n, 0)

    M_i = cofactors(M_i, n)
    M_i = transpose(M_i, n)
    M_i = scalar_product(M_i, n, 1 / det_M)

    return M_i

def vector_product(M, v, n):
    M_vp = copy.deepcopy(M)
    res = []
    
    for r in range(n):
        res.append(0)
        for c in range(n):
            res[r] += M_vp[r][c] * v[c]

    return res

def main():
    M = [
        [1, 1, 0, 1],
        [12, 6, -6, -2],
        [3, -3, 6, -3],
        [-6, 12, -6, 6]
    ]
    b = [0, 1, 1, 11]

    M_i = inverse(M, 4)
    M_vp = vector_product(M_i, b, 4)
    
    print(M_vp)

if __name__ == "__main__":
    main()