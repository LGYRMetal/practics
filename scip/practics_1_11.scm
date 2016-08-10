; recursive version
(define (f n)
  (if (< n 3)
    n
    (+ (* 1 (f (- n 1)))
       (* 2 (f (- n 2)))
       (* 3 (f (- n 3))))))

; iteration version
(define (f-i n)
  (define (f-iteration a b c n)
    (if (< n 3)
      (if (< n 2)
        n
        c)
      (f-iteration b c (+ (* 3 a) (* 2 b) c) (- n 1))))

  (f-iteration 0 1 2 n))

;  (if (< n 3)
;    n
;    (f-iteration 0 1 2 n)))
