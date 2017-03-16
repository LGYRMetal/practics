MERGE(A, p, q, r)
    n1 = q - p + 1
    n2 = r - q

    let L[1..n1] and R[1..n2] be new arrays

    for i = 1 to n1
        L[i] = A[p + i - 1]

    for j = 1 to n2
        R[i] = A[q + j]

    i = 1
    j = 1
    k = 1

    while i <= n1 && j <= n2
        if L[i] <= R[j]
            A[k] = L[i]
            i = i + 1
        else
            A[k] = R[j]
            j = j + 1

        k = k + 1

    while i <= n1
        A[k] = L[i]
        k = k + 1
        i = i + 1

    while j <= n2
        A[k] = R[j]
        k = k + 1
        j = j + 1
