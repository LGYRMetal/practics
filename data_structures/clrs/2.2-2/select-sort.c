select-sort(A)
    for i = 1 to (A.length-1)
        min = A[i]
        for j = i+1 to A.length
            if min > A[j]
                min = A[j]
                k = j
        tmp = A[i]
        A[i] = A[k]
        A[k] = tmp


最好: theta n 平方
最坏: theta n 平方
