(defun entremezclar (v xs)
    (defun entremezclarp (acc v xs)
        (let* ((x (car xs))
              (resto (cdr xs)))
            (cond
                (x (entremezclarp 
                    (if resto (append acc (list x v)) (append acc (list x))) v resto))
                (t acc))))
    (entremezclarp '() v xs))

(defun achatar (structure)
  (cond ((null structure) nil)
        ((atom structure) (list structure))
        (t (mapcan #'achatar structure))))

(defun tomar-mientras-con-indice (f xs)
    (defun tomar-mientras-con-indicep (acc f xs i)
        (let ((x (car xs))
              (resto (cdr xs)))
            (cond
                ((null xs) (if (null acc) (cons acc -1) (cons acc i)))
                ((funcall f x) (tomar-mientras-con-indicep (append acc (list x)) f resto (+ 1 i)))
                (t (cons acc i)))))
    (tomar-mientras-con-indicep '() f xs 0))

(defun es-letra? (x)
    (cond
        ((and (string>= x "a") (string<=  x "z")) t)
        ((and (string>= x "A") (string<=  x "Z")) t)
        (t nil)))

(defun es-espacio? (x)
    (if (string= x " ") t nil))

(defun encontrar-primer-indice (f xs)
    (defun encontrar-primer-indicep (i f xs)
        (cond
            ((null xs) -1)
            ((funcall f (car xs)) i)
            (t (encontrar-primer-indicep (+ 1 i) f (cdr xs)))))
    (encontrar-primer-indicep 0 f xs))

(defun tomar-palabra (xs)
    (let ((indice (encontrar-primer-indice #'es-letra? xs)))
        (cond
            ((>= indice 0) 
                (let* ((par (tomar-mientras-con-indice #'es-letra? (subseq xs indice)))
                       (last-indice (cdr par))
                       (palabra (car par)))
                    (cons palabra (+ indice last-indice))))
            (t (cons "" -1)))))

(defun tomar-palabras (xs)
    (defun tomar-palabrasp (acc xs)
        (let* ((par (tomar-palabra xs))
               (palabra (car par))
               (indice (cdr par)))
            (cond
                ((>= indice 0) (tomar-palabrasp (append acc (list palabra)) (subseq xs indice)))
                (t acc))))
    (tomar-palabrasp '() xs))

(defun capitalizar (xs)
    (let* ((x (car xs))
           (resto (cdr xs)))
        (append (coerce (string-upcase x) 'list) resto)))

(defun juntar (xs sep)
    (defun juntarp (acc xs sep)
        (let* ((x (car xs))
                (resto (cdr xs)))
            (cond
                (x (juntarp (append acc x) resto sep))
                (t acc))))
    (juntarp '() xs sep))

(defun main ()
    (princ "Ingrese una oracion: ")
    (finish-output)
    (format t "Cadena capitalizada: ~S~%" (coerce (achatar 
        (entremezclar #\Space 
            (map 'list #'capitalizar (tomar-palabras (coerce (read-line) 'list))))) 'String)))

(main)
