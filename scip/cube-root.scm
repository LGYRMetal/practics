;; 根据牛顿法求立方根

;; 函数名: cube-root
;; 求给定数值的立方根
(define (cube-root x)
    (cube-root-iter 1.0 x))

;; 函数名: cube-root-iter
;; 根据给定数和他的立方根的猜测值求立方根
(define (cube-root-iter guess x)
    (if (good-enough? guess x)
        guess
        (cube-root-iter (improve guess x) x)))

;; 函数名: good-enough?
;; 判断猜测值是否足够好
(define (good-enough? guess x)
    (< (/ (abs (- guess (improve guess x))) guess) 0.001))

;; 函数名: improve
;; 根据牛顿法求出一个更接近立方根的近似值
(define (improve guess x)
    (/ 
        (+ 
            (/ x (square guess)) 
            (* 2 guess))
        3))
