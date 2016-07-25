(defvar *numero*)
(defvar *exponente*)
(defvar *resultado* 1)
(defvar *contador* 0)

(princ "Introduzca un numero: ")
(finish-output)
(setq *numero* (read))

(princ "Introduzca un exponente: ")
(finish-output)
(setq *exponente* (read))

(loop while (< *contador* *exponente*) do
      (incf *contador*)
      (setf *resultado* (* *resultado* *numero*)))

(format t "~D~%" *resultado*)
