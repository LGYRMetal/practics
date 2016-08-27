; practics 1.16
(define (my-expt b n)
  (my-expt-iter b n 1))

(define (my-expt-iter b n product)
  (cond ((= n 1) product)
        ((even? n) (my-expt-iter product (/ n 2) (square b)))))

(define(square n)
  (* n n))
