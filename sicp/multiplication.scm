; practics 1.17

; example
(define (mul a b)
  (if (= b 0)
    0
    (+ a (mul a (- b 1)))))

; recursion version
(define (fast-mul a b)
  (cond ((= b 0) 0)
        ((even? b) (double (fast-mul a (halve b))))
        (else (+ a (fast-mul a (- b 1))))))

; iteration version
(define (fast-mul-i a b)
  (fast-mul-iter a b 0))

(define (fast-mul-iter a b n)
  (cond ((= b 0) n)
        ((even? b) (fast-mul-iter (double a) (halve b) n))
        (else (fast-mul-iter a (- b 1) (+ n a)))))

(define (double n)
  (+ n n))

(define (halve n)
  (/ n 2))
