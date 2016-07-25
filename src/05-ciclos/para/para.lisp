(defvar *numero*)
(defvar *contador*)
(format t "Introduzca un numero: ")
(finish-output)
(setq *numero* (read))

(loop for *contador* from 1 upto *numero* do
      (if (evenp *contador*) (format t "~D es par!~%" *contador*)
        (format t "~D es impar!~%" *contador*)))
