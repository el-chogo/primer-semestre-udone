(defvar *nombre*)
(format t "Escriba un nombre: ")
(finish-output)
(setq *nombre* (read-line))
(if (string= *nombre* "Napoleon") (format t "Su apellido es Bonaparte!~%")
    (format t "No se ha podido determinar su apellido~%"))
