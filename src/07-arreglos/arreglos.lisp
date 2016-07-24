(defun mapear (f xs)
    (defun mapear-p (f xs ys)
        (let ((x (car xs))
              (rest (cdr xs)))
            (cond 
                (xs (mapear-p f rest (append ys (list (funcall f x)))))
                (t ys))))
    (mapear-p f xs '()))

(defun reducir (f xs inicial)
    (defun reducir-p (acc f xs )
        (let ((x (car xs))
              (rest (cdr xs)))
            (cond
                (xs (reducir-p (funcall f acc x) f rest))
                (t acc))))
    (reducir-p inicial f xs))

(defun voltear (xs)
    (let ((x (car xs))
          (rest (cdr xs)))
        (cond
            (x (append (list x) (voltear rest)))
            (t '()))))

(defun alguno?-2 (f xs)
    (let ((x (car xs))
          (rest (cdr xs)))
        (if x
            (cond
                ((funcall f x) t)
                (t (alguno?-2 f rest)))
            nil)))

(defun y-logico (a b)
    (and a b))

(defun o-logico (a b)
    (or a b))

(defun todos (f xs)
    (reducir #'y-logico (mapear f xs) t))

(defun alguno? (f xs)
    (reducir #'o-logico (mapear f xs) nil))

(defun tomar (n xs)
    (defun tomar-p (n xs ys)
        (let ((x (car xs))
              (rest (cdr xs)))
            (if x
                (cond
                    ((> n 0) (tomar-p (- n 1) rest (append ys (list x))))
                    (t ys))
                ys)))
    (tomar-p n xs '()))

;; Funcion de alto orden, regresa una funcion
(defun anadir-verdad (f)
    (defun anadir-verdad-p (xs a)
        (if (funcall f a) (append xs (list a)) xs)))

(defun tomar-cuando (f xs)
    (let ((x (car xs))
          (rest (cdr xs)))
        (if xs (let ((resultado (reducir (anadir-verdad f) rest (list x)))
                    (anadir-primero (funcall f x)))
                    (if anadir-primero resultado (cdr resultado)))
            xs)))

(defun igual-5 (a) (format t "~D~%" a) (= a 5))

(defun tomar-tantos-cuando (f n xs)
    (defun tomar-tantos-cuando-p (f n xs ys)
        (let ((x (car xs))
              (rest (cdr xs)))
            (if xs
                (cond
                    ((> n 0) 
                        (cond
                            ((funcall f x) (tomar-tantos-cuando-p f (- n 1) rest (append ys (list x))))
                            (t (tomar-tantos-cuando-p f (- n 1) rest ys))))
                    (t ys))
                ys)))
    (tomar-tantos-cuando-p f n xs '()))
