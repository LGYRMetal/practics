;; 函数名: sqrt
;; 使用sqrt-iter求一个数的平方根

(define (sqrt x)
    (sqrt-iter 1.0 x))

;; 函数名: sqrt-iter
;; 根据牛顿逐步逼近法，计算x的平方根

(define (sqrt-iter guess x)
    (if (good-enough? guess x)
        guess
        (sqrt-iter (improve guess x)
            x)))

;; 函数名: good-enough?
;(define (good-enough? guess x)
;    (< (abs (- (square guess) x)) 0.001))

;; new good-enough?
(define (good-enough? guess x)
    (< (/ (abs (- guess (improve guess x))) guess) 0.001))

;; 函数名: next-guess
;; 求下一次猜测值
;(define (next-guess guess x)
;    (/ (+ (/ x guess) guess) 2))
;; 这就是improve

;; 函数名: improve
(define (improve guess x)
    (average guess (/ x guess)))

;; 函数名: average
(define (average x y)
    (/ (+ x y) 2))
