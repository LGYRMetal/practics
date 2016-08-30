; practics 1.16
(define (my-expt b n)
  (my-expt-iter b n 1))

(define (my-expt-iter b n a)
  (cond ((= n 0) a)
        ((even? n) (my-expt-iter (square b) (/ n 2) (square (* a b))))
        (else (* b (my-expt-iter b (- n 1) 1)))))

(define(square n)
  (* n n))
