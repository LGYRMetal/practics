; practics 1.17
(define (mul a b)
  (if (= b 0)
    0
    (+ a (mul a (- b 1)))))

(define (fast-mul a b)
  (cond ((= b 0) 0)
        ((even? b) (double (fast-mul a (halve b))))
        (else (+ a (fast-mul a (- b 1))))))

(define (double n)
  (+ n n))

(define (halve n)
  (/ n 2))
