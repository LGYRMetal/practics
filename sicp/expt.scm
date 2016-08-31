; practics 1.16

;;;;;; 综合下面两个算法，得出下面最佳算法 ;;;;;
(define (my-expt b n)
  (my-expt-iter b n 1))

(define (my-expt-iter b n a)
  (cond ((= n 0) a)
        ((even? n) (my-expt (square b) (/ n 2)))
        (else (* b (my-expt b (- n 1))))))

; version 1
(define (my-expt-1 b n)
  (my-expt-iter-1 b n 1))

(define (my-expt-iter-1 b n a)
  (cond ((= n 0) a)
        ;((even? n) (my-expt-iter (square b) (/ n 2) (square (* a b))))
        ; (square (* a b))这部分纯属多余，没有用，因为在这步a的值是多少都
        ; 不会影响结果
        ((even? n) (my-expt-iter-1 (square b) (/ n 2) 1))
        (else (* b (my-expt-iter-1 b (- n 1) 1)))))

(define(square n)
  (* n n))

;;;;;; another version ;;;;;;
; version 2
(define (my-expt-iter-2 b n a)
  (cond ((= n 0) a)
        ((even? n) (my-expt-iter-2 (square b) (/ n 2) (square (* a b))))
        (else (* b (my-expt-2 b (- n 1))))))

(define (my-expt-2 b n)
  (my-expt-iter-2 b n 1))

