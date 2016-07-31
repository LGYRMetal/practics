;; 换零钱
(define (count-change amount)
  (cc amount 5))

(define (cc amount kinds-of-coins)
  (cond ((= amount 0) 1)
        ((or (< amount 0) (= kinds-of-coins 0)) 0)
        (else (+ (cc amount
                     (- kinds-of-coins 1))
                 (cc (- amount
                        (first-denomination kinds-of-coins))
                     kinds-of-coins)))))

(define (first-denomination kinds-of-coins)
  (cond ((= kinds-of-coins 1) 1)
        ((= kinds-of-coins 2) 5)
        ((= kinds-of-coins 3) 10)
        ((= kinds-of-coins 4) 25)
        ((= kinds-of-coins 5) 50)))

;; 打印出币值从0到n(n是大于0的整数)的换零钱方式数的序列
(define (vec-cc amount)
  (do ((vec (make-vector (+ amount 1)))
       (i 0 (+ i 1)))
      ((> i amount) vec)
      (vector-set! vec i (count-change i))))
