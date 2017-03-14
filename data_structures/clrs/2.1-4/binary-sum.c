binary-sum(A, B, n)
    carry = 0
    for i = n downto 1
        if A[i] == 1 and B[i] == 1 and carry == 1
            carry = 1
        else if A[i] == 1 and B[i] == 1
            carry = 1
        else if (A[i] == 1 or B[i] == 1) and carry == 1
            carry = 1
        else
            carry = 0

        C[i+1] = A[i] ^ B[i] ^ carry
    if carry == 1
        C[i] = 1
    else
        C[i] = 0
