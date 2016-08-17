; Pascal's Triangle
(define (pascal-triangle n)
  (if (< n 1)
    (format
      #t
      "~%Procedure pascal-triangle~%requires its argument ~
      to be of type integer greater then 0.")
      (do ((i 1 (+ i 1)))
        ((> i n))
        (display-n-white-space (- n i))
        (do ((j 1 (+ j 1)))
          ((> j i) (newline))
          (display (pt i j))
          (cond ((< (pt i j) 10) (display-n-white-space 3))
                ((< (pt i j) 100) (display-n-white-space 2))
                ((< (pt i j) 1000) (display-n-white-space 1))
                (else (display-n-white-space 1)))))))

(define (pt n count)
  (if (or (= n 1) (= n count) (= count 1))
    1
    (+ (pt (- n 1) (- count 1))
       (pt (- n 1) count))))

(define (display-n-white-space n)
  (do ((i 1 (+ i 1)))
    ((> i n))
    (display " ")))
