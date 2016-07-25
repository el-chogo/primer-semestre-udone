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
     (x (append (voltear rest) (list x)))
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

(defun generar-agregar-tantos (n)
  (let ((contador 0))
    (defun agregar-tantos (xs a)
      (cond ((< contador n)
             (setq contador (+ contador 1))
             (append xs (list a)))
            (t xs)))))

(defun tomar (n xs)
  (reducir (generar-agregar-tantos n) xs '()))

;; Funcion de alto orden, regresa una funcion
(defun anadir-verdad (f)
  (defun anadir-verdad-p (xs a)
    (if (funcall f a) (append xs (list a)) xs)))

(defun tomar-cuando (f xs)
  (reducir (anadir-verdad f) xs '()))

(defun igual-5 (a) (= 5 a))

(defun tomar-tantos-cuando (n f xs)
  (tomar n (tomar-cuando f xs)))

(defun generar-divisor? (n)
  (lambda (a)
    (if (= 0 (mod a n)) t nil)))

(defun rango (max &key (min 0) (paso 1))
  (loop for n from min below max by paso
        collect n))

(defun aplicar-a (a)
  (lambda (f)
    (funcall f a)))

(defun y-funciones (&rest fs)
  (lambda (x)
    (reducir #'y-logico (mapear (aplicar-a x) fs) t)))

(defun cadena-a-lista (cadena)
  (coerce cadena 'list))

(defun lista-a-cadena (xs)
  (coerce xs 'string))

(defun componer (f g)
  (lambda (x)
    (funcall g (funcall f x))))

(defun palindromo (xs)
  (string-equal (lista-a-cadena xs) (lista-a-cadena (voltear xs))))

(defun main ()
  (format t "Numeros divisibles entre 13 y el 7 del 1 al 1000:~%")
  (let ((divisor-13? (generar-divisor? 13))
	(divisor-7? (generar-divisor? 7)))
    (format t "~S~%"
	    (tomar-cuando (y-funciones divisor-13? divisor-7?)
			  (rango 1000))))
  (format t "Introduzca una palabra: ")
  (finish-output)
  (let* ((palabra (string-downcase (read-line)))
	 (xs (cadena-a-lista palabra)))
    (if (palindromo xs)
	(format t "Su palabra es un palindromo~%")
      (format t "Su palabra no es un palindromo~%")))

  (main)
