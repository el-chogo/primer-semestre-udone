(defvar *nombre*)
(format t "Introduzca su nombre: ")
(finish-output)
(setq *nombre* (read-line))
(format t "Hola ~a ~%" *nombre*)
