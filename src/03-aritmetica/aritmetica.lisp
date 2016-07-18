(defvar *a*)
(defvar *b*)

(format t "Introduzca un valor para a: ")
(finish-output)
(setq *a* (read))

(format t "Introduzca un valor para b: ")
(finish-output)
(setq *b* (read))

(defvar *suma* (+ *a*  *b*))
(defvar *producto* (* *a* *b*))
(defvar *cocienteAB* (/ *a* *b*))
(defvar *cocienteBA* (/ *b* *a*))

(format t "a + b = ~D~%" *suma*)
(format t "a * b = ~D~%" *producto*)
(format t "a / b = ~D~%" *cocienteAB*)
(format t "b / a = ~D~%" *cocienteBA*)
